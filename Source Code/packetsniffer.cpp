#include "packetsniffer.h"
#include <QDebug>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <QElapsedTimer>
#pragma comment(lib, "IPHLPAPI.lib")

PacketSniffer::PacketSniffer(QObject *parent) : QThread(parent), handle(nullptr), capturing(false) {}

QList<NetworkInterface> PacketSniffer::getAllDevices() {
    QList<NetworkInterface> deviceList;

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *alldevs;

    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        qDebug() << "Error finding devices:" << errbuf;
        return deviceList;
    }

    for (pcap_if_t *d = alldevs; d; d = d->next) {
        NetworkInterface iface;
        iface.name = QString(d->name);

        if (d->description != nullptr && strlen(d->description) > 0) {
            iface.friendlyName = QString(d->description);
        } else {
            QString simpleName = iface.name;
            simpleName = simpleName.replace("\\Device\\NPF_", "");
            if (simpleName.contains("{")) {
                simpleName = "Network Adapter " + simpleName.left(8);
            }
            iface.friendlyName = simpleName;
        }

        iface.ipAddress = "";
        for (pcap_addr_t *a = d->addresses; a; a = a->next) {
            if (a->addr && a->addr->sa_family == AF_INET) {
                sockaddr_in *sin = (struct sockaddr_in *)a->addr;
                iface.ipAddress = QString::fromStdString(inet_ntoa(sin->sin_addr));
                break;
            }
        }

        iface.macAddress = "";
        IP_ADAPTER_INFO AdapterInfo[16];
        DWORD dwBufLen = sizeof(AdapterInfo);

        if (GetAdaptersInfo(AdapterInfo, &dwBufLen) == NO_ERROR) {
            PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;
            while (pAdapterInfo) {
                if (iface.ipAddress == QString(pAdapterInfo->IpAddressList.IpAddress.String)) {
                    iface.macAddress = QString("%1:%2:%3:%4:%5:%6")
                    .arg(pAdapterInfo->Address[0], 2, 16, QChar('0'))
                        .arg(pAdapterInfo->Address[1], 2, 16, QChar('0'))
                        .arg(pAdapterInfo->Address[2], 2, 16, QChar('0'))
                        .arg(pAdapterInfo->Address[3], 2, 16, QChar('0'))
                        .arg(pAdapterInfo->Address[4], 2, 16, QChar('0'))
                        .arg(pAdapterInfo->Address[5], 2, 16, QChar('0'))
                        .toUpper();
                    break;
                }
                pAdapterInfo = pAdapterInfo->Next;
            }
        }

        deviceList.append(iface);
    }

    pcap_freealldevs(alldevs);
    return deviceList;
}

QString PacketSniffer::findBestDevice() {
    QList<NetworkInterface> devices = getAllDevices();

    if (devices.isEmpty()) {
        qDebug() << "No network devices found!";
        return QString();
    }

    // Device evaluation result structure
    struct DeviceScore {
        QString name;
        QString friendlyName;
        int packetCount;
        bool hasIP;
        bool isEthernet;
        double score;
    };
    QList<DeviceScore> deviceScores;

    qDebug() << "Testing" << devices.size() << "devices for traffic...";
    char errbuf[PCAP_ERRBUF_SIZE];

    // Prepare device scores list
    for (const NetworkInterface &iface : devices) {
        DeviceScore ds;
        ds.name = iface.name;
        ds.friendlyName = iface.friendlyName;
        ds.packetCount = 0;
        ds.hasIP = !iface.ipAddress.isEmpty();

        QString lowerName = iface.name.toLower();
        ds.isEthernet = !iface.macAddress.isEmpty() &&
                        !lowerName.contains("loopback") &&
                        !lowerName.contains("virtual") &&
                        !lowerName.contains("vpn");

        ds.score = 0;
        deviceScores.append(ds);
    }

    for (int i = 0; i < deviceScores.size(); i++) {
        const QString &deviceName = deviceScores[i].name;
        qDebug() << "Testing device:" << deviceName << "/" << deviceScores[i].friendlyName;

        pcap_t *test_handle = pcap_open_live(deviceName.toStdString().c_str(), BUFSIZ, 1, 100, errbuf);
        if (!test_handle) {
            qDebug() << "  Couldn't open device for testing:" << errbuf;
            continue;
        }

        if (pcap_setnonblock(test_handle, 1, errbuf) == -1) {
            qDebug() << "  Failed to set non-blocking mode:" << errbuf;
            pcap_close(test_handle);
            continue;
        }

        int packetCount = 0;

        auto packetCounter = [](u_char *user, const struct pcap_pkthdr *, const u_char *) {
            int *count = reinterpret_cast<int*>(user);
            (*count)++;
        };

        // Sample for 2 seconds
        QElapsedTimer timer;
        timer.start();
        int sampleTimeMs = 2000;

        qDebug() << "  Sampling traffic for" << sampleTimeMs << "ms...";

        while (timer.elapsed() < sampleTimeMs) {
            int processed = pcap_dispatch(test_handle, 100, packetCounter, reinterpret_cast<u_char*>(&packetCount));

            if (processed < 0) {
                qDebug() << "  Error during packet capture:" << pcap_geterr(test_handle);
                break;
            }

            QThread::msleep(10);
        }

        pcap_close(test_handle);

        deviceScores[i].packetCount = packetCount;
        qDebug() << "  Device:" << deviceName << "packets:" << packetCount;
    }
    for (auto &device : deviceScores) {
        device.score = device.packetCount;
        if (device.hasIP) {
            device.score += 10;
        }
        if (device.isEthernet) {
            device.score += 20;
        }
        QString lowerName = device.name.toLower();
        if (lowerName.contains("loopback") ||
            lowerName.contains("virtual") ||
            lowerName.contains("vpn") ||
            lowerName.contains("vmware") ||
            lowerName.contains("npcap loopback")) {
            device.score -= 50;
        }

        qDebug() << "Device score:" << device.name << "=" << device.score;
    }
    std::sort(deviceScores.begin(), deviceScores.end(),
              [](const DeviceScore &a, const DeviceScore &b) {
                  return a.score > b.score;
              });
    if (!deviceScores.isEmpty() && deviceScores.first().score > 0) {
        QString bestDevice = deviceScores.first().name;
        qDebug() << "Best device selected:" << bestDevice
                 << "(" << deviceScores.first().friendlyName << ")"
                 << "with score:" << deviceScores.first().score;
        return bestDevice;
    }
    for (const auto &device : deviceScores) {
        if (device.hasIP) {
            qDebug() << "No good device found, falling back to device with IP:" << device.name;
            return device.name;
        }
    }

    if (!deviceScores.isEmpty()) {
        qDebug() << "No suitable device found, falling back to first device:" << deviceScores.first().name;
        return deviceScores.first().name;
    }

    return QString();
}

void PacketSniffer::run() {
    char errbuf[PCAP_ERRBUF_SIZE];

    if (selectedDevice.isEmpty()) {
        qDebug() << "No device selected, finding best device automatically...";
        selectedDevice = findBestDevice();
        if (selectedDevice.isEmpty()) {
            qDebug() << "Failed to find any suitable device!";
            emit captureError("No suitable network interface found");
            return;
        }
    }

    qDebug() << "Selected device for capture:" << selectedDevice;
    emit captureStarted(selectedDevice);

    handle = pcap_open_live(selectedDevice.toStdString().c_str(), BUFSIZ, 1, 1000, errbuf);
    if (!handle) {
        qDebug() << "Couldn't open device for capturing:" << errbuf;
        emit captureError(QString("Failed to open device: %1").arg(errbuf));
        return;
    }

    qDebug() << "Successfully opened device for packet capture. Starting capture loop...";
    capturing = true;
    pcap_loop(handle, 0, packetHandler, reinterpret_cast<u_char*>(this));

    qDebug() << "Capture loop ended. Cleaning up...";
    pcap_close(handle);
}

void PacketSniffer::stopCapture() {
    qDebug() << "Stop capture requested";
    capturing = false;
    if (handle) {
        pcap_breakloop(handle);
    }
}

void PacketSniffer::setDeviceName(const QString &deviceName) {
    qDebug() << "Device name manually set to:" << deviceName;
    selectedDevice = deviceName;
}

void PacketSniffer::packetHandler(u_char *userData, const struct pcap_pkthdr *pkthdr, const u_char *packet) {
    PacketSniffer *sniffer = reinterpret_cast<PacketSniffer*>(userData);

    CapturedPacket capturedPacket;
    capturedPacket.header = *pkthdr;
    capturedPacket.data.assign(packet, packet + pkthdr->len);
    sniffer->capturedPackets.append(capturedPacket);
    struct ether_header {
        u_char dest_mac[6];
        u_char src_mac[6];
        u_short ether_type;
    };

    struct ip_header {
        u_char header_length:4;
        u_char version:4;
        u_char tos;
        u_short total_length;
        u_short identification;
        u_short flags_offset;
        u_char ttl;
        u_char protocol;
        u_short checksum;
        struct in_addr src_addr;
        struct in_addr dest_addr;
    };

    struct ether_header *ethHeader = (struct ether_header *)packet;
    u_short eth_type = ntohs(ethHeader->ether_type);

    if (eth_type == 0x0800) { //IPv4
        struct ip_header *ipHeader = (struct ip_header *)(packet + sizeof(struct ether_header));

        QString srcMac = QString("%1:%2:%3:%4:%5:%6")
                             .arg(ethHeader->src_mac[0], 2, 16, QChar('0'))
                             .arg(ethHeader->src_mac[1], 2, 16, QChar('0'))
                             .arg(ethHeader->src_mac[2], 2, 16, QChar('0'))
                             .arg(ethHeader->src_mac[3], 2, 16, QChar('0'))
                             .arg(ethHeader->src_mac[4], 2, 16, QChar('0'))
                             .arg(ethHeader->src_mac[5], 2, 16, QChar('0'));

        QString destMac = QString("%1:%2:%3:%4:%5:%6")
                              .arg(ethHeader->dest_mac[0], 2, 16, QChar('0'))
                              .arg(ethHeader->dest_mac[1], 2, 16, QChar('0'))
                              .arg(ethHeader->dest_mac[2], 2, 16, QChar('0'))
                              .arg(ethHeader->dest_mac[3], 2, 16, QChar('0'))
                              .arg(ethHeader->dest_mac[4], 2, 16, QChar('0'))
                              .arg(ethHeader->dest_mac[5], 2, 16, QChar('0'));

        QString srcIP = QString::fromStdString(inet_ntoa(ipHeader->src_addr));
        QString destIP = QString::fromStdString(inet_ntoa(ipHeader->dest_addr));

        int protocol = ipHeader->protocol;
        QString protocolName;
        QString info;

        if (protocol == 6) { // TCP
            struct tcp_header {
                u_short src_port;
                u_short dest_port;
                u_int seq_num;
                u_int ack_num;
                u_char offset_reserved;
                u_char flags;
                u_short window;
                u_short checksum;
                u_short urgent_ptr;
            };

            struct tcp_header *tcpHeader = (struct tcp_header *)(packet + sizeof(struct ether_header) + (ipHeader->header_length * 4));
            int srcPort = ntohs(tcpHeader->src_port);
            int destPort = ntohs(tcpHeader->dest_port);

            bool isAck = (tcpHeader->flags & 0x10);
            bool isSyn = (tcpHeader->flags & 0x02);
            bool isRst = (tcpHeader->flags & 0x04);

            // TLS
            if ((destPort == 443 || srcPort == 443) && pkthdr->len > 54) {
                const u_char *tlsPayload = packet + sizeof(struct ether_header) + (ipHeader->header_length * 4) + (tcpHeader->offset_reserved >> 4) * 4;
                u_char tlsContentType = tlsPayload[0];

                if (tlsContentType == 0x16) {
                    info = "TLS Handshake";
                } else if (tlsContentType == 0x17) {
                    info = "TLS Application Data";
                } else if (tlsContentType == 0x15) {
                    info = "TLS Alert";
                } else {
                    info = QString("TCP %1 → %2 [%3]").arg(srcPort).arg(destPort).arg(isAck ? "ACK" : (isSyn ? "SYN" : (isRst ? "RST" : "Other")));
                }
                protocolName = "TLS";
            } else {
                protocolName = "TCP";
                info = QString("TCP %1 → %2 [%3]").arg(srcPort).arg(destPort).arg(isAck ? "ACK" : (isSyn ? "SYN" : (isRst ? "RST" : "Other")));
            }
        } else if (protocol == 17) { // UDP
            struct udp_header {
                u_short src_port;
                u_short dest_port;
                u_short length;
                u_short checksum;
            };

            struct udp_header *udpHeader = (struct udp_header *)(packet + sizeof(struct ether_header) + (ipHeader->header_length * 4));
            int srcPort = ntohs(udpHeader->src_port);
            int destPort = ntohs(udpHeader->dest_port);

            if (destPort == 53 || srcPort == 53) {
                protocolName = "DNS";
                info = "DNS Query or Response";
            } else if (destPort == 443 || srcPort == 443) {
                protocolName = "QUIC";
                info = "QUIC Encrypted Packet";
            } else {
                protocolName = "UDP";
                info = QString("UDP %1 → %2").arg(srcPort).arg(destPort);
            }
        } else {
            protocolName = "Other";
            info = "Unknown Protocol";
        }

        int length = pkthdr->len;
        QMetaObject::invokeMethod(sniffer, "packetCaptured", Qt::QueuedConnection,
                                  Q_ARG(QString, srcMac), Q_ARG(QString, destMac),
                                  Q_ARG(QString, srcIP), Q_ARG(QString, destIP),
                                  Q_ARG(QString, protocolName), Q_ARG(int, length),
                                  Q_ARG(QString, info));
    }
}

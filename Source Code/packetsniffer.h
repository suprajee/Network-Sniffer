// Updated packetsniffer.h
#ifndef PACKETSNIFFER_H
#define PACKETSNIFFER_H

#include <QObject>
#include <pcap.h>
#include <QThread>
#include <QList>
#include <QString>

struct NetworkInterface {
    QString name;
    QString friendlyName;  // Add this field
    QString ipAddress;
    QString macAddress;
};
struct CapturedPacket {
    struct pcap_pkthdr header;
    std::vector<u_char> data;
};

class PacketSniffer : public QThread {
    Q_OBJECT

public:
    explicit PacketSniffer(QObject *parent = nullptr);
    void run() override;
    void stopCapture();
    void setDeviceName(const QString &deviceName);
    bool isRunning() const { return capturing; }
    static QList<NetworkInterface> getAllDevices();
    const QVector<CapturedPacket>& getCapturedPackets() const { return capturedPackets; }
    QString findBestDevice();

signals:
    void packetCaptured(QString srcMac, QString destMac, QString srcIP, QString destIP, QString protocol, int length, QString info);
    void captureStarted(QString deviceName);
    void captureError(QString errorMessage);

private:
    static void packetHandler(u_char *userData, const struct pcap_pkthdr *pkthdr, const u_char *packet);
    pcap_t *handle;
    bool capturing;
    QString selectedDevice;
    QVector<CapturedPacket> capturedPackets;
};

#endif // PACKETSNIFFER_H

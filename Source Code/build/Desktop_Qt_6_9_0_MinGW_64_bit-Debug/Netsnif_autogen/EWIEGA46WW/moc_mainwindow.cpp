/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10MainWindowE = QtMocHelpers::stringData(
    "MainWindow",
    "startCapture",
    "",
    "stopCapture",
    "toggleCapture",
    "updatePacketTable",
    "srcMac",
    "destMac",
    "srcIP",
    "destIP",
    "protocol",
    "length",
    "info",
    "onProtocolFilterChanged",
    "onCaptureStarted",
    "deviceName",
    "onCaptureError",
    "errorMessage",
    "updateTrafficGraph",
    "showAlert",
    "message",
    "onBrowseButtonClicked",
    "updateDiskInformation",
    "path",
    "onSaveButtonClicked",
    "updateSaveButtonState",
    "onAddIpFilterClicked",
    "onRemoveIpFilterClicked",
    "onFixedIpFilterChanged",
    "onPacketSelected"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10MainWindowE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  116,    2, 0x0a,    1 /* Public */,
       3,    0,  117,    2, 0x0a,    2 /* Public */,
       4,    0,  118,    2, 0x0a,    3 /* Public */,
       5,    7,  119,    2, 0x0a,    4 /* Public */,
      13,    0,  134,    2, 0x0a,   12 /* Public */,
      14,    1,  135,    2, 0x0a,   13 /* Public */,
      16,    1,  138,    2, 0x0a,   15 /* Public */,
      18,    0,  141,    2, 0x08,   17 /* Private */,
      19,    1,  142,    2, 0x08,   18 /* Private */,
      21,    0,  145,    2, 0x08,   20 /* Private */,
      22,    1,  146,    2, 0x08,   21 /* Private */,
      24,    0,  149,    2, 0x08,   23 /* Private */,
      25,    0,  150,    2, 0x08,   24 /* Private */,
      26,    0,  151,    2, 0x08,   25 /* Private */,
      27,    0,  152,    2, 0x08,   26 /* Private */,
      28,    0,  153,    2, 0x08,   27 /* Private */,
      29,    0,  154,    2, 0x08,   28 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString,    6,    7,    8,    9,   10,   11,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ZN10MainWindowE.offsetsAndSizes,
    qt_meta_data_ZN10MainWindowE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN10MainWindowE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'startCapture'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopCapture'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'toggleCapture'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updatePacketTable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'onProtocolFilterChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCaptureStarted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'onCaptureError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'updateTrafficGraph'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showAlert'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onBrowseButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateDiskInformation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onSaveButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateSaveButtonState'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddIpFilterClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRemoveIpFilterClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onFixedIpFilterChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onPacketSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->startCapture(); break;
        case 1: _t->stopCapture(); break;
        case 2: _t->toggleCapture(); break;
        case 3: _t->updatePacketTable((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7]))); break;
        case 4: _t->onProtocolFilterChanged(); break;
        case 5: _t->onCaptureStarted((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->onCaptureError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->updateTrafficGraph(); break;
        case 8: _t->showAlert((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->onBrowseButtonClicked(); break;
        case 10: _t->updateDiskInformation((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->onSaveButtonClicked(); break;
        case 12: _t->updateSaveButtonState(); break;
        case 13: _t->onAddIpFilterClicked(); break;
        case 14: _t->onRemoveIpFilterClicked(); break;
        case 15: _t->onFixedIpFilterChanged(); break;
        case 16: _t->onPacketSelected(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN10MainWindowE.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP

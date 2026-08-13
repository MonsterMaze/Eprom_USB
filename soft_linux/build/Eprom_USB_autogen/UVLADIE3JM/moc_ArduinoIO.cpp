/****************************************************************************
** Meta object code from reading C++ file 'ArduinoIO.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/ArduinoIO.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ArduinoIO.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ArduinoIO_t {
    QByteArrayData data[19];
    char stringdata0[329];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ArduinoIO_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ArduinoIO_t qt_meta_stringdata_ArduinoIO = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ArduinoIO"
QT_MOC_LITERAL(1, 10, 26), // "SerialOperationStartSignal"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 26), // "SerialOperationErrorSignal"
QT_MOC_LITERAL(4, 65, 11), // "const char*"
QT_MOC_LITERAL(5, 77, 29), // "SerialOperationCompleteSignal"
QT_MOC_LITERAL(6, 107, 20), // "VoltageUpdatedSignal"
QT_MOC_LITERAL(7, 128, 15), // "ReadBlockSignal"
QT_MOC_LITERAL(8, 144, 18), // "ReadCompleteSignal"
QT_MOC_LITERAL(9, 163, 22), // "HardwareTestStepSignal"
QT_MOC_LITERAL(10, 186, 19), // "ReadEpromDataSignal"
QT_MOC_LITERAL(11, 206, 8), // "uint8_t*"
QT_MOC_LITERAL(12, 215, 16), // "WriteBlockSignal"
QT_MOC_LITERAL(13, 232, 19), // "WriteCompleteSignal"
QT_MOC_LITERAL(14, 252, 15), // "SelectEpromSlot"
QT_MOC_LITERAL(15, 268, 15), // "ReadVoltageSlot"
QT_MOC_LITERAL(16, 284, 13), // "ReadEpromSlot"
QT_MOC_LITERAL(17, 298, 15), // "HarwareTestSlot"
QT_MOC_LITERAL(18, 314, 14) // "WriteEpromSlot"

    },
    "ArduinoIO\0SerialOperationStartSignal\0"
    "\0SerialOperationErrorSignal\0const char*\0"
    "SerialOperationCompleteSignal\0"
    "VoltageUpdatedSignal\0ReadBlockSignal\0"
    "ReadCompleteSignal\0HardwareTestStepSignal\0"
    "ReadEpromDataSignal\0uint8_t*\0"
    "WriteBlockSignal\0WriteCompleteSignal\0"
    "SelectEpromSlot\0ReadVoltageSlot\0"
    "ReadEpromSlot\0HarwareTestSlot\0"
    "WriteEpromSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ArduinoIO[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    1,   90,    2, 0x06 /* Public */,
       5,    0,   93,    2, 0x06 /* Public */,
       6,    2,   94,    2, 0x06 /* Public */,
       7,    1,   99,    2, 0x06 /* Public */,
       8,    0,  102,    2, 0x06 /* Public */,
       9,    1,  103,    2, 0x06 /* Public */,
      10,    3,  106,    2, 0x06 /* Public */,
      12,    1,  113,    2, 0x06 /* Public */,
      13,    2,  116,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  121,    2, 0x08 /* Private */,
      15,    0,  122,    2, 0x08 /* Private */,
      16,    0,  123,    2, 0x08 /* Private */,
      17,    0,  124,    2, 0x08 /* Private */,
      18,    0,  125,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 11,    2,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ArduinoIO::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ArduinoIO *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SerialOperationStartSignal(); break;
        case 1: _t->SerialOperationErrorSignal((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 2: _t->SerialOperationCompleteSignal(); break;
        case 3: _t->VoltageUpdatedSignal((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 4: _t->ReadBlockSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->ReadCompleteSignal(); break;
        case 6: _t->HardwareTestStepSignal((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 7: _t->ReadEpromDataSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< uint8_t*(*)>(_a[3]))); break;
        case 8: _t->WriteBlockSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->WriteCompleteSignal((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2]))); break;
        case 10: _t->SelectEpromSlot(); break;
        case 11: _t->ReadVoltageSlot(); break;
        case 12: _t->ReadEpromSlot(); break;
        case 13: _t->HarwareTestSlot(); break;
        case 14: _t->WriteEpromSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ArduinoIO::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArduinoIO::SerialOperationStartSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ArduinoIO::*)(const char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArduinoIO::SerialOperationErrorSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ArduinoIO::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArduinoIO::SerialOperationCompleteSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ArduinoIO::*)(double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArduinoIO::VoltageUpdatedSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ArduinoIO::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArduinoIO::ReadBlockSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ArduinoIO::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArduinoIO::ReadCompleteSignal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ArduinoIO::*)(const char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArduinoIO::HardwareTestStepSignal)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ArduinoIO::*)(int , int , uint8_t * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArduinoIO::ReadEpromDataSignal)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ArduinoIO::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArduinoIO::WriteBlockSignal)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (ArduinoIO::*)(bool , const char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArduinoIO::WriteCompleteSignal)) {
                *result = 9;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ArduinoIO::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ArduinoIO.data,
    qt_meta_data_ArduinoIO,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ArduinoIO::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ArduinoIO::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ArduinoIO.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ArduinoIO::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void ArduinoIO::SerialOperationStartSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ArduinoIO::SerialOperationErrorSignal(const char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ArduinoIO::SerialOperationCompleteSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ArduinoIO::VoltageUpdatedSignal(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ArduinoIO::ReadBlockSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ArduinoIO::ReadCompleteSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ArduinoIO::HardwareTestStepSignal(const char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ArduinoIO::ReadEpromDataSignal(int _t1, int _t2, uint8_t * _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ArduinoIO::WriteBlockSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void ArduinoIO::WriteCompleteSignal(bool _t1, const char * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

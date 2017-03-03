/****************************************************************************
** Meta object code from reading C++ file 'rgbdial.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Interface/rgbdial.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rgbdial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_rgbDial_t {
    QByteArrayData data[9];
    char stringdata[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rgbDial_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rgbDial_t qt_meta_stringdata_rgbDial = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 21),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 5),
QT_MOC_LITERAL(4, 37, 22),
QT_MOC_LITERAL(5, 60, 20),
QT_MOC_LITERAL(6, 81, 24),
QT_MOC_LITERAL(7, 106, 26),
QT_MOC_LITERAL(8, 133, 25)
    },
    "rgbDial\0on__blue_valueChanged\0\0value\0"
    "on__green_valueChanged\0on__red_valueChanged\0"
    "on__redVal_returnPressed\0"
    "on__greenVal_returnPressed\0"
    "on__blueVal_returnPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rgbDial[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    1,   47,    2, 0x08 /* Private */,
       5,    1,   50,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void rgbDial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        rgbDial *_t = static_cast<rgbDial *>(_o);
        switch (_id) {
        case 0: _t->on__blue_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on__green_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on__red_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on__redVal_returnPressed(); break;
        case 4: _t->on__greenVal_returnPressed(); break;
        case 5: _t->on__blueVal_returnPressed(); break;
        default: ;
        }
    }
}

const QMetaObject rgbDial::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_rgbDial.data,
      qt_meta_data_rgbDial,  qt_static_metacall, 0, 0}
};


const QMetaObject *rgbDial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rgbDial::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rgbDial.stringdata))
        return static_cast<void*>(const_cast< rgbDial*>(this));
    return QDialog::qt_metacast(_clname);
}

int rgbDial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

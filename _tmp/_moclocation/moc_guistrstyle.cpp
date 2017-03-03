/****************************************************************************
** Meta object code from reading C++ file 'guistrstyle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Interface/guistrstyle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'guistrstyle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GuiStrStyle_t {
    QByteArrayData data[8];
    char stringdata[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GuiStrStyle_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GuiStrStyle_t qt_meta_stringdata_GuiStrStyle = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 15),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 14),
QT_MOC_LITERAL(4, 44, 14),
QT_MOC_LITERAL(5, 59, 20),
QT_MOC_LITERAL(6, 80, 17),
QT_MOC_LITERAL(7, 98, 16)
    },
    "GuiStrStyle\0lineEditChanged\0\0"
    "profileChanged\0contactChanged\0"
    "selectContactChanged\0onLineEditChanged\0"
    "onContactChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GuiStrStyle[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GuiStrStyle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GuiStrStyle *_t = static_cast<GuiStrStyle *>(_o);
        switch (_id) {
        case 0: _t->lineEditChanged(); break;
        case 1: _t->profileChanged(); break;
        case 2: _t->contactChanged(); break;
        case 3: _t->selectContactChanged(); break;
        case 4: _t->onLineEditChanged(); break;
        case 5: _t->onContactChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GuiStrStyle::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GuiStrStyle::lineEditChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (GuiStrStyle::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GuiStrStyle::profileChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (GuiStrStyle::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GuiStrStyle::contactChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (GuiStrStyle::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GuiStrStyle::selectContactChanged)) {
                *result = 3;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject GuiStrStyle::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GuiStrStyle.data,
      qt_meta_data_GuiStrStyle,  qt_static_metacall, 0, 0}
};


const QMetaObject *GuiStrStyle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GuiStrStyle::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GuiStrStyle.stringdata))
        return static_cast<void*>(const_cast< GuiStrStyle*>(this));
    return QObject::qt_metacast(_clname);
}

int GuiStrStyle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void GuiStrStyle::lineEditChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void GuiStrStyle::profileChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void GuiStrStyle::contactChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void GuiStrStyle::selectContactChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE

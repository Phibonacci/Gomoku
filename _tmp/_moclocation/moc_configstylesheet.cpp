/****************************************************************************
** Meta object code from reading C++ file 'configstylesheet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Interface/configstylesheet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configstylesheet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_configStyleSheet_t {
    QByteArrayData data[17];
    char stringdata[378];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_configStyleSheet_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_configStyleSheet_t qt_meta_stringdata_configStyleSheet = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 21),
QT_MOC_LITERAL(2, 39, 0),
QT_MOC_LITERAL(3, 40, 25),
QT_MOC_LITERAL(4, 66, 19),
QT_MOC_LITERAL(5, 86, 28),
QT_MOC_LITERAL(6, 115, 26),
QT_MOC_LITERAL(7, 142, 23),
QT_MOC_LITERAL(8, 166, 21),
QT_MOC_LITERAL(9, 188, 24),
QT_MOC_LITERAL(10, 213, 25),
QT_MOC_LITERAL(11, 239, 19),
QT_MOC_LITERAL(12, 259, 25),
QT_MOC_LITERAL(13, 285, 29),
QT_MOC_LITERAL(14, 315, 20),
QT_MOC_LITERAL(15, 336, 24),
QT_MOC_LITERAL(16, 361, 16)
    },
    "configStyleSheet\0on__windowBut_clicked\0"
    "\0on__windowTextBut_clicked\0"
    "on__baseBut_clicked\0on__alternateBaseBut_clicked\0"
    "on__toolTipBaseBut_clicked\0"
    "on__toolTipText_clicked\0on__buttonBut_clicked\0"
    "on__butonTextBut_clicked\0"
    "on__brightTextBut_clicked\0on__linkBut_clicked\0"
    "on__hightlightBut_clicked\0"
    "on__hightlitedTextBut_clicked\0"
    "on__editLine_clicked\0on__editLineText_clicked\0"
    "on__text_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_configStyleSheet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void configStyleSheet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        configStyleSheet *_t = static_cast<configStyleSheet *>(_o);
        switch (_id) {
        case 0: _t->on__windowBut_clicked(); break;
        case 1: _t->on__windowTextBut_clicked(); break;
        case 2: _t->on__baseBut_clicked(); break;
        case 3: _t->on__alternateBaseBut_clicked(); break;
        case 4: _t->on__toolTipBaseBut_clicked(); break;
        case 5: _t->on__toolTipText_clicked(); break;
        case 6: _t->on__buttonBut_clicked(); break;
        case 7: _t->on__butonTextBut_clicked(); break;
        case 8: _t->on__brightTextBut_clicked(); break;
        case 9: _t->on__linkBut_clicked(); break;
        case 10: _t->on__hightlightBut_clicked(); break;
        case 11: _t->on__hightlitedTextBut_clicked(); break;
        case 12: _t->on__editLine_clicked(); break;
        case 13: _t->on__editLineText_clicked(); break;
        case 14: _t->on__text_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject configStyleSheet::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_configStyleSheet.data,
      qt_meta_data_configStyleSheet,  qt_static_metacall, 0, 0}
};


const QMetaObject *configStyleSheet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *configStyleSheet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_configStyleSheet.stringdata))
        return static_cast<void*>(const_cast< configStyleSheet*>(this));
    return QDialog::qt_metacast(_clname);
}

int configStyleSheet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE

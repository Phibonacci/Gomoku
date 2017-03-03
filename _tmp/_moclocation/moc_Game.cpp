/****************************************************************************
** Meta object code from reading C++ file 'Game.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Logic/Game.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Game.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Logic__Game_t {
    QByteArrayData data[15];
    char stringdata[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Logic__Game_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Logic__Game_t qt_meta_stringdata_Logic__Game = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 6),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 13),
QT_MOC_LITERAL(4, 34, 6),
QT_MOC_LITERAL(5, 41, 1),
QT_MOC_LITERAL(6, 43, 1),
QT_MOC_LITERAL(7, 45, 5),
QT_MOC_LITERAL(8, 51, 11),
QT_MOC_LITERAL(9, 63, 3),
QT_MOC_LITERAL(10, 67, 13),
QT_MOC_LITERAL(11, 81, 9),
QT_MOC_LITERAL(12, 91, 6),
QT_MOC_LITERAL(13, 98, 5),
QT_MOC_LITERAL(14, 104, 4)
    },
    "Logic::Game\0played\0\0Logic::Player\0"
    "player\0x\0y\0error\0std::string\0err\0"
    "playerChanged\0humanPlay\0aiPlay\0reset\0"
    "undo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Logic__Game[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   49,    2, 0x06 /* Public */,
       7,    1,   56,    2, 0x06 /* Public */,
      10,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    2,   60,    2, 0x0a /* Public */,
      12,    2,   65,    2, 0x0a /* Public */,
      13,    0,   70,    2, 0x0a /* Public */,
      14,    0,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::UInt, QMetaType::UInt,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    5,    6,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    5,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Logic::Game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Game *_t = static_cast<Game *>(_o);
        switch (_id) {
        case 0: _t->played((*reinterpret_cast< const Logic::Player(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 1: _t->error((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 2: _t->playerChanged(); break;
        case 3: _t->humanPlay((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 4: _t->aiPlay((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 5: _t->reset(); break;
        case 6: _t->undo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Game::*_t)(const Logic::Player & , unsigned int , unsigned int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Game::played)) {
                *result = 0;
            }
        }
        {
            typedef void (Game::*_t)(const std::string & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Game::error)) {
                *result = 1;
            }
        }
        {
            typedef void (Game::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Game::playerChanged)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Logic::Game::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Logic__Game.data,
      qt_meta_data_Logic__Game,  qt_static_metacall, 0, 0}
};


const QMetaObject *Logic::Game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Logic::Game::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Logic__Game.stringdata))
        return static_cast<void*>(const_cast< Game*>(this));
    return QObject::qt_metacast(_clname);
}

int Logic::Game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Logic::Game::played(const Logic::Player & _t1, unsigned int _t2, unsigned int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Logic::Game::error(const std::string & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Logic::Game::playerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE

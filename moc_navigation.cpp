/****************************************************************************
** Meta object code from reading C++ file 'navigation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../login/navigation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'navigation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_navigation_t {
    QByteArrayData data[18];
    char stringdata0[271];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_navigation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_navigation_t qt_meta_stringdata_navigation = {
    {
QT_MOC_LITERAL(0, 0, 10), // "navigation"
QT_MOC_LITERAL(1, 11, 11), // "receiveData"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "data"
QT_MOC_LITERAL(4, 29, 9), // "nav_click"
QT_MOC_LITERAL(5, 39, 1), // "i"
QT_MOC_LITERAL(6, 41, 15), // "on_back_clicked"
QT_MOC_LITERAL(7, 57, 17), // "on_modify_clicked"
QT_MOC_LITERAL(8, 75, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(9, 97, 16), // "on_delet_clicked"
QT_MOC_LITERAL(10, 114, 19), // "on_shortest_clicked"
QT_MOC_LITERAL(11, 134, 19), // "on_cheapest_clicked"
QT_MOC_LITERAL(12, 154, 18), // "on_lessway_clicked"
QT_MOC_LITERAL(13, 173, 18), // "on_freeway_clicked"
QT_MOC_LITERAL(14, 192, 20), // "on_roadfirst_clicked"
QT_MOC_LITERAL(15, 213, 15), // "on_walk_clicked"
QT_MOC_LITERAL(16, 229, 23), // "on_bimianyongdu_clicked"
QT_MOC_LITERAL(17, 253, 17) // "on_search_clicked"

    },
    "navigation\0receiveData\0\0data\0nav_click\0"
    "i\0on_back_clicked\0on_modify_clicked\0"
    "on_pushButton_clicked\0on_delet_clicked\0"
    "on_shortest_clicked\0on_cheapest_clicked\0"
    "on_lessway_clicked\0on_freeway_clicked\0"
    "on_roadfirst_clicked\0on_walk_clicked\0"
    "on_bimianyongdu_clicked\0on_search_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_navigation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x08 /* Private */,
       4,    1,   87,    2, 0x0a /* Public */,
       6,    0,   90,    2, 0x0a /* Public */,
       7,    0,   91,    2, 0x0a /* Public */,
       8,    0,   92,    2, 0x08 /* Private */,
       9,    0,   93,    2, 0x08 /* Private */,
      10,    0,   94,    2, 0x08 /* Private */,
      11,    0,   95,    2, 0x08 /* Private */,
      12,    0,   96,    2, 0x08 /* Private */,
      13,    0,   97,    2, 0x08 /* Private */,
      14,    0,   98,    2, 0x08 /* Private */,
      15,    0,   99,    2, 0x08 /* Private */,
      16,    0,  100,    2, 0x08 /* Private */,
      17,    0,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
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

void navigation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        navigation *_t = static_cast<navigation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receiveData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->nav_click((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_back_clicked(); break;
        case 3: _t->on_modify_clicked(); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_delet_clicked(); break;
        case 6: _t->on_shortest_clicked(); break;
        case 7: _t->on_cheapest_clicked(); break;
        case 8: _t->on_lessway_clicked(); break;
        case 9: _t->on_freeway_clicked(); break;
        case 10: _t->on_roadfirst_clicked(); break;
        case 11: _t->on_walk_clicked(); break;
        case 12: _t->on_bimianyongdu_clicked(); break;
        case 13: _t->on_search_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject navigation::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_navigation.data,
      qt_meta_data_navigation,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *navigation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *navigation::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_navigation.stringdata0))
        return static_cast<void*>(const_cast< navigation*>(this));
    return QDialog::qt_metacast(_clname);
}

int navigation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

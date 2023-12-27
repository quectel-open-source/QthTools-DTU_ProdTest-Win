/****************************************************************************
** Meta object code from reading C++ file 'toolupdate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../QthTools-DTU_ProdTest-Win/third/QSimpleUpdater/toolupdate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toolupdate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_toolUpdate_t {
    QByteArrayData data[10];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_toolUpdate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_toolUpdate_t qt_meta_stringdata_toolUpdate = {
    {
QT_MOC_LITERAL(0, 0, 10), // "toolUpdate"
QT_MOC_LITERAL(1, 11, 15), // "checkForUpdates"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "resetFields"
QT_MOC_LITERAL(4, 40, 15), // "updateChangelog"
QT_MOC_LITERAL(5, 56, 3), // "url"
QT_MOC_LITERAL(6, 60, 14), // "displayAppcast"
QT_MOC_LITERAL(7, 75, 5), // "reply"
QT_MOC_LITERAL(8, 81, 14), // "updataExeEvent"
QT_MOC_LITERAL(9, 96, 11) // "newSoftName"

    },
    "toolUpdate\0checkForUpdates\0\0resetFields\0"
    "updateChangelog\0url\0displayAppcast\0"
    "reply\0updataExeEvent\0newSoftName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_toolUpdate[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    1,   41,    2, 0x08 /* Private */,
       6,    2,   44,    2, 0x08 /* Private */,
       8,    1,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QByteArray,    5,    7,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void toolUpdate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<toolUpdate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->checkForUpdates(); break;
        case 1: _t->resetFields(); break;
        case 2: _t->updateChangelog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->displayAppcast((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 4: _t->updataExeEvent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject toolUpdate::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_toolUpdate.data,
    qt_meta_data_toolUpdate,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *toolUpdate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *toolUpdate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_toolUpdate.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int toolUpdate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

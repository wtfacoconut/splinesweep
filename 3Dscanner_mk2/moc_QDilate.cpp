/****************************************************************************
** Meta object code from reading C++ file 'QDilate.h'
**
** Created: Sun Apr 18 15:41:11 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QDilate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QDilate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QDilate[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      15,    9,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   32,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QDilate[] = {
    "QDilate\0\0image\0newImage(QImage)\0"
    "passed_image\0setImage(QImage)\0"
};

const QMetaObject QDilate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QDilate,
      qt_meta_data_QDilate, 0 }
};

const QMetaObject *QDilate::metaObject() const
{
    return &staticMetaObject;
}

void *QDilate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDilate))
        return static_cast<void*>(const_cast< QDilate*>(this));
    return QObject::qt_metacast(_clname);
}

int QDilate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: setImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QDilate::newImage(QImage _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

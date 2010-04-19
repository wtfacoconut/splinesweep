/****************************************************************************
** Meta object code from reading C++ file 'QChromaKey.h'
**
** Created: Sun Apr 18 15:41:05 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QChromaKey.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QChromaKey.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QChromaKey[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   35,   11,   11, 0x0a,
      72,   65,   11,   11, 0x0a,
      87,   65,   11,   11, 0x0a,
     102,   65,   11,   11, 0x0a,
     119,   65,   11,   11, 0x0a,
     136,   65,   11,   11, 0x0a,
     152,   65,   11,   11, 0x0a,
     168,   65,   11,   11, 0x0a,
     186,   65,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QChromaKey[] = {
    "QChromaKey\0\0image\0newImage(QImage)\0"
    "passed_image\0setImage(QImage)\0passed\0"
    "setRedMax(int)\0setRedMin(int)\0"
    "setGreenMax(int)\0setGreenMin(int)\0"
    "setBlueMax(int)\0setBlueMin(int)\0"
    "setMaxColor(QRgb)\0setMinColor(QRgb)\0"
};

const QMetaObject QChromaKey::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QChromaKey,
      qt_meta_data_QChromaKey, 0 }
};

const QMetaObject *QChromaKey::metaObject() const
{
    return &staticMetaObject;
}

void *QChromaKey::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QChromaKey))
        return static_cast<void*>(const_cast< QChromaKey*>(this));
    return QObject::qt_metacast(_clname);
}

int QChromaKey::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: setImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: setRedMax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: setRedMin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: setGreenMax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: setGreenMin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: setBlueMax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: setBlueMin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: setMaxColor((*reinterpret_cast< QRgb(*)>(_a[1]))); break;
        case 9: setMinColor((*reinterpret_cast< QRgb(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QChromaKey::newImage(QImage _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

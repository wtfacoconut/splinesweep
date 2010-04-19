/****************************************************************************
** Meta object code from reading C++ file 'ModelGen.h'
**
** Created: Sun Apr 18 15:41:00 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ModelGen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModelGen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ModelGen[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      17,   10,    9,    9, 0x08,
      34,   10,    9,    9, 0x08,
      53,   10,    9,    9, 0x08,
      71,    9,    9,    9, 0x08,
     101,   94,   87,    9, 0x08,
     131,  124,   87,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ModelGen[] = {
    "ModelGen\0\0passed\0setImage(QImage)\0"
    "setTexture(QImage)\0setNumImages(int)\0"
    "createTexture()\0double\0radian\0"
    "radianToDegree(double)\0degree\0"
    "degreeToRadian(double)\0"
};

const QMetaObject ModelGen::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ModelGen,
      qt_meta_data_ModelGen, 0 }
};

const QMetaObject *ModelGen::metaObject() const
{
    return &staticMetaObject;
}

void *ModelGen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ModelGen))
        return static_cast<void*>(const_cast< ModelGen*>(this));
    return QObject::qt_metacast(_clname);
}

int ModelGen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: setTexture((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: setNumImages((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: createTexture(); break;
        case 4: { double _r = radianToDegree((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 5: { double _r = degreeToRadian((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

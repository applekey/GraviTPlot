/****************************************************************************
** Meta object code from reading C++ file 'QvisGraviTPlotWindow.h'
**
** Created: Mon Jun 6 12:43:29 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QvisGraviTPlotWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QvisGraviTPlotWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QvisGraviTPlotWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   29,   29,   29, 0x0a,
      30,   29,   29,   29, 0x0a,
      44,   29,   29,   29, 0x0a,
      52,   77,   29,   29, 0x08,
      83,   77,   29,   29, 0x08,
     108,   29,   29,   29, 0x08,
     136,  157,   29,   29, 0x08,
     161,  157,   29,   29, 0x08,
     186,   29,   29,   29, 0x08,
     207,   29,   29,   29, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QvisGraviTPlotWindow[] = {
    "QvisGraviTPlotWindow\0apply()\0\0"
    "makeDefault()\0reset()\0DiffColorChanged(QColor)\0"
    "color\0SpecColorChanged(QColor)\0"
    "MaxReflectionsProcessText()\0"
    "MaterialChanged(int)\0val\0"
    "ScheduleTypeChanged(int)\0SamplesProcessText()\0"
    "JitterSizeProcessText()\0"
};

void QvisGraviTPlotWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QvisGraviTPlotWindow *_t = static_cast<QvisGraviTPlotWindow *>(_o);
        switch (_id) {
        case 0: _t->apply(); break;
        case 1: _t->makeDefault(); break;
        case 2: _t->reset(); break;
        case 3: _t->DiffColorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 4: _t->SpecColorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 5: _t->MaxReflectionsProcessText(); break;
        case 6: _t->MaterialChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->ScheduleTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->SamplesProcessText(); break;
        case 9: _t->JitterSizeProcessText(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QvisGraviTPlotWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QvisGraviTPlotWindow::staticMetaObject = {
    { &QvisPostableWindowObserver::staticMetaObject, qt_meta_stringdata_QvisGraviTPlotWindow,
      qt_meta_data_QvisGraviTPlotWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QvisGraviTPlotWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QvisGraviTPlotWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QvisGraviTPlotWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QvisGraviTPlotWindow))
        return static_cast<void*>(const_cast< QvisGraviTPlotWindow*>(this));
    return QvisPostableWindowObserver::qt_metacast(_clname);
}

int QvisGraviTPlotWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QvisPostableWindowObserver::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

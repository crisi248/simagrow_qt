/****************************************************************************
** Meta object code from reading C++ file 'ventanaprincipal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "ventanaprincipal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ventanaprincipal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VentanaPrincipal_t {
    QByteArrayData data[12];
    char stringdata0[237];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VentanaPrincipal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VentanaPrincipal_t qt_meta_stringdata_VentanaPrincipal = {
    {
QT_MOC_LITERAL(0, 0, 16), // "VentanaPrincipal"
QT_MOC_LITERAL(1, 17, 22), // "slotResolverIncidencia"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 21), // "slotGuardarIncidencia"
QT_MOC_LITERAL(4, 63, 25), // "slotCargarDatosIncidencia"
QT_MOC_LITERAL(5, 89, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 106, 23), // "slotRecargarIncidencias"
QT_MOC_LITERAL(7, 130, 24), // "slotIncidenciasRecibidas"
QT_MOC_LITERAL(8, 155, 20), // "slotErrorIncidencias"
QT_MOC_LITERAL(9, 176, 16), // "slotFiltrarTodos"
QT_MOC_LITERAL(10, 193, 20), // "slotFiltrarResueltos"
QT_MOC_LITERAL(11, 214, 22) // "slotFiltrarNoResueltos"

    },
    "VentanaPrincipal\0slotResolverIncidencia\0"
    "\0slotGuardarIncidencia\0slotCargarDatosIncidencia\0"
    "QListWidgetItem*\0slotRecargarIncidencias\0"
    "slotIncidenciasRecibidas\0slotErrorIncidencias\0"
    "slotFiltrarTodos\0slotFiltrarResueltos\0"
    "slotFiltrarNoResueltos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VentanaPrincipal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       3,    0,   62,    2, 0x0a /* Public */,
       4,    1,   63,    2, 0x0a /* Public */,
       6,    0,   66,    2, 0x0a /* Public */,
       7,    1,   67,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VentanaPrincipal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VentanaPrincipal *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slotResolverIncidencia((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->slotGuardarIncidencia(); break;
        case 2: _t->slotCargarDatosIncidencia((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->slotRecargarIncidencias(); break;
        case 4: _t->slotIncidenciasRecibidas((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->slotErrorIncidencias(); break;
        case 6: _t->slotFiltrarTodos(); break;
        case 7: _t->slotFiltrarResueltos(); break;
        case 8: _t->slotFiltrarNoResueltos(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VentanaPrincipal::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_VentanaPrincipal.data,
    qt_meta_data_VentanaPrincipal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VentanaPrincipal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VentanaPrincipal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VentanaPrincipal.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::VentanaPrincipal"))
        return static_cast< Ui::VentanaPrincipal*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int VentanaPrincipal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

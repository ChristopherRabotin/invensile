/****************************************************************************
** Meta object code from reading C++ file 'createaddressdialog.h'
**
** Created:
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "createaddressdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'createaddressdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CreateAddressDialog[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x08,
      30,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CreateAddressDialog[] = {
    "CreateAddressDialog\0\0accept()\0"
    "checkValues()\0"
};

const QMetaObject CreateAddressDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateAddressDialog,
      qt_meta_data_CreateAddressDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CreateAddressDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CreateAddressDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CreateAddressDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CreateAddressDialog))
        return static_cast<void*>(const_cast< CreateAddressDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateAddressDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: accept(); break;
        case 1: checkValues(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'ledindicator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../LedTriIndicator/LedIndicator/ledindicator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ledindicator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LedIndicator_t {
    QByteArrayData data[14];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LedIndicator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LedIndicator_t qt_meta_stringdata_LedIndicator = {
    {
QT_MOC_LITERAL(0, 0, 12), // "LedIndicator"
QT_MOC_LITERAL(1, 13, 12), // "stateToggled"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "stateChanged"
QT_MOC_LITERAL(4, 40, 14), // "IndicatorState"
QT_MOC_LITERAL(5, 55, 5), // "state"
QT_MOC_LITERAL(6, 61, 7), // "setText"
QT_MOC_LITERAL(7, 69, 4), // "text"
QT_MOC_LITERAL(8, 74, 11), // "setTurnedOn"
QT_MOC_LITERAL(9, 86, 6), // "turned"
QT_MOC_LITERAL(10, 93, 11), // "setTristate"
QT_MOC_LITERAL(11, 105, 10), // "isTristate"
QT_MOC_LITERAL(12, 116, 8), // "setState"
QT_MOC_LITERAL(13, 125, 8) // "turnedOn"

    },
    "LedIndicator\0stateToggled\0\0stateChanged\0"
    "IndicatorState\0state\0setText\0text\0"
    "setTurnedOn\0turned\0setTristate\0"
    "isTristate\0setState\0turnedOn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LedIndicator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       3,   62, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   50,    2, 0x0a /* Public */,
       8,    1,   53,    2, 0x0a /* Public */,
      10,    1,   56,    2, 0x0a /* Public */,
      12,    1,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, 0x80000000 | 4,    5,

 // properties: name, type, flags
       7, QMetaType::QString, 0x00095103,
      13, QMetaType::Bool, 0x00495103,
       5, 0x80000000 | 4, 0x0049510b,

 // properties: notify_signal_id
       0,
       0,
       1,

       0        // eod
};

void LedIndicator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LedIndicator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->stateToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->stateChanged((*reinterpret_cast< IndicatorState(*)>(_a[1]))); break;
        case 2: _t->setText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->setTurnedOn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setTristate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setState((*reinterpret_cast< IndicatorState(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LedIndicator::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LedIndicator::stateToggled)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LedIndicator::*)(IndicatorState );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LedIndicator::stateChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<LedIndicator *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->text(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->isTurnedOn(); break;
        case 2: *reinterpret_cast< IndicatorState*>(_v) = _t->state(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<LedIndicator *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setText(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setTurnedOn(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setState(*reinterpret_cast< IndicatorState*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject LedIndicator::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_LedIndicator.data,
    qt_meta_data_LedIndicator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LedIndicator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LedIndicator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LedIndicator.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LedIndicator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void LedIndicator::stateToggled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LedIndicator::stateChanged(IndicatorState _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

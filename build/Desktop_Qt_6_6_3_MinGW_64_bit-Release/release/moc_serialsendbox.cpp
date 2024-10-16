/****************************************************************************
** Meta object code from reading C++ file 'serialsendbox.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/SimpleTab/serialsendbox.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialsendbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSerialSendBoxENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSerialSendBoxENDCLASS = QtMocHelpers::stringData(
    "SerialSendBox",
    "errorSend",
    "",
    "string",
    "addSendCount",
    "count",
    "on_buttonSend_clicked",
    "onCheckBoxChanged",
    "onCheckTimerStateChanged",
    "onSpinTimerValueChanged",
    "i"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSerialSendBoxENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[14];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[7];
    char stringdata4[13];
    char stringdata5[6];
    char stringdata6[22];
    char stringdata7[18];
    char stringdata8[25];
    char stringdata9[24];
    char stringdata10[2];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSerialSendBoxENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSerialSendBoxENDCLASS_t qt_meta_stringdata_CLASSSerialSendBoxENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "SerialSendBox"
        QT_MOC_LITERAL(14, 9),  // "errorSend"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 6),  // "string"
        QT_MOC_LITERAL(32, 12),  // "addSendCount"
        QT_MOC_LITERAL(45, 5),  // "count"
        QT_MOC_LITERAL(51, 21),  // "on_buttonSend_clicked"
        QT_MOC_LITERAL(73, 17),  // "onCheckBoxChanged"
        QT_MOC_LITERAL(91, 24),  // "onCheckTimerStateChanged"
        QT_MOC_LITERAL(116, 23),  // "onSpinTimerValueChanged"
        QT_MOC_LITERAL(140, 1)   // "i"
    },
    "SerialSendBox",
    "errorSend",
    "",
    "string",
    "addSendCount",
    "count",
    "on_buttonSend_clicked",
    "onCheckBoxChanged",
    "onCheckTimerStateChanged",
    "onSpinTimerValueChanged",
    "i"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSerialSendBoxENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,
       4,    1,   53,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   56,    2, 0x08,    5 /* Private */,
       7,    0,   57,    2, 0x08,    6 /* Private */,
       8,    0,   58,    2, 0x08,    7 /* Private */,
       9,    1,   59,    2, 0x08,    8 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

Q_CONSTINIT const QMetaObject SerialSendBox::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSSerialSendBoxENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSerialSendBoxENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSerialSendBoxENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SerialSendBox, std::true_type>,
        // method 'errorSend'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'addSendCount'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_buttonSend_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCheckBoxChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCheckTimerStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSpinTimerValueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void SerialSendBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SerialSendBox *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->errorSend((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->addSendCount((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->on_buttonSend_clicked(); break;
        case 3: _t->onCheckBoxChanged(); break;
        case 4: _t->onCheckTimerStateChanged(); break;
        case 5: _t->onSpinTimerValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SerialSendBox::*)(QString );
            if (_t _q_method = &SerialSendBox::errorSend; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SerialSendBox::*)(int );
            if (_t _q_method = &SerialSendBox::addSendCount; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *SerialSendBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialSendBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSerialSendBoxENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SerialSendBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SerialSendBox::errorSend(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SerialSendBox::addSendCount(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP

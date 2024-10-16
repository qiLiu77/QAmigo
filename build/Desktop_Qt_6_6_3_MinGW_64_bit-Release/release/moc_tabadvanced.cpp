/****************************************************************************
** Meta object code from reading C++ file 'tabadvanced.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/AdvancedTab/tabadvanced.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qabstractbarseries.h>
#include <QtCharts/qvbarmodelmapper.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCharts/qcandlestickseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tabadvanced.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSTabAdvancedENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSTabAdvancedENDCLASS = QtMocHelpers::stringData(
    "TabAdvanced",
    "onDecodeParametersUpdated",
    "",
    "QList<Protocal*>",
    "listProtocals",
    "frameDataReady",
    "id",
    "QList<double>",
    "listValues",
    "onButtonAddHeaderClicked",
    "onButtonAddDataClicked",
    "onButtonDeleteClicked",
    "onButtonUpClicked",
    "onButtonDownClicked",
    "onButtonEnableClicked",
    "onButtonLoadSettingsClicked",
    "onButtonSaveSettingsClicked",
    "onRadioLittleBigClicked",
    "onButtonClearLogClicked",
    "ontreeProtocalItemChanged",
    "QStandardItem*",
    "item",
    "onGraphUpdate",
    "currentX"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTabAdvancedENDCLASS_t {
    uint offsetsAndSizes[48];
    char stringdata0[12];
    char stringdata1[26];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[14];
    char stringdata5[15];
    char stringdata6[3];
    char stringdata7[14];
    char stringdata8[11];
    char stringdata9[25];
    char stringdata10[23];
    char stringdata11[22];
    char stringdata12[18];
    char stringdata13[20];
    char stringdata14[22];
    char stringdata15[28];
    char stringdata16[28];
    char stringdata17[24];
    char stringdata18[24];
    char stringdata19[26];
    char stringdata20[15];
    char stringdata21[5];
    char stringdata22[14];
    char stringdata23[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTabAdvancedENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTabAdvancedENDCLASS_t qt_meta_stringdata_CLASSTabAdvancedENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "TabAdvanced"
        QT_MOC_LITERAL(12, 25),  // "onDecodeParametersUpdated"
        QT_MOC_LITERAL(38, 0),  // ""
        QT_MOC_LITERAL(39, 16),  // "QList<Protocal*>"
        QT_MOC_LITERAL(56, 13),  // "listProtocals"
        QT_MOC_LITERAL(70, 14),  // "frameDataReady"
        QT_MOC_LITERAL(85, 2),  // "id"
        QT_MOC_LITERAL(88, 13),  // "QList<double>"
        QT_MOC_LITERAL(102, 10),  // "listValues"
        QT_MOC_LITERAL(113, 24),  // "onButtonAddHeaderClicked"
        QT_MOC_LITERAL(138, 22),  // "onButtonAddDataClicked"
        QT_MOC_LITERAL(161, 21),  // "onButtonDeleteClicked"
        QT_MOC_LITERAL(183, 17),  // "onButtonUpClicked"
        QT_MOC_LITERAL(201, 19),  // "onButtonDownClicked"
        QT_MOC_LITERAL(221, 21),  // "onButtonEnableClicked"
        QT_MOC_LITERAL(243, 27),  // "onButtonLoadSettingsClicked"
        QT_MOC_LITERAL(271, 27),  // "onButtonSaveSettingsClicked"
        QT_MOC_LITERAL(299, 23),  // "onRadioLittleBigClicked"
        QT_MOC_LITERAL(323, 23),  // "onButtonClearLogClicked"
        QT_MOC_LITERAL(347, 25),  // "ontreeProtocalItemChanged"
        QT_MOC_LITERAL(373, 14),  // "QStandardItem*"
        QT_MOC_LITERAL(388, 4),  // "item"
        QT_MOC_LITERAL(393, 13),  // "onGraphUpdate"
        QT_MOC_LITERAL(407, 8)   // "currentX"
    },
    "TabAdvanced",
    "onDecodeParametersUpdated",
    "",
    "QList<Protocal*>",
    "listProtocals",
    "frameDataReady",
    "id",
    "QList<double>",
    "listValues",
    "onButtonAddHeaderClicked",
    "onButtonAddDataClicked",
    "onButtonDeleteClicked",
    "onButtonUpClicked",
    "onButtonDownClicked",
    "onButtonEnableClicked",
    "onButtonLoadSettingsClicked",
    "onButtonSaveSettingsClicked",
    "onRadioLittleBigClicked",
    "onButtonClearLogClicked",
    "ontreeProtocalItemChanged",
    "QStandardItem*",
    "item",
    "onGraphUpdate",
    "currentX"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTabAdvancedENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   98,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    2,  101,    2, 0x0a,    3 /* Public */,
       9,    0,  106,    2, 0x08,    6 /* Private */,
      10,    0,  107,    2, 0x08,    7 /* Private */,
      11,    0,  108,    2, 0x08,    8 /* Private */,
      12,    0,  109,    2, 0x08,    9 /* Private */,
      13,    0,  110,    2, 0x08,   10 /* Private */,
      14,    0,  111,    2, 0x08,   11 /* Private */,
      15,    0,  112,    2, 0x08,   12 /* Private */,
      16,    0,  113,    2, 0x08,   13 /* Private */,
      17,    0,  114,    2, 0x08,   14 /* Private */,
      18,    0,  115,    2, 0x08,   15 /* Private */,
      19,    1,  116,    2, 0x08,   16 /* Private */,
      22,    1,  119,    2, 0x08,   18 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 7,    6,    8,
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
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, QMetaType::Int,   23,

       0        // eod
};

Q_CONSTINIT const QMetaObject TabAdvanced::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSTabAdvancedENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTabAdvancedENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTabAdvancedENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TabAdvanced, std::true_type>,
        // method 'onDecodeParametersUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<Protocal*> &, std::false_type>,
        // method 'frameDataReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<double>, std::false_type>,
        // method 'onButtonAddHeaderClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonAddDataClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonDeleteClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonUpClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonDownClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonEnableClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonLoadSettingsClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonSaveSettingsClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRadioLittleBigClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonClearLogClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ontreeProtocalItemChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStandardItem *, std::false_type>,
        // method 'onGraphUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void TabAdvanced::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TabAdvanced *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onDecodeParametersUpdated((*reinterpret_cast< std::add_pointer_t<QList<Protocal*>>>(_a[1]))); break;
        case 1: _t->frameDataReady((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<double>>>(_a[2]))); break;
        case 2: _t->onButtonAddHeaderClicked(); break;
        case 3: _t->onButtonAddDataClicked(); break;
        case 4: _t->onButtonDeleteClicked(); break;
        case 5: _t->onButtonUpClicked(); break;
        case 6: _t->onButtonDownClicked(); break;
        case 7: _t->onButtonEnableClicked(); break;
        case 8: _t->onButtonLoadSettingsClicked(); break;
        case 9: _t->onButtonSaveSettingsClicked(); break;
        case 10: _t->onRadioLittleBigClicked(); break;
        case 11: _t->onButtonClearLogClicked(); break;
        case 12: _t->ontreeProtocalItemChanged((*reinterpret_cast< std::add_pointer_t<QStandardItem*>>(_a[1]))); break;
        case 13: _t->onGraphUpdate((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TabAdvanced::*)(const QList<Protocal*> & );
            if (_t _q_method = &TabAdvanced::onDecodeParametersUpdated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *TabAdvanced::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TabAdvanced::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTabAdvancedENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TabAdvanced::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void TabAdvanced::onDecodeParametersUpdated(const QList<Protocal*> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP

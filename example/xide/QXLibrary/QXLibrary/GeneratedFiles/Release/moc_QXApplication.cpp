/****************************************************************************
** Meta object code from reading C++ file 'QXApplication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QXApplication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QXApplication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QXApplication_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QXApplication_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QXApplication_t qt_meta_stringdata_QXApplication = {
    {
QT_MOC_LITERAL(0, 0, 13) // "QXApplication"

    },
    "QXApplication"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QXApplication[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void QXApplication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject QXApplication::staticMetaObject = {
    { &QApplication::staticMetaObject, qt_meta_stringdata_QXApplication.data,
      qt_meta_data_QXApplication,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QXApplication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QXApplication::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QXApplication.stringdata0))
        return static_cast<void*>(const_cast< QXApplication*>(this));
    return QApplication::qt_metacast(_clname);
}

int QXApplication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QApplication::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ActionReceiver_t {
    QByteArrayData data[93];
    char stringdata0[1162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ActionReceiver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ActionReceiver_t qt_meta_stringdata_ActionReceiver = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ActionReceiver"
QT_MOC_LITERAL(1, 15, 15), // "ActionTriggered"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 3), // "act"
QT_MOC_LITERAL(4, 36, 13), // "tritemPressed"
QT_MOC_LITERAL(5, 50, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(6, 67, 4), // "item"
QT_MOC_LITERAL(7, 72, 6), // "column"
QT_MOC_LITERAL(8, 79, 13), // "tritemClicked"
QT_MOC_LITERAL(9, 93, 19), // "tritemDoubleClicked"
QT_MOC_LITERAL(10, 113, 15), // "tritemActivated"
QT_MOC_LITERAL(11, 129, 13), // "tritemEntered"
QT_MOC_LITERAL(12, 143, 13), // "tritemChanged"
QT_MOC_LITERAL(13, 157, 14), // "tritemExpanded"
QT_MOC_LITERAL(14, 172, 15), // "tritemCollapsed"
QT_MOC_LITERAL(15, 188, 20), // "trcurrentItemChanged"
QT_MOC_LITERAL(16, 209, 7), // "current"
QT_MOC_LITERAL(17, 217, 8), // "previous"
QT_MOC_LITERAL(18, 226, 22), // "tritemSelectionChanged"
QT_MOC_LITERAL(19, 249, 10), // "btnclicked"
QT_MOC_LITERAL(20, 260, 7), // "checked"
QT_MOC_LITERAL(21, 268, 10), // "btntoggled"
QT_MOC_LITERAL(22, 279, 10), // "btnpressed"
QT_MOC_LITERAL(23, 290, 11), // "btnreleased"
QT_MOC_LITERAL(24, 302, 8), // "onFinish"
QT_MOC_LITERAL(25, 311, 3), // "res"
QT_MOC_LITERAL(26, 315, 8), // "onAccept"
QT_MOC_LITERAL(27, 324, 8), // "onReject"
QT_MOC_LITERAL(28, 333, 15), // "QSCN_SELCHANGED"
QT_MOC_LITERAL(29, 349, 3), // "yes"
QT_MOC_LITERAL(30, 353, 18), // "SCN_AUTOCCANCELLED"
QT_MOC_LITERAL(31, 372, 20), // "SCN_AUTOCCHARDELETED"
QT_MOC_LITERAL(32, 393, 18), // "SCN_AUTOCCOMPLETED"
QT_MOC_LITERAL(33, 412, 11), // "const char*"
QT_MOC_LITERAL(34, 424, 9), // "selection"
QT_MOC_LITERAL(35, 434, 8), // "position"
QT_MOC_LITERAL(36, 443, 2), // "ch"
QT_MOC_LITERAL(37, 446, 6), // "method"
QT_MOC_LITERAL(38, 453, 18), // "SCN_AUTOCSELECTION"
QT_MOC_LITERAL(39, 472, 11), // "SCEN_CHANGE"
QT_MOC_LITERAL(40, 484, 16), // "SCN_CALLTIPCLICK"
QT_MOC_LITERAL(41, 501, 9), // "direction"
QT_MOC_LITERAL(42, 511, 13), // "SCN_CHARADDED"
QT_MOC_LITERAL(43, 525, 9), // "charadded"
QT_MOC_LITERAL(44, 535, 15), // "SCN_DOUBLECLICK"
QT_MOC_LITERAL(45, 551, 4), // "line"
QT_MOC_LITERAL(46, 556, 9), // "modifiers"
QT_MOC_LITERAL(47, 566, 12), // "SCN_DWELLEND"
QT_MOC_LITERAL(48, 579, 1), // "x"
QT_MOC_LITERAL(49, 581, 1), // "y"
QT_MOC_LITERAL(50, 583, 14), // "SCN_DWELLSTART"
QT_MOC_LITERAL(51, 598, 11), // "SCN_FOCUSIN"
QT_MOC_LITERAL(52, 610, 12), // "SCN_FOCUSOUT"
QT_MOC_LITERAL(53, 623, 16), // "SCN_HOTSPOTCLICK"
QT_MOC_LITERAL(54, 640, 22), // "SCN_HOTSPOTDOUBLECLICK"
QT_MOC_LITERAL(55, 663, 23), // "SCN_HOTSPOTRELEASECLICK"
QT_MOC_LITERAL(56, 687, 18), // "SCN_INDICATORCLICK"
QT_MOC_LITERAL(57, 706, 20), // "SCN_INDICATORRELEASE"
QT_MOC_LITERAL(58, 727, 15), // "SCN_MACRORECORD"
QT_MOC_LITERAL(59, 743, 3), // "msg"
QT_MOC_LITERAL(60, 747, 6), // "wparam"
QT_MOC_LITERAL(61, 754, 6), // "lparam"
QT_MOC_LITERAL(62, 761, 15), // "SCN_MARGINCLICK"
QT_MOC_LITERAL(63, 777, 6), // "margin"
QT_MOC_LITERAL(64, 784, 20), // "SCN_MARGINRIGHTCLICK"
QT_MOC_LITERAL(65, 805, 12), // "SCN_MODIFIED"
QT_MOC_LITERAL(66, 818, 7), // "modType"
QT_MOC_LITERAL(67, 826, 4), // "text"
QT_MOC_LITERAL(68, 831, 6), // "length"
QT_MOC_LITERAL(69, 838, 10), // "linesAdded"
QT_MOC_LITERAL(70, 849, 12), // "foldLevelNow"
QT_MOC_LITERAL(71, 862, 13), // "foldLevelPrev"
QT_MOC_LITERAL(72, 876, 5), // "token"
QT_MOC_LITERAL(73, 882, 20), // "annotationLinesAdded"
QT_MOC_LITERAL(74, 903, 19), // "SCN_MODIFYATTEMPTRO"
QT_MOC_LITERAL(75, 923, 13), // "SCN_NEEDSHOWN"
QT_MOC_LITERAL(76, 937, 11), // "SCN_PAINTED"
QT_MOC_LITERAL(77, 949, 17), // "SCN_SAVEPOINTLEFT"
QT_MOC_LITERAL(78, 967, 20), // "SCN_SAVEPOINTREACHED"
QT_MOC_LITERAL(79, 988, 15), // "SCN_STYLENEEDED"
QT_MOC_LITERAL(80, 1004, 12), // "SCN_UPDATEUI"
QT_MOC_LITERAL(81, 1017, 7), // "updated"
QT_MOC_LITERAL(82, 1025, 21), // "SCN_USERLISTSELECTION"
QT_MOC_LITERAL(83, 1047, 8), // "SCN_ZOOM"
QT_MOC_LITERAL(84, 1056, 12), // "etextChanged"
QT_MOC_LITERAL(85, 1069, 3), // "str"
QT_MOC_LITERAL(86, 1073, 11), // "etextEdited"
QT_MOC_LITERAL(87, 1085, 22), // "ecursorPositionChanged"
QT_MOC_LITERAL(88, 1108, 1), // "a"
QT_MOC_LITERAL(89, 1110, 1), // "b"
QT_MOC_LITERAL(90, 1112, 14), // "ereturnPressed"
QT_MOC_LITERAL(91, 1127, 16), // "eeditingFinished"
QT_MOC_LITERAL(92, 1144, 17) // "eselectionChanged"

    },
    "ActionReceiver\0ActionTriggered\0\0act\0"
    "tritemPressed\0QTreeWidgetItem*\0item\0"
    "column\0tritemClicked\0tritemDoubleClicked\0"
    "tritemActivated\0tritemEntered\0"
    "tritemChanged\0tritemExpanded\0"
    "tritemCollapsed\0trcurrentItemChanged\0"
    "current\0previous\0tritemSelectionChanged\0"
    "btnclicked\0checked\0btntoggled\0btnpressed\0"
    "btnreleased\0onFinish\0res\0onAccept\0"
    "onReject\0QSCN_SELCHANGED\0yes\0"
    "SCN_AUTOCCANCELLED\0SCN_AUTOCCHARDELETED\0"
    "SCN_AUTOCCOMPLETED\0const char*\0selection\0"
    "position\0ch\0method\0SCN_AUTOCSELECTION\0"
    "SCEN_CHANGE\0SCN_CALLTIPCLICK\0direction\0"
    "SCN_CHARADDED\0charadded\0SCN_DOUBLECLICK\0"
    "line\0modifiers\0SCN_DWELLEND\0x\0y\0"
    "SCN_DWELLSTART\0SCN_FOCUSIN\0SCN_FOCUSOUT\0"
    "SCN_HOTSPOTCLICK\0SCN_HOTSPOTDOUBLECLICK\0"
    "SCN_HOTSPOTRELEASECLICK\0SCN_INDICATORCLICK\0"
    "SCN_INDICATORRELEASE\0SCN_MACRORECORD\0"
    "msg\0wparam\0lparam\0SCN_MARGINCLICK\0"
    "margin\0SCN_MARGINRIGHTCLICK\0SCN_MODIFIED\0"
    "modType\0text\0length\0linesAdded\0"
    "foldLevelNow\0foldLevelPrev\0token\0"
    "annotationLinesAdded\0SCN_MODIFYATTEMPTRO\0"
    "SCN_NEEDSHOWN\0SCN_PAINTED\0SCN_SAVEPOINTLEFT\0"
    "SCN_SAVEPOINTREACHED\0SCN_STYLENEEDED\0"
    "SCN_UPDATEUI\0updated\0SCN_USERLISTSELECTION\0"
    "SCN_ZOOM\0etextChanged\0str\0etextEdited\0"
    "ecursorPositionChanged\0a\0b\0ereturnPressed\0"
    "eeditingFinished\0eselectionChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ActionReceiver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      57,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  299,    2, 0x08 /* Private */,
       4,    2,  302,    2, 0x08 /* Private */,
       8,    2,  307,    2, 0x08 /* Private */,
       9,    2,  312,    2, 0x08 /* Private */,
      10,    2,  317,    2, 0x08 /* Private */,
      11,    2,  322,    2, 0x08 /* Private */,
      12,    2,  327,    2, 0x08 /* Private */,
      13,    1,  332,    2, 0x08 /* Private */,
      14,    1,  335,    2, 0x08 /* Private */,
      15,    2,  338,    2, 0x08 /* Private */,
      18,    0,  343,    2, 0x08 /* Private */,
      19,    1,  344,    2, 0x08 /* Private */,
      21,    1,  347,    2, 0x08 /* Private */,
      22,    0,  350,    2, 0x08 /* Private */,
      23,    0,  351,    2, 0x08 /* Private */,
      24,    1,  352,    2, 0x08 /* Private */,
      26,    0,  355,    2, 0x08 /* Private */,
      27,    0,  356,    2, 0x08 /* Private */,
      28,    1,  357,    2, 0x08 /* Private */,
      30,    0,  360,    2, 0x08 /* Private */,
      31,    0,  361,    2, 0x08 /* Private */,
      32,    4,  362,    2, 0x08 /* Private */,
      38,    4,  371,    2, 0x08 /* Private */,
      38,    2,  380,    2, 0x08 /* Private */,
      39,    0,  385,    2, 0x08 /* Private */,
      40,    1,  386,    2, 0x08 /* Private */,
      42,    1,  389,    2, 0x08 /* Private */,
      44,    3,  392,    2, 0x08 /* Private */,
      47,    3,  399,    2, 0x08 /* Private */,
      50,    3,  406,    2, 0x08 /* Private */,
      51,    0,  413,    2, 0x08 /* Private */,
      52,    0,  414,    2, 0x08 /* Private */,
      53,    2,  415,    2, 0x08 /* Private */,
      54,    2,  420,    2, 0x08 /* Private */,
      55,    2,  425,    2, 0x08 /* Private */,
      56,    2,  430,    2, 0x08 /* Private */,
      57,    2,  435,    2, 0x08 /* Private */,
      58,    3,  440,    2, 0x08 /* Private */,
      62,    3,  447,    2, 0x08 /* Private */,
      64,    3,  454,    2, 0x08 /* Private */,
      65,   10,  461,    2, 0x08 /* Private */,
      74,    0,  482,    2, 0x08 /* Private */,
      75,    2,  483,    2, 0x08 /* Private */,
      76,    0,  488,    2, 0x08 /* Private */,
      77,    0,  489,    2, 0x08 /* Private */,
      78,    0,  490,    2, 0x08 /* Private */,
      79,    1,  491,    2, 0x08 /* Private */,
      80,    1,  494,    2, 0x08 /* Private */,
      82,    4,  497,    2, 0x08 /* Private */,
      82,    2,  506,    2, 0x08 /* Private */,
      83,    0,  511,    2, 0x08 /* Private */,
      84,    1,  512,    2, 0x08 /* Private */,
      86,    1,  515,    2, 0x08 /* Private */,
      87,    2,  518,    2, 0x08 /* Private */,
      90,    0,  523,    2, 0x08 /* Private */,
      91,    0,  524,    2, 0x08 /* Private */,
      92,    0,  525,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QObjectStar,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,   16,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 33, QMetaType::Int, QMetaType::Int, QMetaType::Int,   34,   35,   36,   37,
    QMetaType::Void, 0x80000000 | 33, QMetaType::Int, QMetaType::Int, QMetaType::Int,   34,   35,   36,   37,
    QMetaType::Void, 0x80000000 | 33, QMetaType::Int,   34,   35,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   41,
    QMetaType::Void, QMetaType::Int,   43,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   35,   45,   46,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   35,   48,   49,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   35,   48,   49,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   35,   46,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   35,   46,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   35,   46,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   35,   46,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   35,   46,
    QMetaType::Void, QMetaType::UInt, QMetaType::ULong, QMetaType::VoidStar,   59,   60,   61,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   35,   46,   63,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   35,   46,   63,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 33, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   35,   66,   67,   68,   69,   45,   70,   71,   72,   73,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   35,   68,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,   81,
    QMetaType::Void, 0x80000000 | 33, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 33, QMetaType::Int,   67,   68,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   85,
    QMetaType::Void, QMetaType::QString,   85,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   88,   89,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ActionReceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ActionReceiver *_t = static_cast<ActionReceiver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->ActionTriggered((*reinterpret_cast< QObject*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->tritemPressed((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->tritemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->tritemDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->tritemActivated((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->tritemEntered((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->tritemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->tritemExpanded((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->tritemCollapsed((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 9: _t->trcurrentItemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        case 10: _t->tritemSelectionChanged(); break;
        case 11: _t->btnclicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->btntoggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->btnpressed(); break;
        case 14: _t->btnreleased(); break;
        case 15: _t->onFinish((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->onAccept(); break;
        case 17: _t->onReject(); break;
        case 18: _t->QSCN_SELCHANGED((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->SCN_AUTOCCANCELLED(); break;
        case 20: _t->SCN_AUTOCCHARDELETED(); break;
        case 21: _t->SCN_AUTOCCOMPLETED((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 22: _t->SCN_AUTOCSELECTION((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 23: _t->SCN_AUTOCSELECTION((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 24: _t->SCEN_CHANGE(); break;
        case 25: _t->SCN_CALLTIPCLICK((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->SCN_CHARADDED((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->SCN_DOUBLECLICK((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 28: _t->SCN_DWELLEND((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 29: _t->SCN_DWELLSTART((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 30: _t->SCN_FOCUSIN(); break;
        case 31: _t->SCN_FOCUSOUT(); break;
        case 32: _t->SCN_HOTSPOTCLICK((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 33: _t->SCN_HOTSPOTDOUBLECLICK((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 34: _t->SCN_HOTSPOTRELEASECLICK((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 35: _t->SCN_INDICATORCLICK((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 36: _t->SCN_INDICATORRELEASE((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 37: _t->SCN_MACRORECORD((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< ulong(*)>(_a[2])),(*reinterpret_cast< void*(*)>(_a[3]))); break;
        case 38: _t->SCN_MARGINCLICK((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 39: _t->SCN_MARGINRIGHTCLICK((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 40: _t->SCN_MODIFIED((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const char*(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10]))); break;
        case 41: _t->SCN_MODIFYATTEMPTRO(); break;
        case 42: _t->SCN_NEEDSHOWN((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 43: _t->SCN_PAINTED(); break;
        case 44: _t->SCN_SAVEPOINTLEFT(); break;
        case 45: _t->SCN_SAVEPOINTREACHED(); break;
        case 46: _t->SCN_STYLENEEDED((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 47: _t->SCN_UPDATEUI((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 48: _t->SCN_USERLISTSELECTION((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 49: _t->SCN_USERLISTSELECTION((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 50: _t->SCN_ZOOM(); break;
        case 51: _t->etextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 52: _t->etextEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 53: _t->ecursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 54: _t->ereturnPressed(); break;
        case 55: _t->eeditingFinished(); break;
        case 56: _t->eselectionChanged(); break;
        default: ;
        }
    }
}

const QMetaObject ActionReceiver::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ActionReceiver.data,
      qt_meta_data_ActionReceiver,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ActionReceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ActionReceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ActionReceiver.stringdata0))
        return static_cast<void*>(const_cast< ActionReceiver*>(this));
    return QObject::qt_metacast(_clname);
}

int ActionReceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 57)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 57;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 57)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 57;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

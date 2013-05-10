/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon Apr 12 16:55:06 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      38,   11,   11,   11, 0x08,
      83,   11,   11,   11, 0x08,
     114,  106,   11,   11, 0x08,
     154,  106,   11,   11, 0x08,
     192,   11,   11,   11, 0x08,
     218,   11,   11,   11, 0x08,
     259,   11,   11,   11, 0x08,
     298,   11,   11,   11, 0x08,
     344,  338,   11,   11, 0x08,
     382,  338,   11,   11, 0x08,
     419,   11,   11,   11, 0x08,
     455,   11,   11,   11, 0x08,
     490,   11,   11,   11, 0x08,
     535,   11,   11,   11, 0x08,
     571,   11,   11,   11, 0x08,
     602,   11,   11,   11, 0x08,
     647,   11,   11,   11, 0x08,
     684,   11,   11,   11, 0x08,
     713,   11,   11,   11, 0x08,
     743,   11,   11,   11, 0x08,
     769,   11,   11,   11, 0x08,
     794,   11,   11,   11, 0x08,
     817,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_pushButton_3_clicked()\0"
    "on_pushButton_addRectangleToRegion_clicked()\0"
    "on_SaveAct_triggered()\0checked\0"
    "on_radioButton_DrawGlyphs_toggled(bool)\0"
    "on_radioButton_DrawText_toggled(bool)\0"
    "on_pushButton_2_clicked()\0"
    "on_checkBox_Underlined_stateChanged(int)\0"
    "on_checkBox_Stricken_stateChanged(int)\0"
    "on_checkBox_Overlined_stateChanged(int)\0"
    "value\0on_dial_Orientation_valueChanged(int)\0"
    "on_dial_Escapement_valueChanged(int)\0"
    "on_spinBox_Weight_valueChanged(int)\0"
    "on_spinBox_Width_valueChanged(int)\0"
    "on_textField_TextItself_textChanged(QString)\0"
    "on_spinBox_Height_valueChanged(int)\0"
    "on_ChangeColorButton_clicked()\0"
    "on_fontComboBox_currentIndexChanged(QString)\0"
    "on_fontComboBox_textChanged(QString)\0"
    "on_normalSizeAct_triggered()\0"
    "on_fitToWindowAct_triggered()\0"
    "on_zoomOutAct_triggered()\0"
    "on_zoomInAct_triggered()\0"
    "on_openAct_triggered()\0on_pushButton_clicked()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButton_3_clicked(); break;
        case 1: on_pushButton_addRectangleToRegion_clicked(); break;
        case 2: on_SaveAct_triggered(); break;
        case 3: on_radioButton_DrawGlyphs_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: on_radioButton_DrawText_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: on_pushButton_2_clicked(); break;
        case 6: on_checkBox_Underlined_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: on_checkBox_Stricken_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: on_checkBox_Overlined_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: on_dial_Orientation_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: on_dial_Escapement_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: on_spinBox_Weight_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: on_spinBox_Width_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: on_textField_TextItself_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: on_spinBox_Height_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: on_ChangeColorButton_clicked(); break;
        case 16: on_fontComboBox_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: on_fontComboBox_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: on_normalSizeAct_triggered(); break;
        case 19: on_fitToWindowAct_triggered(); break;
        case 20: on_zoomOutAct_triggered(); break;
        case 21: on_zoomInAct_triggered(); break;
        case 22: on_openAct_triggered(); break;
        case 23: on_pushButton_clicked(); break;
        default: ;
        }
        _id -= 24;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

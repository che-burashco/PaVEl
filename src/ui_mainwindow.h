/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *openAct;
    QAction *exitAct;
    QAction *zoomInAct;
    QAction *zoomOutAct;
    QAction *fitToWindowAct;
    QAction *normalSizeAct;
    QAction *SaveAct;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QToolBox *toolBox_2;
    QWidget *page_3;
    QHBoxLayout *horizontalLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_2;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QFontComboBox *fontComboBox;
    QPushButton *ChangeColorButton;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QSpinBox *spinBox_Height;
    QLabel *label_7;
    QSpinBox *spinBox_Width;
    QLabel *label_10;
    QSpinBox *spinBox_Weight;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_11;
    QCheckBox *checkBox_Overlined;
    QCheckBox *checkBox_Stricken;
    QCheckBox *checkBox_Underlined;
    QVBoxLayout *verticalLayout_10;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_8;
    QDial *dial_Escapement;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_9;
    QDial *dial_Orientation;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QVBoxLayout *verticalLayout_7;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_5;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_12;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_11;
    QLineEdit *lineEdit_rectangleX;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_12;
    QLineEdit *lineEdit_rectangleY;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_13;
    QLineEdit *lineEdit_rectangleWidth;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_14;
    QLineEdit *lineEdit_rectangleHeight;
    QVBoxLayout *verticalLayout_14;
    QPushButton *pushButton_addRectangleToRegion;
    QListView *listView;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *textField_TextItself;
    QHBoxLayout *horizontalLayout_10;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_9;
    QRadioButton *radioButton_DrawText;
    QRadioButton *radioButton_DrawGlyphs;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_4;
    QLineEdit *xField;
    QLabel *label_3;
    QLineEdit *yField;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuPanguin;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(623, 795);
        MainWindow->setMinimumSize(QSize(0, 0));
        openAct = new QAction(MainWindow);
        openAct->setObjectName(QStringLiteral("openAct"));
        exitAct = new QAction(MainWindow);
        exitAct->setObjectName(QStringLiteral("exitAct"));
        zoomInAct = new QAction(MainWindow);
        zoomInAct->setObjectName(QStringLiteral("zoomInAct"));
        zoomInAct->setEnabled(false);
        zoomOutAct = new QAction(MainWindow);
        zoomOutAct->setObjectName(QStringLiteral("zoomOutAct"));
        zoomOutAct->setEnabled(false);
        fitToWindowAct = new QAction(MainWindow);
        fitToWindowAct->setObjectName(QStringLiteral("fitToWindowAct"));
        fitToWindowAct->setCheckable(true);
        fitToWindowAct->setEnabled(false);
        normalSizeAct = new QAction(MainWindow);
        normalSizeAct->setObjectName(QStringLiteral("normalSizeAct"));
        normalSizeAct->setEnabled(false);
        SaveAct = new QAction(MainWindow);
        SaveAct->setObjectName(QStringLiteral("SaveAct"));
        verticalLayoutWidget = new QWidget(MainWindow);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        toolBox_2 = new QToolBox(verticalLayoutWidget);
        toolBox_2->setObjectName(QStringLiteral("toolBox_2"));
        toolBox_2->setMinimumSize(QSize(500, 500));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setGeometry(QRect(0, 0, 605, 446));
        horizontalLayout_3 = new QHBoxLayout(page_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        scrollArea = new QScrollArea(page_3);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMinimumSize(QSize(0, 0));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 585, 426));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 0));
        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 600, 450));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setScaledContents(true);
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_3->addWidget(scrollArea);

        toolBox_2->addItem(page_3, QStringLiteral("Output window"));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        page_4->setGeometry(QRect(0, 0, 605, 446));
        verticalLayout_3 = new QVBoxLayout(page_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(page_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        fontComboBox = new QFontComboBox(page_4);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        fontComboBox->setEditable(true);

        horizontalLayout_5->addWidget(fontComboBox);

        ChangeColorButton = new QPushButton(page_4);
        ChangeColorButton->setObjectName(QStringLiteral("ChangeColorButton"));
        QPalette palette;
        QBrush brush(QColor(170, 255, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        ChangeColorButton->setPalette(palette);
        ChangeColorButton->setDefault(false);

        horizontalLayout_5->addWidget(ChangeColorButton);


        verticalLayout_8->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(page_4);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        spinBox_Height = new QSpinBox(page_4);
        spinBox_Height->setObjectName(QStringLiteral("spinBox_Height"));
        spinBox_Height->setMaximum(2000);
        spinBox_Height->setValue(14);

        horizontalLayout_6->addWidget(spinBox_Height);

        label_7 = new QLabel(page_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        spinBox_Width = new QSpinBox(page_4);
        spinBox_Width->setObjectName(QStringLiteral("spinBox_Width"));
        spinBox_Width->setMaximum(2000);

        horizontalLayout_6->addWidget(spinBox_Width);

        label_10 = new QLabel(page_4);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_6->addWidget(label_10);

        spinBox_Weight = new QSpinBox(page_4);
        spinBox_Weight->setObjectName(QStringLiteral("spinBox_Weight"));
        spinBox_Weight->setMaximum(1000);

        horizontalLayout_6->addWidget(spinBox_Weight);


        verticalLayout_8->addLayout(horizontalLayout_6);


        horizontalLayout_9->addLayout(verticalLayout_8);

        groupBox_2 = new QGroupBox(page_4);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_11 = new QVBoxLayout(groupBox_2);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        checkBox_Overlined = new QCheckBox(groupBox_2);
        checkBox_Overlined->setObjectName(QStringLiteral("checkBox_Overlined"));

        verticalLayout_11->addWidget(checkBox_Overlined);

        checkBox_Stricken = new QCheckBox(groupBox_2);
        checkBox_Stricken->setObjectName(QStringLiteral("checkBox_Stricken"));

        verticalLayout_11->addWidget(checkBox_Stricken);

        checkBox_Underlined = new QCheckBox(groupBox_2);
        checkBox_Underlined->setObjectName(QStringLiteral("checkBox_Underlined"));

        verticalLayout_11->addWidget(checkBox_Underlined);


        horizontalLayout_9->addWidget(groupBox_2);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));

        horizontalLayout_9->addLayout(verticalLayout_10);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_8 = new QLabel(page_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_4->addWidget(label_8);

        dial_Escapement = new QDial(page_4);
        dial_Escapement->setObjectName(QStringLiteral("dial_Escapement"));
        dial_Escapement->setMaximum(3600);
        dial_Escapement->setOrientation(Qt::Horizontal);
        dial_Escapement->setInvertedAppearance(false);

        verticalLayout_4->addWidget(dial_Escapement);


        horizontalLayout_7->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_9 = new QLabel(page_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_5->addWidget(label_9);

        dial_Orientation = new QDial(page_4);
        dial_Orientation->setObjectName(QStringLiteral("dial_Orientation"));
        dial_Orientation->setMaximum(3600);

        verticalLayout_5->addWidget(dial_Orientation);


        horizontalLayout_7->addLayout(verticalLayout_5);

        groupBox = new QGroupBox(page_4);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout_2->addWidget(radioButton);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout_2->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        verticalLayout_2->addWidget(radioButton_4);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout_7->addWidget(radioButton_2);

        radioButton_6 = new QRadioButton(groupBox);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));

        verticalLayout_7->addWidget(radioButton_6);

        radioButton_5 = new QRadioButton(groupBox);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));

        verticalLayout_7->addWidget(radioButton_5);


        horizontalLayout_2->addLayout(verticalLayout_7);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        horizontalLayout_7->addWidget(groupBox);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        groupBox_4 = new QGroupBox(page_4);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_13 = new QHBoxLayout(groupBox_4);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_14->addWidget(label_11);

        lineEdit_rectangleX = new QLineEdit(groupBox_4);
        lineEdit_rectangleX->setObjectName(QStringLiteral("lineEdit_rectangleX"));
        lineEdit_rectangleX->setMaximumSize(QSize(75, 16777215));
        lineEdit_rectangleX->setInputMethodHints(Qt::ImhDigitsOnly);

        horizontalLayout_14->addWidget(lineEdit_rectangleX);


        verticalLayout_12->addLayout(horizontalLayout_14);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_16->addWidget(label_12);

        lineEdit_rectangleY = new QLineEdit(groupBox_4);
        lineEdit_rectangleY->setObjectName(QStringLiteral("lineEdit_rectangleY"));
        lineEdit_rectangleY->setMaximumSize(QSize(75, 16777215));
        lineEdit_rectangleY->setInputMethodHints(Qt::ImhDigitsOnly);

        horizontalLayout_16->addWidget(lineEdit_rectangleY);


        verticalLayout_12->addLayout(horizontalLayout_16);


        horizontalLayout_13->addLayout(verticalLayout_12);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_17->addWidget(label_13);

        lineEdit_rectangleWidth = new QLineEdit(groupBox_4);
        lineEdit_rectangleWidth->setObjectName(QStringLiteral("lineEdit_rectangleWidth"));
        lineEdit_rectangleWidth->setMaximumSize(QSize(75, 16777215));
        lineEdit_rectangleWidth->setInputMethodHints(Qt::ImhDigitsOnly);

        horizontalLayout_17->addWidget(lineEdit_rectangleWidth);


        verticalLayout_13->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_18->addWidget(label_14);

        lineEdit_rectangleHeight = new QLineEdit(groupBox_4);
        lineEdit_rectangleHeight->setObjectName(QStringLiteral("lineEdit_rectangleHeight"));
        lineEdit_rectangleHeight->setMaximumSize(QSize(75, 16777215));
        lineEdit_rectangleHeight->setInputMethodHints(Qt::ImhDigitsOnly);

        horizontalLayout_18->addWidget(lineEdit_rectangleHeight);


        verticalLayout_13->addLayout(horizontalLayout_18);


        horizontalLayout_13->addLayout(verticalLayout_13);


        horizontalLayout_12->addWidget(groupBox_4);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        pushButton_addRectangleToRegion = new QPushButton(page_4);
        pushButton_addRectangleToRegion->setObjectName(QStringLiteral("pushButton_addRectangleToRegion"));

        verticalLayout_14->addWidget(pushButton_addRectangleToRegion);


        horizontalLayout_12->addLayout(verticalLayout_14);

        listView = new QListView(page_4);
        listView->setObjectName(QStringLiteral("listView"));

        horizontalLayout_12->addWidget(listView);


        verticalLayout_3->addLayout(horizontalLayout_12);

        pushButton_3 = new QPushButton(page_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_3->addWidget(pushButton_3);

        toolBox_2->addItem(page_4, QStringLiteral("Text settings"));

        verticalLayout->addWidget(toolBox_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        scrollArea_2 = new QScrollArea(verticalLayoutWidget);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 297, 246));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout->addWidget(scrollArea_2);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        textField_TextItself = new QLineEdit(verticalLayoutWidget);
        textField_TextItself->setObjectName(QStringLiteral("textField_TextItself"));

        horizontalLayout_4->addWidget(textField_TextItself);


        verticalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        groupBox_3 = new QGroupBox(verticalLayoutWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_9 = new QVBoxLayout(groupBox_3);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        radioButton_DrawText = new QRadioButton(groupBox_3);
        radioButton_DrawText->setObjectName(QStringLiteral("radioButton_DrawText"));
        radioButton_DrawText->setChecked(true);

        verticalLayout_9->addWidget(radioButton_DrawText);

        radioButton_DrawGlyphs = new QRadioButton(groupBox_3);
        radioButton_DrawGlyphs->setObjectName(QStringLiteral("radioButton_DrawGlyphs"));
        radioButton_DrawGlyphs->setEnabled(false);

        verticalLayout_9->addWidget(radioButton_DrawGlyphs);


        horizontalLayout_10->addWidget(groupBox_3);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_10->addWidget(pushButton_2);


        verticalLayout_6->addLayout(horizontalLayout_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_8->addWidget(label_4);

        xField = new QLineEdit(verticalLayoutWidget);
        xField->setObjectName(QStringLiteral("xField"));
        xField->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_8->addWidget(xField);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_8->addWidget(label_3);

        yField = new QLineEdit(verticalLayoutWidget);
        yField->setObjectName(QStringLiteral("yField"));
        yField->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_8->addWidget(yField);


        verticalLayout_6->addLayout(horizontalLayout_8);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_6->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout_6);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(verticalLayoutWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 623, 21));
        menuPanguin = new QMenu(menuBar);
        menuPanguin->setObjectName(QStringLiteral("menuPanguin"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuPanguin->menuAction());
        menuBar->addAction(menu->menuAction());
        menuPanguin->addAction(openAct);
        menuPanguin->addAction(SaveAct);
        menuPanguin->addAction(exitAct);
        menu->addAction(zoomInAct);
        menu->addAction(zoomOutAct);
        menu->addAction(normalSizeAct);
        menu->addSeparator();
        menu->addAction(fitToWindowAct);

        retranslateUi(MainWindow);

        toolBox_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PaVEl - PAnguin Visualizer ELement", 0));
        openAct->setText(QApplication::translate("MainWindow", "Open", 0));
        exitAct->setText(QApplication::translate("MainWindow", "Quit", 0));
        zoomInAct->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\261\320\273\320\270\320\267\320\270\321\202\321\214", 0));
        zoomOutAct->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        fitToWindowAct->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\276\320\263\320\275\320\260\321\202\321\214 \320\277\320\276\320\264 \321\200\320\260\320\267\320\274\320\265\321\200 \320\276\320\272\320\275\320\260", 0));
        normalSizeAct->setText(QApplication::translate("MainWindow", "\320\235\320\276\321\200\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \321\200\320\260\320\267\320\274\320\265\321\200", 0));
        SaveAct->setText(QApplication::translate("MainWindow", "Save As", 0));
        label_2->setText(QString());
        toolBox_2->setItemText(toolBox_2->indexOf(page_3), QApplication::translate("MainWindow", "Output window", 0));
        label_6->setText(QApplication::translate("MainWindow", "Font", 0));
        ChangeColorButton->setText(QApplication::translate("MainWindow", "Change text color", 0));
        label_5->setText(QApplication::translate("MainWindow", "Font Height", 0));
        label_7->setText(QApplication::translate("MainWindow", "Font Width", 0));
        label_10->setText(QApplication::translate("MainWindow", "Font Weight", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Markup settings", 0));
        checkBox_Overlined->setText(QApplication::translate("MainWindow", "Overlined", 0));
        checkBox_Stricken->setText(QApplication::translate("MainWindow", "Stricken", 0));
        checkBox_Underlined->setText(QApplication::translate("MainWindow", "Underlined", 0));
        label_8->setText(QApplication::translate("MainWindow", "Escapement Angle", 0));
        label_9->setText(QApplication::translate("MainWindow", "Orientation Angle", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Reference point position", 0));
        radioButton->setText(QApplication::translate("MainWindow", "Left", 0));
        radioButton_3->setText(QApplication::translate("MainWindow", "Middle", 0));
        radioButton_4->setText(QApplication::translate("MainWindow", "Right", 0));
        radioButton_2->setText(QApplication::translate("MainWindow", "Upper", 0));
        radioButton_6->setText(QApplication::translate("MainWindow", "Baseline", 0));
        radioButton_5->setText(QApplication::translate("MainWindow", "Lower", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "GroupBox", 0));
        label_11->setText(QApplication::translate("MainWindow", "X", 0));
        lineEdit_rectangleX->setInputMask(QString());
        label_12->setText(QApplication::translate("MainWindow", "Y", 0));
        lineEdit_rectangleY->setInputMask(QString());
        label_13->setText(QApplication::translate("MainWindow", "Width", 0));
        lineEdit_rectangleWidth->setInputMask(QString());
        label_14->setText(QApplication::translate("MainWindow", "Height", 0));
        lineEdit_rectangleHeight->setInputMask(QString());
        pushButton_addRectangleToRegion->setText(QApplication::translate("MainWindow", "Add to region", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "PushButton", 0));
        toolBox_2->setItemText(toolBox_2->indexOf(page_4), QApplication::translate("MainWindow", "Text settings", 0));
        label->setText(QApplication::translate("MainWindow", "Text", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "GroupBox", 0));
        radioButton_DrawText->setText(QApplication::translate("MainWindow", "Text", 0));
        radioButton_DrawGlyphs->setText(QApplication::translate("MainWindow", "Glyphs", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Load Glyph Indexes", 0));
        label_4->setText(QApplication::translate("MainWindow", "X", 0));
        xField->setText(QApplication::translate("MainWindow", "0", 0));
        label_3->setText(QApplication::translate("MainWindow", "Y", 0));
        yField->setText(QApplication::translate("MainWindow", "0", 0));
        pushButton->setText(QApplication::translate("MainWindow", "DRAW", 0));
        menuPanguin->setTitle(QApplication::translate("MainWindow", "File", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\320\222\320\270\320\264", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

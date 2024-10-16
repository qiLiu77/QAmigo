/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionload;
    QAction *actionLoad_Plugin;
    QAction *actionEnglish;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonOpen;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabMain;
    QWidget *tabConnection;
    QGroupBox *groupSerialProperties;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_2;
    QLabel *labelPort;
    QComboBox *comboPorts;
    QLabel *labelBaudRate;
    QComboBox *comboBaudrate;
    QLabel *labelDataBits;
    QComboBox *comboDataBits;
    QLabel *labelParity;
    QComboBox *comboParity;
    QLabel *labelStopBits;
    QComboBox *comboStopBits;
    QLabel *labelFlowControl;
    QComboBox *comboFlowControl;
    QPushButton *buttonRefreshPorts;
    QMenuBar *menuBar;
    QMenu *menuPlugins;
    QMenu *menuLanguage;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 800);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/com_128px.ico"), QSize(), QIcon::Normal, QIcon::On);
        MainWindow->setWindowIcon(icon);
        actionload = new QAction(MainWindow);
        actionload->setObjectName("actionload");
        actionLoad_Plugin = new QAction(MainWindow);
        actionLoad_Plugin->setObjectName("actionLoad_Plugin");
        actionEnglish = new QAction(MainWindow);
        actionEnglish->setObjectName("actionEnglish");
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        buttonOpen = new QPushButton(centralWidget);
        buttonOpen->setObjectName("buttonOpen");

        horizontalLayout->addWidget(buttonOpen);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

        tabMain = new QTabWidget(centralWidget);
        tabMain->setObjectName("tabMain");
        tabConnection = new QWidget();
        tabConnection->setObjectName("tabConnection");
        groupSerialProperties = new QGroupBox(tabConnection);
        groupSerialProperties->setObjectName("groupSerialProperties");
        groupSerialProperties->setGeometry(QRect(20, 10, 211, 231));
        verticalLayout = new QVBoxLayout(groupSerialProperties);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName("formLayout_2");
        labelPort = new QLabel(groupSerialProperties);
        labelPort->setObjectName("labelPort");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelPort);

        comboPorts = new QComboBox(groupSerialProperties);
        comboPorts->setObjectName("comboPorts");
        comboPorts->setEditable(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, comboPorts);

        labelBaudRate = new QLabel(groupSerialProperties);
        labelBaudRate->setObjectName("labelBaudRate");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelBaudRate);

        comboBaudrate = new QComboBox(groupSerialProperties);
        comboBaudrate->setObjectName("comboBaudrate");
        comboBaudrate->setEditable(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, comboBaudrate);

        labelDataBits = new QLabel(groupSerialProperties);
        labelDataBits->setObjectName("labelDataBits");

        formLayout_2->setWidget(2, QFormLayout::LabelRole, labelDataBits);

        comboDataBits = new QComboBox(groupSerialProperties);
        comboDataBits->setObjectName("comboDataBits");

        formLayout_2->setWidget(2, QFormLayout::FieldRole, comboDataBits);

        labelParity = new QLabel(groupSerialProperties);
        labelParity->setObjectName("labelParity");
        labelParity->setFrameShape(QFrame::Shape::NoFrame);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, labelParity);

        comboParity = new QComboBox(groupSerialProperties);
        comboParity->setObjectName("comboParity");

        formLayout_2->setWidget(3, QFormLayout::FieldRole, comboParity);

        labelStopBits = new QLabel(groupSerialProperties);
        labelStopBits->setObjectName("labelStopBits");

        formLayout_2->setWidget(4, QFormLayout::LabelRole, labelStopBits);

        comboStopBits = new QComboBox(groupSerialProperties);
        comboStopBits->setObjectName("comboStopBits");

        formLayout_2->setWidget(4, QFormLayout::FieldRole, comboStopBits);

        labelFlowControl = new QLabel(groupSerialProperties);
        labelFlowControl->setObjectName("labelFlowControl");

        formLayout_2->setWidget(5, QFormLayout::LabelRole, labelFlowControl);

        comboFlowControl = new QComboBox(groupSerialProperties);
        comboFlowControl->setObjectName("comboFlowControl");

        formLayout_2->setWidget(5, QFormLayout::FieldRole, comboFlowControl);


        verticalLayout->addLayout(formLayout_2);

        buttonRefreshPorts = new QPushButton(tabConnection);
        buttonRefreshPorts->setObjectName("buttonRefreshPorts");
        buttonRefreshPorts->setGeometry(QRect(250, 30, 89, 25));
        tabMain->addTab(tabConnection, QString());

        gridLayout->addWidget(tabMain, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1200, 18));
        menuPlugins = new QMenu(menuBar);
        menuPlugins->setObjectName("menuPlugins");
        menuLanguage = new QMenu(menuBar);
        menuLanguage->setObjectName("menuLanguage");
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuPlugins->menuAction());
        menuBar->addAction(menuLanguage->menuAction());
        menuPlugins->addAction(actionLoad_Plugin);
        menuLanguage->addAction(actionEnglish);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        tabMain->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QAmigo", nullptr));
        actionload->setText(QCoreApplication::translate("MainWindow", "load", nullptr));
        actionLoad_Plugin->setText(QCoreApplication::translate("MainWindow", "Load Plugin", nullptr));
        actionEnglish->setText(QCoreApplication::translate("MainWindow", "English", nullptr));
        buttonOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        groupSerialProperties->setTitle(QCoreApplication::translate("MainWindow", "Serial Properties", nullptr));
        labelPort->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        labelBaudRate->setText(QCoreApplication::translate("MainWindow", "BaudRate", nullptr));
        labelDataBits->setText(QCoreApplication::translate("MainWindow", "Data Bits", nullptr));
        labelParity->setText(QCoreApplication::translate("MainWindow", "Parity", nullptr));
        labelStopBits->setText(QCoreApplication::translate("MainWindow", "Stop Bits", nullptr));
        labelFlowControl->setText(QCoreApplication::translate("MainWindow", "FlowControl", nullptr));
        buttonRefreshPorts->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        tabMain->setTabText(tabMain->indexOf(tabConnection), QCoreApplication::translate("MainWindow", "Connection Settings", nullptr));
        menuPlugins->setTitle(QCoreApplication::translate("MainWindow", "Plugins", nullptr));
        menuLanguage->setTitle(QCoreApplication::translate("MainWindow", "Language", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QWidget>
#include <QTimer>

#include "SimpleTab/serialsendbox.h"
#include "SimpleTab/tabcomsimple.h"
#include "tabplugininterface.h"
#include "AdvancedTab/tabadvanced.h"
#include "AdvancedTab/decoder.h"
#include "HeatMapTab/heatmaptab.h"
#include "BarChartTab/barcharttab.h"
#include "TrajectoryMapTab/trajectorymap.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void refreshPorts();
    void updatePluginConnection();
    void translateTo(QString locale);
    void retranslateUi();

signals:
    void switchToTab(int index);

public slots:
    void errorMessage(QString str);
    void openSerial();

private slots:
    void onButtonRefreshClicked();
    void onLoadPluginTriggered();
    void onDecodedDataReady(int id, QList<double> listValues);
    void onActionEnglishTriggered();
    void onActionChineseTriggered();

private:
    Ui::MainWindow *ui;
    SerialSendBox *sendBox;
    QIODevice *currentConnection;
    QSerialPort *port;
    TabCOMSimple *tabCOMSimple;
    TabAdvanced *tabAdvanced;
    Decoder *decoder;
    QList<TabPluginInterface *> listPlugins;
    QTranslator *translator;
    HeatMap *tabHeatMap;
    BarChart *tabBarChart;
    TrajectoryMap *tabTrajectoryMap;

    // QWidget interface
protected:
    void changeEvent(QEvent *event) override;
};

#endif // MAINWINDOW_H

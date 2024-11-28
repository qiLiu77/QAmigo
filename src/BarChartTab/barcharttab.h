#ifndef BARCHARTTAB_H
#define BARCHARTTAB_H

#include <QOpenGLWidget>
#include <QRadioButton>
#include <QtCharts>
#include <QVector>
#include <QMap>
#include <iostream>
#include <chrono>

namespace cr = std::chrono;

class BarChart : public QWidget
{
    Q_OBJECT
    enum class State
    {
        Waiting,
        Error,
        X,
        Y,
        XBase,
        YBase,
    };
    enum Axis
    {
        X,
        Y
    };
    enum Data
    {
        D,
        I,
        Q
    };

public:
    explicit BarChart(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent* event) override;

private:
    void reattachAxis(int i, int j);

    QRadioButton* axisSwitch[2], * dataSwitch[3];
    QLabel* maxTextEdit;
    int axisCheckedIndex = 0, dataCheckedIndex = 0;
    QChart* chart;
    QChartView* chartView;
    QLineSeries* lineSeries[2];
    QBarSeries* barSeries[2][3];
    QValueAxis* positive, * real, * bin[2];

    QVector<int16_t> avg[2], newestPacketPack[3];
    QVector<QPair<State, QVector<int16_t>>> valid;
    QQueue<QVector<int16_t>> base[2];

signals:

public slots:
    void onSerialDataReceived(const QByteArray& array);
    void setShouldRefresh(int index);
    void onRefresh();
};

#endif // BARCHARTTAB_H

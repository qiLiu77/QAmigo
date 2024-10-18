#ifndef GRAPHTAB_H
#define GRAPHTAB_H

#include <QOpenGLWidget>
#include <QPainter>
#include <QTextEdit>
#include <QVector>
#include <QPair>
#include <QTime>
#include <QFile>
#include <iostream>
#include <chrono>

class HeatMap : public QOpenGLWidget
{
    Q_OBJECT
    enum class State
    {
        Waiting,
        Error,
        SelfCapacity,
        MutualCapacity,
    };

public:
    explicit HeatMap(QWidget *parent = nullptr);

    bool shouldClearScreen = true;

protected:
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;

private:
    QTextEdit* stateTextEdit;

    QVector<QPair<State, QVector<int16_t>>> valid;
    QString prev;
    // std::chrono::high_resolution_clock clock;
    // decltype(clock.now()) p1, p2;
    // decltype(std::chrono::duration_cast<std::chrono::microseconds>(p1 - p1)) dur;

    void doPaint(QPainter* painter, uint8_t hue, int16_t data, const QPoint& topLeft, const QSize& size);

signals:

public slots:
    void onSerialDataReceived(const QByteArray &array);
    void setShouldRefresh(int index);
    void onRefresh();
};

#endif // GRAPHTAB_H

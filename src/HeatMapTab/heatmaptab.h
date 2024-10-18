#ifndef GRAPHTAB_H
#define GRAPHTAB_H

#include <QApplication>
#include <QOpenGLWidget>
#include <QScreen>
#include <QPainter>
#include <QTextEdit>
#include <QPushButton>
#include <QVector>
#include <QPair>
#include <QTime>
#include <QFile>
#include <QFileInfo>
#include <iostream>
#include <chrono>

class HeatMap : public QOpenGLWidget
{
    Q_OBJECT
    enum class State
    {
        Waiting,
        Error,
        SelfCapacitor,
        MutualCapacitor,
    };

public:
    explicit HeatMap(QWidget *parent = nullptr);

    bool shouldClearScreen = true;

protected:
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;

private:
    QTextEdit* stateTextEdit;
    QPushButton* screenshotButton;

    QVector<QPair<State, QVector<int16_t>>> valid;
    QVector<QVector<int16_t>> newestPacketPack, newestFrame;

    QString prev;
    QRect printArea;

    void doPaint(QPainter* painter, uint8_t hue, int16_t data, const QPoint& topLeft, const QSize& size);

signals:

public slots:
    void onSerialDataReceived(const QByteArray &array);
    void setShouldRefresh(int index);
    void onSaveScreen();
    void onRefresh();
};

#endif // GRAPHTAB_H

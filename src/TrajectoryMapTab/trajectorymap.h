#ifndef TRAJECTORYMAP_H
#define TRAJECTORYMAP_H

#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QLabel>
#include <tuple>
#include <QQueue>
#include <QTimer>
#include <QTime>
#include <QFile>
#include <QFileInfo>
#include <QPixmap>
#include <QMessageBox>

class TrajectoryMap : public QWidget
{
    Q_OBJECT
public:
    explicit TrajectoryMap(QWidget *parent = nullptr);

    bool shouldClearScreen = true;

protected:
    void paintEvent(QPaintEvent*) override;
    void keyPressEvent(QKeyEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private:
    QLabel* positionLabel;

    QQueue<std::tuple<bool, QPoint, uint16_t>> valid;
    QVector<QVector<uint16_t>> newestPacketPack;
    QPixmap saved;
    QPair<uint16_t, uint16_t> mouse;
    QPair<double, double> coil;

    bool isShowingOld = false, isSwitching = false;
    double widthScaler, heightScaler;

signals:

public slots:
    void onSerialDataReceived(const QByteArray &array);
    void setShouldRefresh(int index);
    void onRefresh();
};

#endif // TRAJECTORYMAP_H

#ifndef TRAJECTORYMAP_H
#define TRAJECTORYMAP_H

#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QLabel>
#include <tuple>
#include <QQueue>
#include <QTimer>
#include <QPixmap>

class TrajectoryMap : public QWidget
{
    Q_OBJECT
public:
    explicit TrajectoryMap(QWidget *parent = nullptr);

    bool shouldClearScreen = true;

protected:
    void paintEvent(QPaintEvent*) override;
    void keyPressEvent(QKeyEvent* event) override;

private:
    QLabel* statusLabel;

    QQueue<std::tuple<bool, QPoint, uint16_t>> valid;
    QPixmap saved;

    bool isShowingOld = false, isSwitching = false;

signals:

public slots:
    void onSerialDataReceived(const QByteArray &array);
    void setShouldRefresh(int index);
    void onRefresh();
};

#endif // TRAJECTORYMAP_H

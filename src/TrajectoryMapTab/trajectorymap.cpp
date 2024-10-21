#include "trajectorymap.h"

#define PRESSURE_MAX 0x1FFF
#define TR_PACKET_HEADER 't'
constexpr QPoint NO_PREVIOUS_POINT(0x7FFF, 0x7FFF);
constexpr QSize DATA_MAX(0x5750, 0x3690);

TrajectoryMap::TrajectoryMap(QWidget *parent)
    : QWidget{parent}
{
    // statusLabel = new QLabel(this);
    // statusLabel->move(10, 10);
    // statusLabel->setText("showing current");

    setFocusPolicy(Qt::StrongFocus);
    setFocus();

    setAttribute(Qt::WA_OpaquePaintEvent);
}

void TrajectoryMap::onSerialDataReceived(const QByteArray& packet)
{
    if(packet[0] != TR_PACKET_HEADER)
    {
        return;
    }
    assert((packet.size() - 1) % 6 == 0);
    int i = 1;
    while(i < packet.size())
    {
        auto xhigh = packet[i + 1],
             xlow  = packet[i],
             yhigh = packet[i + 3],
             ylow  = packet[i + 2],
             phigh = packet[i + 5],
             plow  = packet[i + 4];
        QPoint pt(DATA_MAX.width() - (xhigh << 8 | (uint8_t)xlow), DATA_MAX.height() - (yhigh << 8 | (uint8_t)ylow));
        bool v = pt.x() >> 15 & 1, o = pt.y() >> 15 & 1;
        if(!v)
        {
            continue;
        }
        pt.rx() &= 0x7FFF, pt.ry() &= 0x7FFF;
        valid.emplace_back(o, pt, phigh << 8 | (uint8_t)plow);

        i += 6;
    }

    assert(i == packet.size());
}

void TrajectoryMap::setShouldRefresh(int index)
{
    if(index != 5)
    {
        return;
    }
    shouldClearScreen = true;
    isShowingOld = false;
    saved = QPixmap();
}


void TrajectoryMap::onRefresh()
{
    update();
}

void TrajectoryMap::paintEvent(QPaintEvent*)
{
    const double widthScaler = static_cast<double>(width()) / DATA_MAX.width(),
                 heightScaler = static_cast<double>(height()) / DATA_MAX.height();

    QPainter painter(this);
    static QPointF last[2] = {NO_PREVIOUS_POINT, NO_PREVIOUS_POINT};

    if(isShowingOld)
    {
        valid.clear();
    }
    if(shouldClearScreen)
    {
        painter.setBrush(Qt::white);
        painter.drawRect(0, 0, width(), height());
        last[0] = last[1] = NO_PREVIOUS_POINT;
        shouldClearScreen = false;

        // user called clearscreen by pressing space
        if(!isSwitching)
        {
            saved = QPixmap();
        }
    }
    if(isSwitching)
    {
        auto g = geometry();
        auto now = QApplication::primaryScreen()->grabWindow(winId(), g.left(), g.top(), g.width(), g.height());
        painter.drawPixmap(0, 0, saved);
        saved = std::move(now);
        isSwitching = false;
    }

    while(!valid.empty())
    {
        bool o;
        QPointF pt;
        uint16_t p;
        std::tie(o, pt, p) = std::move(valid.front());
        valid.pop_front();
        if(p == 0)
        {
            last[o] = NO_PREVIOUS_POINT;
            continue;
        }

        pt.rx() *= widthScaler, pt.ry() *= heightScaler;
        //if(last[o] != NO_PREVIOUS_POINT)
        if(std::abs(last[o].x() - NO_PREVIOUS_POINT.x()) > 1e-6 ||
           std::abs(last[o].y() - NO_PREVIOUS_POINT.y()) > 1e-6)
        {
            painter.setPen({Qt::black, 3.0 * p / PRESSURE_MAX});
            painter.drawLine(last[o], pt);
        }
        last[o] = std::move(pt);
    }
}

void TrajectoryMap::keyPressEvent(QKeyEvent* event)
{
    //QString nextText, currentText;
    QPainter painter(this);

    switch(event->key())
    {
    case Qt::Key_S:
    {
        auto g = geometry();
        saved = QApplication::primaryScreen()->grabWindow(winId(), g.left(), g.top(), g.width(), g.height());
        assert(saved.save("data/export.png"));
        //currentText = "saved";
        //nextText = statusLabel->text();
        break;
    }
    case Qt::Key_R:
        isShowingOld = !isShowingOld;
        shouldClearScreen = true;
        isSwitching = true;
        //currentText = isShowingOld ? "showing old" : "restored";
        //nextText = isShowingOld ? "showing old" : "showing current";
        break;
    case Qt::Key_Space:
        shouldClearScreen = true;
    }

    update();
    QWidget::keyPressEvent(event);

    // statusLabel->setText(currentText);
    // auto* timer = new QTimer;
    // connect(timer, &QTimer::timeout, [=]()
    // {
    //     if(statusLabel->text() == currentText)
    //     {
    //         statusLabel->setText(nextText);
    //         statusLabel->adjustSize();
    //     }
    //     timer->stop();
    //     timer->deleteLater();
    // });
    // timer->start(2000);
}

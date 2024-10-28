#include "trajectorymap.h"
#include "combine.h"

#define PRESSURE_MAX 0x1FFF
#define TR_PACKET_HEADER 't'
#define X_COIL_NUM 52
#define Y_COIL_NUM 39
#define HEIGHT_RESERVED 30
#define INVALID_COIL -999.0
constexpr QPoint NO_PREVIOUS_POINT(0x7FFF, 0x7FFF);
constexpr QSize DATA_MAX(0x5750, 0x3690);

TrajectoryMap::TrajectoryMap(QWidget *parent)
    : QWidget{parent}
{
    // statusLabel = new QLabel(this);
    // statusLabel->move(10, 10);
    // statusLabel->setText("showing current");
    positionLabel = new QLabel(this);
    positionLabel->resize(300, HEIGHT_RESERVED - 6);

    setFocusPolicy(Qt::StrongFocus);
    setFocus();

    setMouseTracking(true);

    setAttribute(Qt::WA_OpaquePaintEvent);
}

void TrajectoryMap::onSerialDataReceived(const QByteArray& packet)
{
    if(packet[0] != TR_PACKET_HEADER)
    {
        return;
    }

    int i = 1;
    //ensure there are at least 6 bytes
    while(i + 6 <= packet.size())
    {
        auto x = combineToInt<2>(packet, i),
             y = combineToInt<2>(packet, i + 2),
             p = combineToInt<2>(packet, i + 4);
        QVector<uint16_t> arr;
        bool v = x >> 15 & 1, o = y >> 15 & 1;
        x &= 0x7FFF, y &= 0x7FFF;
        QPoint pt(DATA_MAX.width() - x, DATA_MAX.height() - y);
        int more = p >> (sizeof(p) * 8 - 3) & 0x7;

        //enxure there are at least 6 + more bytes
        if(i + 6 + more > packet.size())
        {
            goto error;
        }
        p &= PRESSURE_MAX;
        i += 6 + more * 2;
        if(!v)
        {
            continue;
        }
        valid.emplace_back(o, std::move(pt), p);

        arr.append(decltype(arr){x, y, p});
        for(int j = i - more * 2; j < i; j += 2)
        {
            arr.append(combineToInt<2>(packet, j));
        }
        newestPacketPack.append(std::move(arr));
    }

    if(i != packet.size())
    {
        goto error;
    }
    return;

    error:
    qDebug() << "Error packet: " << packet.toHex(' ') <<Qt::endl;
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
    widthScaler = static_cast<double>(width()) / DATA_MAX.width();
    heightScaler = static_cast<double>(height() - HEIGHT_RESERVED) / DATA_MAX.height();
    positionLabel->move(10, height() - (HEIGHT_RESERVED - 3));

    QPainter painter(this);
    static QPointF last[2] = {NO_PREVIOUS_POINT, NO_PREVIOUS_POINT};

    if(isShowingOld)
    {
        valid.clear();
    }
    if(shouldClearScreen)
    {
        painter.setBrush(Qt::white);
        painter.drawRect(0, 0, width(), height() - HEIGHT_RESERVED);
        last[0] = last[1] = NO_PREVIOUS_POINT;
        shouldClearScreen = false;

        // user called clearscreen by pressing space
        if(!isSwitching)
        {
            saved = QPixmap();
            newestPacketPack.clear();
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

    painter.eraseRect(0, height() - HEIGHT_RESERVED, width(), height());
    if(std::abs(coil.second - INVALID_COIL) > 1e-6)
    {
        positionLabel->setText(QStringLiteral("mouse: %1  %2    coil: %3  %4").arg(mouse.first)
                                                                              .arg(mouse.second)
                                                                              .arg(coil.first, 0, 'f', 1)
                                                                              .arg(coil.second, 0, 'f', 1));
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
        QString baseFilename = QStringLiteral("data/trajectory_%1").arg(QTime()
                                                                       .currentTime()
                                                                       .toString()
                                                                       .replace(':', '_'));
        QFileInfo fInfo(baseFilename);
        baseFilename = fInfo.absoluteFilePath();

        auto g = geometry();
        saved = QApplication::primaryScreen()->grabWindow(winId(), g.left(), g.top(), g.width(), g.height());
        assert(saved.save(baseFilename + ".png"));

        QFile txt(baseFilename + ".txt");
        assert(txt.open(QIODevice::WriteOnly | QIODevice::Text));
        QTextStream strm(&txt);
        bool ofirst = true, ifirst = true;
        for(const auto& lines : newestPacketPack)
        {
            if(!ofirst)
            {
                strm << '\n';
            }

            for(const auto elem : lines)
            {
                if(!ifirst)
                {
                    strm << ' ';
                }

                strm << elem;
                ifirst = false;
            }
            ifirst = true;
            ofirst = false;
        }
        txt.close();

        break;
    }
    case Qt::Key_R:
        isShowingOld = !isShowingOld;
        shouldClearScreen = true;
        isSwitching = true;
        break;
    case Qt::Key_Space:
        shouldClearScreen = true;
    }

    update();
    QWidget::keyPressEvent(event);
}

void TrajectoryMap::mouseMoveEvent(QMouseEvent* event)
{
    auto pos = event->position();
    mouse = {DATA_MAX.width() - pos.x() / widthScaler,
             DATA_MAX.height() - pos.y() / heightScaler};
    coil = {(DATA_MAX.width() - mouse.first) / 422.0 - 1,
            mouse.second > DATA_MAX.height() ? INVALID_COIL : (DATA_MAX.height() - mouse.second) / 350.0 - 1};
}

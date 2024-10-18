#include "heatmaptab.h"

#define WIDTH 20
#define HEIGHT 12
#define LINES 52
#define COLUMNS 39
#define SELF_CAP_PACKETSIZE (LINES + COLUMNS)
#define MUT_CAP_PACKETSIZE 3
#define SELF_CAP_HEADER 's'
#define MUT_CAP_HEADER 'm'

const QSize CellSize(WIDTH, HEIGHT);

HeatMap::HeatMap(QWidget *parent)
    : QOpenGLWidget{parent}
{
    stateTextEdit = new QTextEdit(this);
    stateTextEdit->setReadOnly(true);
    stateTextEdit->resize(200, LINES * HEIGHT);

    setAttribute(Qt::WA_OpaquePaintEvent);
}

void HeatMap::onSerialDataReceived(const QByteArray& packet)
{   
    QVector<int16_t> data;
    data.reserve(SELF_CAP_PACKETSIZE);

    assert(packet[0] == SELF_CAP_HEADER || packet[0] == MUT_CAP_HEADER);
    auto state = packet[0] == SELF_CAP_HEADER ? State::SelfCapacity : State::MutualCapacity;
    if((state == State::SelfCapacity && packet.size() - 1 != SELF_CAP_PACKETSIZE * 2) ||
       (state == State::MutualCapacity && (packet.size() - 1) % (MUT_CAP_PACKETSIZE * 2) != 0))
    {
        valid.emplace_back(State::Error, QVector<int16_t>(SELF_CAP_PACKETSIZE, 0));
        qDebug() << "Error packet: " << packet << Qt::endl;
        return;
    }

    for(int i = 1; i < packet.size(); i += 2)
    {
        auto high = packet[i + 1], low = packet[i];
        data.push_back(high << 8 | (uint8_t)low);
    }

    valid.emplace_back(state, data);
}

void HeatMap::setShouldRefresh(int index)
{
    if(index != 3)
    {
        return;
    }
    shouldClearScreen = true;
    valid.clear();
    valid.emplace_back(State::Waiting, QVector<int16_t>(SELF_CAP_PACKETSIZE, 0));
}

void HeatMap::onRefresh()
{
    update();
}

void HeatMap::paintEvent(QPaintEvent *)
{
    static const auto [originalWidth, originalHeight] = size();
    const double widthScaler = static_cast<double>(originalWidth) / width(),
                 heightScaler = static_cast<double>(originalHeight) / height();
    static const int left = 240, top = 20;
    static const auto calcHue = [](int16_t data)
    {
        if(data < -100)
        {
            return 120;
        }
        else if(data > 100)
        {
            return 0;
        }
        else
        {
            return 60;
        }
    };

    stateTextEdit->move(20, top);
    QPainter painter(this);

    // clear the background manually, and draw the table
    if(shouldClearScreen)
    {
        painter.eraseRect(0, 0, width(), height());
    }
    painter.setWindow(0, 0, WIDTH * COLUMNS, LINES * HEIGHT);
    painter.setViewport(left * widthScaler, top * heightScaler, WIDTH * COLUMNS * widthScaler, LINES * HEIGHT * heightScaler);

    static State oldDataState = State::Error;
    while(true)
    {
        if(valid.empty())
        {
            goto end;
        }

        const auto& [state, data] = valid.front();

        // refresh label area if needed
        if(state == State::Error || oldDataState != state)
        {
            QString text = QTime().currentTime().toString("[mm:ss.zzz]:");

            switch(state) {
            case State::Waiting:
                text += "Waiting";
                break;
            case State::Error:
                text += "Wrong Packet";
                break;
            case State::SelfCapacity:
                text += "Self Cap";
                break;
            case State::MutualCapacity:
                text += "Mut Cap";
                break;
            }
            oldDataState = state;
            stateTextEdit->append(text);
        }

        // receiving self capacity data
        if(state == State::SelfCapacity || shouldClearScreen)
        {
            painter.setBrush(QBrush(QColor::fromHsv(60, 255, 255)));
            painter.drawRect(0, 0, COLUMNS * WIDTH, LINES * HEIGHT);
            for(int j = 0; j < LINES; j++)
            {
                for(int i = LINES; i < COLUMNS + LINES; i++)
                {
                    int16_t d = (std::abs(data[i]) < std::abs(data[j]) ? data[i] : data[j]);
                    auto topLeft = QPoint(WIDTH * (i - LINES), HEIGHT * (j));
                    doPaint(&painter, calcHue(d), d, topLeft, CellSize);
                }
            }
        }
        else if(state == State::MutualCapacity)
        {
            for(int i = 0; i < data.size(); i += 3)
            {
                int16_t x = data[i], y = data[i + 1], d = data[i + 2];
                auto topLeft = QPoint(WIDTH * x, HEIGHT * y);
                doPaint(&painter, calcHue(d), d, topLeft, CellSize);
            }
        }

        valid.pop_front();
    }

    end:
    shouldClearScreen = false;
}

void HeatMap::resizeEvent(QResizeEvent* event)
{
    setShouldRefresh(3);
    update();
}

void HeatMap::doPaint(QPainter* painter, uint8_t hue, int16_t data, const QPoint& topLeft, const QSize& size)
{
    auto rect = QRect(topLeft, size);

    static const QFont font = QFont("Arial", 7);

    if(hue != 60)
    {
        QBrush brush = QBrush(QColor::fromHsv(hue, 255, 255));
        painter->setBrush(brush);
        painter->drawRect(rect);
    }

#ifndef SHOW_DETAILED_DATA
    if(data < -100 || data > 100)
#endif
    {
        painter->setFont(font);
        painter->setPen(QPen(Qt::black));
        painter->drawText(rect, Qt::AlignCenter, QString::number(data));
    }
}

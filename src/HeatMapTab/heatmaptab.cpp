#include "heatmaptab.h"

#define WIDTH 20
#define HEIGHT 12
#define LINES 52
#define COLUMNS 3
#define SELF_CAP_PACKETSIZE (LINES + COLUMNS)
#define MUT_CAP_PACKETSIZE 3
#define SELF_CAP_HEADER 'S'
#define MUT_CAP_HEADER 'M'
#define TAIL 'E'

#define SHOW_DETAILED_DATA

const QSize CellSize(WIDTH, HEIGHT);

HeatMap::HeatMap(QWidget *parent)
    : QOpenGLWidget{parent}
{
    stateTextEdit = new QTextEdit(this);
    stateTextEdit->setReadOnly(true);
    stateTextEdit->move(20, 8);
    stateTextEdit->resize(200, 600);

    setAttribute(Qt::WA_OpaquePaintEvent);
}

void HeatMap::onSerialDataReceived(const QByteArray& array)
{   
    QVector<int16_t> data;
    data.reserve(SELF_CAP_PACKETSIZE);
    assert(packet[0] == SELF_CAP_HEADER || packet[0] == MUT_CAP_HEADER);

    auto state = packet[0] == SELF_CAP_HEADER ? State::SelfCapacity : State::MutualCapacity;
    if((state == State::SelfCapacity && packet.size() - 2 != SELF_CAP_PACKETSIZE * 2) ||
       (state == State::MutualCapacity && (data.size() - 2) % (MUT_CAP_PACKETSIZE * 2)  != 0))
    {
        valid.push_back({State::Error, {}});
        qDebug() << "Error packet: " << packet << Qt::endl;
        return;
    }

    for(int i = 1; i < packet.size(); i += 2)
    {
        auto high = packet[i + 1], low = packet[i];
        data.push_back(high << 8 | low);
    }

    valid.push_back({state, data});
}

void HeatMap::setShouldRefresh(int index)
{
    if(index != 3)
    {
        return;
    }
    shouldClearScreen = true;
    valid.clear();
    valid.push_back({State::Waiting, QVector<int16_t>(SELF_CAP_PACKETSIZE, 0)});
}

void HeatMap::onRefresh()
{
    update();
}

void HeatMap::paintEvent(QPaintEvent *)
{
    static const auto size = this->size();
    static const int top = size.height() / 2 - LINES / 2 * HEIGHT;
    static const int left = 240;
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

    QPainter painter(this);

    // clear the background manually, and draw the table
    if(shouldClearScreen)
    {
        painter.eraseRect(0, 0, size.width(), size.height());
    }

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
            painter.drawRect(left, top, COLUMNS * WIDTH, LINES * HEIGHT);
            for(int j = 0; j < LINES; j++)
            {
                for(int i = LINES; i < COLUMNS + LINES; i++)
                {
                    int16_t d = std::min(data[i], data[j]);
                    auto topLeft = QPoint(left + WIDTH * (i - LINES), top + HEIGHT * (j));
                    doPaint(&painter, calcHue(d), d, topLeft, CellSize);
                }
            }
        }
        else if(state == State::MutualCapacity)
        {
            for(int i = 0; i < data.size(); i += 3)
            {
                int16_t x = data[i], y = data[i + 1], d = data[i + 2];
                auto topLeft = QPoint(left + WIDTH * x, top + HEIGHT * y);
                doPaint(&painter, calcHue(d), d, topLeft, CellSize);
            }
        }

        valid.pop_front();
    }

    end:
    shouldClearScreen = false;
}

void HeatMap::doPaint(QPainter* painter, uint8_t hue, int16_t data, const QPoint& topLeft, const QSize& size)
{
    auto rect = QRect(topLeft, size);

    static QFont font = QFont("Arial", 7);

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

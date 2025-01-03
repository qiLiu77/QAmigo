#include "barcharttab.h"

#define X_BIN_CNT (50 + 1)
#define Y_BIN_CNT (37 + 1)
#define WIDTH 18
#define HEIGHT 275
#define X_HEADER 'x'
#define Y_HEADER 'y'
#define DATA_SUBHEADER 'd'
#define I_SUBHEADER 'i'
#define Q_SUBHEADER 'q'
#define BASE_SUBHEADER 'b'
#define NUM_RESERVED 10
#define BASE_DIFF_THRESH 300

BarChart::BarChart(QWidget *parent)
    : QWidget{parent}
{
    avg[X] = QVector<int16_t>(X_BIN_CNT, 0);
    avg[Y] = QVector<int16_t>(Y_BIN_CNT, 0);
    maxTextEdit = new QLabel(this);
    maxTextEdit->resize(200, 40);
    maxTextEdit->move(20, 140);
    maxTextEdit->setText("Waiting");

    positive = new QValueAxis();
    positive->setRange(0, 6000);
    positive->setTickCount(6);
    positive->setLabelFormat("%d");
    real = new QValueAxis();
    real->setRange(-4000, 4000);
    real->setTickCount(13);
    real->setLabelFormat("%d");

    bin[X] = new QValueAxis();
    bin[X]->setRange(-0.5, X_BIN_CNT - 0.5);
    bin[X]->setTickType(QValueAxis::TicksDynamic);
    bin[X]->setTickInterval(5);
    bin[X]->setLabelFormat("%d");
    bin[Y] = new QValueAxis();
    bin[Y]->setRange(-0.5, Y_BIN_CNT - 0.5);
    bin[Y]->setTickType(QValueAxis::TicksDynamic);
    bin[Y]->setTickInterval(4);
    bin[Y]->setLabelFormat("%d");

    //generate barSeries for all combinations
    auto arr = reinterpret_cast<QBarSeries**>(barSeries);
    for(int i = 0; i < std::size(barSeries) * std::size(*barSeries); i++)
    {
        arr[i] = new QBarSeries(this);
        auto set = new QBarSet("数据");
        arr[i]->append(set);
    }

    //generate lineSeries for base data
    for(int i = 0; i < std::size(lineSeries); i++)
    {
        lineSeries[i] = new QLineSeries(this);
        lineSeries[i]->setName("基准");
    }

    //generate buttons
    auto generateButtonSeries = [this](const QList<QString>& labels, QRadioButton* array[], const QPoint& topLeft = {})
    {
        auto group = new QButtonGroup(this);
        for(int i = 0; i < labels.size(); i++)
        {
            auto button = new QRadioButton(labels[i], this);
            button->resize({100, 40});
            button->move(topLeft.x(), topLeft.y() + i * 30);
            array[i] = button;
            group->addButton(button);
        }

        array[0]->setChecked(true);
    };

    generateButtonSeries({"X", "Y"}, axisSwitch, {20, 30});
    generateButtonSeries({"Data", "I", "Q"}, dataSwitch, {100, 30});

    //connect signal for button press
    for(int i = 0; i < std::size(axisSwitch); i++)
    {
        connect(axisSwitch[i], &QRadioButton::clicked, [this, i](bool checked)
        {
            if(!checked)
            {
                return;
            }

            chart->removeSeries(barSeries[axisCheckedIndex][dataCheckedIndex]);
            axisCheckedIndex = i;
            reattachAxis(axisCheckedIndex, dataCheckedIndex);
        });
    }
    for(int i = 0; i < std::size(dataSwitch); i++)
    {
        connect(dataSwitch[i], &QRadioButton::clicked, [this, i](bool checked)
        {
            if(!checked)
            {
                return;
            }

            chart->removeSeries(barSeries[axisCheckedIndex][dataCheckedIndex]);
            dataCheckedIndex = i;
            reattachAxis(axisCheckedIndex, dataCheckedIndex);
        });
    }

    chart = new QChart();

    for(const auto& e1 : barSeries)
    {
        for(const auto& e2 : e1)
        {
            e2->setBarWidth(1.0);
        }
    }
    chart->addAxis(bin[X], Qt::AlignBottom);
    chart->addAxis(bin[Y], Qt::AlignBottom);
    chart->addAxis(positive, Qt::AlignLeft);
    chart->addAxis(real, Qt::AlignLeft);
    reattachAxis(axisCheckedIndex, dataCheckedIndex);

    chartView = new QChartView(chart, this);
    chartView->resize(900, 600);
    chartView->move(240, 40);
}

void BarChart::onSerialDataReceived(const QByteArray& packet)
{
    QVector<int16_t> data;
    int i = 2;
    assert(packet[0] == X_HEADER || packet[0] == Y_HEADER);
    if((packet.size() - 2) % 2 != 0)
    {
        goto error;
    }

    for(; i < packet.size(); i += 2)
    {
        auto high = packet[i + 1], low = packet[i];
        data.push_back(high << 8 | (uint8_t)low);
    }

    switch(auto u = packet.at(0), v = packet.at(1); v)
    {
    case DATA_SUBHEADER:
    case I_SUBHEADER:
    case Q_SUBHEADER:
    {
        static const auto axisMap = QMap<QChar, int>{{X_HEADER, X}, {Y_HEADER, Y}},
                          dataMap = QMap<QChar, int>{{DATA_SUBHEADER, D}, {I_SUBHEADER, I}, {Q_SUBHEADER, Q}};

        const int idx = data[0];
        auto series = this->barSeries[u = axisMap[u]][v = dataMap[v]];
        newestPacketPack[v] = data;

        //get and remove old set
        auto set = series->barSets()[0];
        assert(series->remove(set));

        //prepare new set
        set = new QBarSet("数据");
        int16_t max = 0, index = 0;
        for(int i = 0; i < idx; i++)
        {
            *set << 0;
        }
        for(int i = 1; i < data.size(); i++)
        {
            *set << data[i];
            if(data[i] > max)
            {
                max = data[i];
                index = idx + i;
            }
        }
        for(int i = idx + data.size() - 1; i < static_cast<int16_t>(packet[0] == X_HEADER ? X_BIN_CNT : Y_BIN_CNT); i++)
        {
            *set << 0;
        }

        //record max value and append set to series
        maxTextEdit->setText(QStringLiteral("max data is %1 at coil %2").arg(max).arg(index));
        series->append(set);
        break;
    }
    case BASE_SUBHEADER:
    {
#if false
        auto& base = this->base[u == X_HEADER ? X : Y];
        auto& avg = this->avg[u == X_HEADER ? X : Y];
        base.emplaceBack(data);
        if(base.length() > NUM_RESERVED)
        {
            base.pop_front();
        }
        for(int i = 0; i < base[0].size(); i++)
        {
            uint16_t sum = 0;
            for(int j = 0; j < base.size(); j++)
            {
                sum += base[j][i];
            }
            avg[i] = sum / base.size();
        }
        avg = base.back();
#endif

        // temporary measure for fixed base;
        for(int i = 0; i < data.size(); i++)
        {
            lineSeries[X]->append(i, data[i]);
        }
        reattachAxis(axisCheckedIndex, dataCheckedIndex);

        break;
    }
    default:
        goto error;
    }

    return;
error:
    qDebug() << "Error packet " << packet << Qt::endl;
}

void BarChart::setShouldRefresh(int index)
{
    if(index != 3)
    {
        return;
    }
    valid.clear();
    base[X].clear();
    base[Y].clear();
}

void BarChart::onRefresh()
{
    chart->update();
}

void BarChart::reattachAxis(int i, int j)
{
    chart->addSeries(barSeries[i][j]);
    chart->removeSeries(lineSeries[X]);
    chart->addSeries(lineSeries[X]);
    positive->setVisible(j == 0);
    real->setVisible(j != 0);
    bin[X]->setVisible(i == X);
    bin[Y]->setVisible(i == Y);
    barSeries[i][j]->attachAxis(bin[i]);
    barSeries[i][j]->attachAxis(j == 0 ? positive : real);
    lineSeries[X]->attachAxis(bin[i]);
    lineSeries[X]->attachAxis(j == 0 ? positive : real);
}

void BarChart::keyPressEvent(QKeyEvent* event)
{
    //QString nextText, currentText;
    QPainter painter(this);

    if(event->key() == Qt::Key_S)
    {
        QString baseFilename(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) +
                             "/QSerial Socket Amigo/data/barchart_%1");
        baseFilename = baseFilename.arg(QTime().currentTime().toString().replace(':', '_'));
        baseFilename = QFileInfo(baseFilename).absoluteFilePath();

        auto g = chart->geometry();
        auto screenshot = chartView->grab(QRect(g.left() + g.width() * 2 / 3, g.top() + g.height() / 2, g.width() / 3, g.height() / 2));
        if(!screenshot.save(baseFilename + ".png"))
        {
            goto error;
        }

        QFile txt(baseFilename + ".txt");
        if(!txt.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            goto error;
        }

        QTextStream strm(&txt);
        auto printPacket = [&strm](QVector<int16_t> packet){
            bool first = true;
            int prevLength = 0;
            for(const auto elem : packet)
            {
                if(!first)
                {
                    strm << QString(7 - prevLength, ' ');
                }
                auto str = QString::number(elem);
                prevLength = str.length();
                strm << str;
                first = false;
            }
        };
        strm << "D:\t";
        printPacket(newestPacketPack[D]);
        strm << "\nI:\t";
        printPacket(newestPacketPack[I]);
        strm << "\nQ:\t";
        printPacket(newestPacketPack[Q]);
        txt.close();

        QMessageBox(QMessageBox::Information, "提示", "保存成功", QMessageBox::Ok).exec();
    }

    update();
    QWidget::keyPressEvent(event);
    return;

error:
    QMessageBox(QMessageBox::Warning, "提示", "保存失败", QMessageBox::Ok).exec();
}

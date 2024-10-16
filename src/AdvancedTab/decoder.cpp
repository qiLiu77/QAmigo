#include "decoder.h"

Decoder::Decoder(QObject *object, const QList<Protocal *> &listProtocals,
                 const ENDIANESS &endianess) :
    QObject (object),
    listProtocals(listProtocals),
    endianess(endianess)
{
    timer = new QTimer(this);
    timer->setInterval(50);
    timer->start();
}

Decoder::~Decoder()
{
    delete timer;
}

QByteArray unstuffData(const QByteArray& stuffedData)
{
    QByteArray result;
    for (int i = 0; i < stuffedData.size(); i++)
    {
        if (stuffedData[i] == ESCAPE)
        {
            // missing escaped byte
            if(i + 1 == stuffedData.size())
            {
                goto error;
            }
            switch(stuffedData[++i])
            {
            case ESCAPE_LF:
                result.append(LF);
                break;
            case ESCAPE_BEGIN:
                result.append(BEGIN);
                break;
            case ESCAPE_END:
                result.append(END);
                break;
            case ESCAPE_ESCAPE:
                result.append(ESCAPE);
                break;
            default:
                // invalid escape byte
                goto error;
            }
        }
        else
        {
            result.append(stuffedData[i]);
        }
    }
    return result;
    error:
    return QByteArray();
}

void Decoder::setConnection(QIODevice *connection)
{
    disconnect(timer);
    connect(timer, &QTimer::timeout, [this, connection]
    {
        if (connection->bytesAvailable() > 0) {
            QByteArray newData = connection->readAll();
            buffer.append(newData);

            while (true) {
                int beginIndex = buffer.indexOf(BEGIN);
                if (beginIndex == -1)
                {
                    break; // 未找到帧头，跳出循环
                }

                int endIndex = buffer.indexOf(END, beginIndex + 1);
                if (endIndex == -1)
                {
                    break; // 未找到帧尾，数据可能不完整，等待更多数据
                }

                QByteArray stuffedPacket = buffer.mid(beginIndex + 1, endIndex - beginIndex - 1);
                buffer.remove(0, endIndex + 1);  // 相当于重定位到帧头（如果缺失帧头的话）
                QByteArray unstuffedPacket = unstuffData(stuffedPacket);

                if (!unstuffedPacket.isEmpty())
                {
                    emit dataReady(unstuffedPacket);
                }
                else
                {
                    qDebug() << "Error packet" << Qt::endl;
                    continue;
                }
            }
        }
    });
}

void Decoder::decode_buffer()
{
    /*
     * This will search for frame headers and see if the length satisfys
     * if header exits.
     *
     * Exit condition:
     * 1. All data should be garbage if no frame header is found, remove it
     * then.
     * 2. If headers are found while no frame is retrived, indicates that
     * all frames are not complete.
     *
     * It would be another story if there are CRC bytes, will be added later.
     */
    bool found = false;
    bool retrived = false;
    do {
        found = false;
        retrived = false;
        for (int i = 0; i < listProtocals.count(); i++) {
            Protocal *protocal = listProtocals[i];
            int index;
            if ((index = buffer.indexOf(protocal->getHeader())) != -1) {
                if (buffer.length() - index >= protocal->getFrameLength()) {
                    decodeFrame(i, buffer.mid(index + protocal->getHeader().length(), protocal->getFrameLength()));
                    buffer.remove(index, protocal->getFrameLength());
                    retrived = true;
                }
                found = true;
            }
        }
        if (!found)
            buffer.clear();
    } while (found && retrived);
}

void Decoder::decodeFrame(int id, QByteArray frameRawData)
{
    Protocal *protocal = listProtocals.at(id);
    QList<VarType *> *listData = protocal->getListData();
    //Prepare data to send to plugins.
    QList<double> listValues;
    int count = 0;
    for (int i = 0; i < listData->count(); i++) {
        VarType *type = listData->at(i);
        type->setBufferValue(frameRawData.mid(count, type->getSize()));
        count += type->getSize();
        double value = type->getDouble(endianess);
        listValues.append(value);
    }
    emit frameReady(id, listValues);
}

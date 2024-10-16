#ifndef DECODER_H
#define DECODER_H

#include <QByteArray>
#include <QThread>
#include <QIODevice>
#include <QList>
#include <QListWidget>

#include "protocal.h"
#include "vartype.h"

#define BEGIN 0x7E  // 帧的定界符
#define END 0x7F
#define ESCAPE 0x7D // 转义字符
#define ESCAPE_BEGIN 0x5E // 用于替代0x7E的转义序列
#define ESCAPE_END 0x5F
#define ESCAPE_ESCAPE 0x5D // 用于替代0x7D的转义序列

class Decoder : public QObject
{
    Q_OBJECT

public:
    Decoder(QObject *object, const QList<Protocal *> &listProtocals,
            const ENDIANESS &endianess);
    ~Decoder();

signals:
    void frameReady(int id, QList<double> listValues);		//Sends one ready frame out.
    void dataReady(const QByteArray &array);	//Sends what it recives.

public:
    void setConnection(QIODevice *connection);

private:
    void decode_buffer();
    void decodeFrame(int id, QByteArray frameRawData);

private:
    QTimer* timer;
    QByteArray buffer;
    QIODevice *connection;
    const QList<Protocal *> &listProtocals;
    const ENDIANESS &endianess;
};

#endif // DECODERTHREAD_H

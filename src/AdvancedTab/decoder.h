#ifndef DECODER_H
#define DECODER_H

#include <QByteArray>
#include <QThread>
#include <QIODevice>
#include <QList>
#include <QListWidget>

#include "protocal.h"
#include "vartype.h"

#define LF 0x0A
#define BEGIN 0x7E
#define END 0x7F
#define ESCAPE 0x7D
#define ESCAPE_LF 0x5A
#define ESCAPE_BEGIN 0x5E
#define ESCAPE_END 0x5F
#define ESCAPE_ESCAPE 0x5D

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

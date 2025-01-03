﻿#include "serialsendbox.h"
#include "tabcomsimple.h"

#include <QCoreApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTime>

TabCOMSimple::TabCOMSimple(QWidget *parent,
                           QSerialPort *port) : QWidget(parent),
    boxReceive(new QPlainTextEdit()),
    radioReceiveHex(new QRadioButton(tr("Hex"))),
    radioReceiveASC(new QRadioButton(tr("ASC"))),
    buttonReceiveClear(new QPushButton(tr("Clear All"))),
    counterRX(new TransferCounter(parent, tr("RX"))),
    counterTX(new TransferCounter(parent, tr("TX")))
{
    boxReceive->setFont({"Consolas", 12});

    radioReceiveASC->setChecked(true);

    QHBoxLayout *layoutMain = new QHBoxLayout(this);
    QVBoxLayout *layoutReceive = new QVBoxLayout(this);
    QVBoxLayout *layoutSend = new QVBoxLayout(this);

    layoutMain->addLayout(layoutReceive);
    layoutMain->addLayout(layoutSend);

    layoutReceive->addWidget(boxReceive);
    QHBoxLayout *layoutReceiveControls = new QHBoxLayout(this);
    layoutReceive->addLayout(layoutReceiveControls);

    layoutReceiveControls->addWidget(radioReceiveASC);
    layoutReceiveControls->addWidget(radioReceiveHex);

    layoutReceiveControls->addWidget(counterRX);
    layoutReceiveControls->addWidget(counterTX);

    layoutReceiveControls->addWidget(buttonReceiveClear);

    // Draw 5 serial send boxes at right of the window
    for (int i = 0; i < 5; i++) {
        SerialSendBox *box = new SerialSendBox(this, port);
        layoutSend->addWidget(box);
        connect(box, &SerialSendBox::errorSend, this, &TabCOMSimple::sendError);
        connect(box, &SerialSendBox::addSendCount, this, &TabCOMSimple::addTXCount);
    }

    connect(buttonReceiveClear, &QPushButton::clicked, this, &TabCOMSimple::onButtonReceiveClearClicked);
}

TabCOMSimple::~TabCOMSimple()
{
    delete counterRX;
    delete counterTX;
}

void TabCOMSimple::rawDataReady(const QByteArray &array)
{
    /*
     * appendPlainText is much more faster than insert or any other methods. But in Qt,
     * QPlainTextEdit is designed as a log system, which means it will automatically
     * append new line when we append new text and this is inevitable, so better use it
     * as a log system until we can implement a better append method.
     */
    QString buffer = QTime().currentTime().toString("[hh:mm:ss.zzz]: ");
    counterRX->add(array.size());

    if (radioReceiveASC->isChecked())
        boxReceive->appendPlainText(buffer.append(array));
    else {
        uint16_t count = 0;
        QString temp;
        for (char data : array.toHex()) {
            
            if (count % 2 == 1)
                //!!! data
                //temp.append(QString().sprintf("%c ", data));
                temp.append(QString().asprintf("%c ", data));
            else
                //temp.append(QString().sprintf("%c", data));
                temp.append(QString().asprintf("%c", data));
            count++;
        }
        boxReceive->appendPlainText(buffer.append(temp));
    }
}

void TabCOMSimple::addTXCount(int count)
{
    counterTX->add(count);
}

void TabCOMSimple::onButtonReceiveClearClicked()
{
    boxReceive->setPlainText("");
    counterRX->clear();
    counterTX->clear();
}

void TabCOMSimple::sendError(QString string)
{
    emit errorMessage(string);
}

void TabCOMSimple::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange)
        retranslateUi();
    QWidget::changeEvent(event);
}

void TabCOMSimple::retranslateUi()
{
    radioReceiveHex->setText(QCoreApplication::translate("TabCOMSimple", "Hex"));
    radioReceiveASC->setText(QCoreApplication::translate("TabCOMSimple", "ASC"));
    buttonReceiveClear->setText(QCoreApplication::translate("TabCOMSimple", "Clear All"));
    counterRX->setLabelText(QCoreApplication::translate("TabCOMSimple", "RX"));
    counterTX->setLabelText(QCoreApplication::translate("TabCOMSimple", "TX"));
}

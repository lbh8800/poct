#include "serialport.h"

SerialPort::SerialPort(QObject *parent) : QObject(parent)
{
    serial = new QSerialPort;
}
SerialPort::~SerialPort()
{
}
bool SerialPort::openPort(QString name, int baudRate)
{
    serial->setPortName(name);
    serial->setBaudRate(baudRate);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if(serial->open(QIODevice::ReadWrite))
    {
        connect(serial,&QSerialPort::readyRead,this,&SerialPort::read);
        return true;
    }
    else
        return false;
}
void SerialPort::closePort()
{
    serial->close();
}
void SerialPort::read()
{
    QByteArray returnData = serial->readAll();
}
void SerialPort::sendData(QByteArray &sendBuffer)
{
    if(serial->isOpen())
    {
        serial->write(sendBuffer);
    }
}

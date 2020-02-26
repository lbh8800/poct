#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class SerialPort : public QObject
{
    Q_OBJECT
public:
    explicit SerialPort(QObject *parent = nullptr);
    ~SerialPort();
    void sendData(QByteArray &sendBuffer);
    bool openPort(QString name, int baudRate);
    void closePort();

signals:

public slots:
    void read();

private:
    QSerialPort *serial;
};

#endif // SERIALPORT_H

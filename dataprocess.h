#ifndef DATAPROCESS_H
#define DATAPROCESS_H

#include <QObject>
#include "serialport.h"

class DataProcess : public QObject
{
    Q_OBJECT

public:
    explicit DataProcess(QObject *parent = nullptr);
    ~DataProcess();
    unsigned short crc16(const void *buf, int len);

signals:

public slots:
    void sendData(ushort typeCode, ushort actionCode);

private:
    SerialPort *serialPort;
};

#endif // DATAPROCESS_H

#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QtSerialPort/QSerialPort>

class SerialPort: public QSerialPort
{
public:
    SerialPort();

    const QString &getPortPath() const;
    void setPortPath(const QString &newPortPath);
    void createLists(void);

    QList<QString> baudRateList;
    QList<QString> dataBitList;
    QList<QString> stopBitList;
    QList<QString> parityList;
    QList<QString> flowControlList;

private:
    QString portPath;
};

#endif // SERIALPORT_H

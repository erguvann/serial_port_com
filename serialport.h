#ifndef SERIALPORT_H
#define SERIALPORT_H
#include <QtSerialPort/QSerialPort>

#define terminator1602 "0"
#define message1602 "1"

class SerialPort: public QSerialPort
{
public:
    SerialPort();

    const QString &getPortPath() const;
    void setPortPath(const QString &newPortPath);
    void createLists(void);
    void sendMessage1602(QByteArray);

    QList<QString> baudRateList;
    QList<QString> dataBitList;
    QList<QString> stopBitList;
    QList<QString> parityList;
    QList<QString> flowControlList;

private:
    QString portPath;
};

#endif // SERIALPORT_H

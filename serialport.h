#ifndef SERIALPORT_H
#define SERIALPORT_H
#include <QtSerialPort/QSerialPort>

#define terminator1602 '\n'
#define message1602 '1'
#define clear1602 '2'
#define secondLine1602 '3'
#define moveCursor1602 '4'
#define options1602 '5'

class SerialPort: public QSerialPort
{
public:
    SerialPort();

    QByteArray command;
    const QString &getPortPath() const;
    void setPortPath(const QString &newPortPath);
    void createLists(void);
    void sendMessage1602(QByteArray);
    void sendCommand1602(const char);
    void sendSettings1602(const char);

    QList<QString> baudRateList;
    QList<QString> dataBitList;
    QList<QString> stopBitList;
    QList<QString> parityList;
    QList<QString> flowControlList;

private:
    QString portPath;
};

#endif // SERIALPORT_H

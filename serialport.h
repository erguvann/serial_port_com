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

private:
    QString portPath;

};

#endif // SERIALPORT_H

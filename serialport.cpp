#include "serialport.h"


SerialPort::SerialPort()
{
    setBaudRate(BaudRate::Baud9600);
    setDataBits(DataBits::Data8);
    setStopBits(StopBits::OneStop);
    setParity(Parity::NoParity);
    setFlowControl(FlowControl::NoFlowControl);
    setPortName(portPath);
    createLists();
}

const QString &SerialPort::getPortPath() const
{
    return portPath;
}

void SerialPort::setPortPath(const QString &newPortPath)
{
    portPath = newPortPath;
}

void SerialPort::createLists()
{
    baudRateList.append("Select Baud Rate");
    baudRateList.append("1200");
    baudRateList.append("2400");
    baudRateList.append("4800");
    baudRateList.append("9600");
    baudRateList.append("19200");
    baudRateList.append("38400");
    baudRateList.append("57600");
    baudRateList.append("115200");
}

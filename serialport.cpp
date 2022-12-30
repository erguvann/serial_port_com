#include "serialport.h"

SerialPort::SerialPort()
{
    setBaudRate(BaudRate::Baud9600);
    setDataBits(DataBits::Data8);
    setStopBits(StopBits::OneStop);
    setParity(Parity::NoParity);
    setFlowControl(FlowControl::NoFlowControl);
    setPortName(portPath);

}

const QString &SerialPort::getPortPath() const
{
    return portPath;
}

void SerialPort::setPortPath(const QString &newPortPath)
{
    portPath = newPortPath;
}

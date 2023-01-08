#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>
#include <QStringList>
#include <QDebug>
#include <iostream>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Serial Port Com");
    getComPorts();
    serial = new SerialPort;
    connect(serial,SIGNAL(readyRead()),this,SLOT(readData()));
    ui->baudRateBox->addItems(serial->baudRateList);
    ui->baudRateBox->setCurrentIndex(4);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_send_button_clicked()
{
    ui->chat_box->appendPlainText(ui->message_line->text());
    ui->message_line->clear();
}

void MainWindow::readData()
{
    ui->chat_box->appendPlainText(serial->readAll());
}

void MainWindow::on_comPortButton_clicked()
{
    getComPorts();
}

void MainWindow::getComPorts()
{
    ui->comPortBox->clear();
    list = QSerialPortInfo::availablePorts();

    if(list.isEmpty())
        ui->comPortBox->addItem("No Port Detected");

    QList<QString> portList;

    for(int i=0; i<list.length(); i++)
    {
        portList.push_back(list[i].portName());
    }
    ui->comPortBox->addItems(portList);
}

void MainWindow::on_connectButton_clicked()
{ 
    int index = -1;
    for(int i=0; i<list.length(); i++)
    {
        if(list[i].portName() == ui->comPortBox->currentText())
        {
            index = i;
            //std::cout << i << std::endl;
            break;
        }
    }
    if(index != -1)
        serial->setPort(list[index]);
    else
        ui->chat_box->appendPlainText("Error: Selected port cannot be found! Please refresh port list");

    //QDebug << *(serial->getPortPath());
    int portOpen = serial->open(QIODeviceBase::ReadWrite);
    if(portOpen)
        ui->chat_box->appendPlainText("port açıldı");
    else
        ui->chat_box->appendPlainText("port açma hatası");
}

void MainWindow::on_baudRateBox_currentIndexChanged(int index)
{
    switch(index)
    {
        case 1:
            serial->setBaudRate(SerialPort::BaudRate::Baud1200);
            break;
        case 2:
            serial->setBaudRate(SerialPort::BaudRate::Baud2400);
            break;
        case 3:
            serial->setBaudRate(SerialPort::BaudRate::Baud4800);
            break;
        case 4:
            serial->setBaudRate(SerialPort::BaudRate::Baud9600);
            break;
        case 5:
            serial->setBaudRate(SerialPort::BaudRate::Baud19200);
            break;
        case 6:
            serial->setBaudRate(SerialPort::BaudRate::Baud38400);
            break;
        case 7:
            serial->setBaudRate(SerialPort::BaudRate::Baud57600);
            break;
        case 8:
            serial->setBaudRate(SerialPort::BaudRate::Baud115200);
            break;
    }
}


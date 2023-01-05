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
        ui->chat_box->appendPlainText("portInfo eşleşmedi");

    //QDebug << *(serial->getPortPath());
    int portOpen = serial->open(QIODeviceBase::ReadWrite);
    if(portOpen)
        ui->chat_box->appendPlainText("port açıldı");
    else
        ui->chat_box->appendPlainText("port açma hatası");
}




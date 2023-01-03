#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>
#include <QStringList>
//#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Serial Port Com");
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

void MainWindow::on_comPortButton_clicked()
{
    QList<QSerialPortInfo> list = QSerialPortInfo::availablePorts();
    QList<QString> portList;

    for(int i=0; i<list.length(); i++)
    {
        portList.push_back(list[i].portName());
    }
    ui->comPortBox->addItems(portList);
}

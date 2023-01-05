#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "serialport.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void getComPorts();

private slots:
    void on_send_button_clicked();
    void readData();
    void on_comPortButton_clicked();
    void on_connectButton_clicked();

private:
    QList<QSerialPortInfo> list;
    SerialPort* serial;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

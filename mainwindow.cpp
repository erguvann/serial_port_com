#include "mainwindow.h"
#include "ui_mainwindow.h"

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

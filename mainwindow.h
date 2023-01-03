#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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


    void on_comPortButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

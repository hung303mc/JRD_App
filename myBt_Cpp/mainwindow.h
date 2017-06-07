#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pbSend_clicked();

    void on_pbFind_clicked();

    void on_cbBtDevice_activated(const QString &arg1);

    void deviceDiscovered(const QBluetoothDeviceInfo &device);
    void msgReceived();
    void on_pbConnect_clicked();

private:
    Ui::MainWindow *ui;
    QBluetoothDeviceDiscoveryAgent *agent = new QBluetoothDeviceDiscoveryAgent;
    QBluetoothSocket *socket;
    QString BtAddress;
    QString sendMsg;
    QString RcvMsg;
};

#endif // MAINWINDOW_H

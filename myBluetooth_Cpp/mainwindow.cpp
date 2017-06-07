#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->hide();
    connect(agent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)), this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));
    agent->start();
    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbFind_clicked()
{
    ui->listWidget->show();
    ui->listWidget->clear();
    agent->stop();
    agent->start();
}

void MainWindow::on_pbOn_clicked()
{
    socket->write("a");
}

void MainWindow::on_pbOff_clicked()
{
    socket->write("b");
}

void MainWindow::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    ui->listWidget->addItem(device.address().toString());
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    myString = item->text();
    static const QString serviceUUid(QString("00001101-0000-1000-8000-00805F9B34FB"));
    socket->connectToService(QBluetoothAddress(myString),QBluetoothUuid(serviceUUid),QIODevice::ReadWrite);
}

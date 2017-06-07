#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(agent,SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),this,SLOT(deviceDiscovered(QBluetoothDeviceInfo)));
    agent->start();
    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbSend_clicked()
{
    sendMsg = ui->txtSendMsg->text();
    socket->write(sendMsg.toLocal8Bit());
    ui->txtConvMsg->appendPlainText(sendMsg);
}

void MainWindow::msgReceived()
{
    RcvMsg = QString::fromLocal8Bit(socket->readAll());
    ui->txtConvMsg->appendPlainText(RcvMsg);
}

void MainWindow::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    ui->cbBtDevice->addItem(device.address().toString());
}

void MainWindow::on_pbConnect_clicked()
{
    BtAddress = ui->cbBtDevice->currentText();
    qDebug() << "Address of connected bluetooth device : " << BtAddress;
    static const QString serviceUUid(QString("00001101-0000-1000-8000-00805F9B34FB"));
    socket->connectToService(QBluetoothAddress(BtAddress),QBluetoothUuid(serviceUUid),QIODevice::ReadWrite);
    ui->lbStatus->setText("Connect");
    connect(socket,SIGNAL(readyRead()),this,SLOT(msgReceived()));
}

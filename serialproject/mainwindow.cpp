#include "mainwindow.h"

MainWindow::MainWindow(QSerialPort *serialPort, QObject *parent) : QObject(parent), m_serialPort(serialPort)
{
    m_serialPort->setBaudRate(QSerialPort::Baud9600);
    m_serialPort->setDataBits(QSerialPort::Data8);
    m_serialPort->setParity(QSerialPort::NoParity);
    m_serialPort->setStopBits(QSerialPort::OneStop);
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);

    connect(m_serialPort, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(m_serialPort, SIGNAL(errorOccurred(QSerialPort::SerialPortError)), this, SLOT(handleError(QSerialPort::SerialPortError)));

    m_readTimer = new QTimer(this);
    m_readTimer->setInterval(100); // 100ms interval for reading data
    connect(m_readTimer, SIGNAL(timeout()), this, SLOT(readData()));
    m_readTimer->start();
}

void MainWindow::sendMessage(const QString &message)
{
    m_serialPort->write(message.toUtf8());
}

void MainWindow::readData()
{
    QByteArray data = m_serialPort->readAll();
    // Process received data and update UI as needed
}

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError)
    {
        // Handle the resource error
    }
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QTimer>

class MainWindow : public QObject
{
    Q_OBJECT
public:
    explicit MainWindow(QSerialPort *serialPort, QObject *parent = nullptr);
    Q_INVOKABLE void sendMessage(const QString &message);

private slots:
    void readData();
    void handleError(QSerialPort::SerialPortError error);

private:
    QSerialPort *m_serialPort;
    QTimer *m_readTimer;
};

#endif // MAINWINDOW_H

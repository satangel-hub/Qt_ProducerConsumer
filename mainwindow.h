#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QWaitCondition>
#include <QMutex>
#include "produce.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    const int DataSize = 1000;
    QStringList listBuffer;
    const int bufferSize = 10;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QThread th1;
    produce *pr1;
    QWaitCondition bufferNotEmpty;
    QWaitCondition bufferNotFull;
    QMutex mutex;
private:


};
#endif // MAINWINDOW_H

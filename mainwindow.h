#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "produce.h"
#include "consume.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QThread th_pd;
    produce *pd;
    QThread th_cs;
    consume *cs;

private:

};
#endif // MAINWINDOW_H

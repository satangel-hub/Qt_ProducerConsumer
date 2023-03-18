#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{


qDebug()<<"222222222222";
    pr1=new produce();
    pr1->moveToThread(&th1);
    th1.start();
    qDebug()<<"222222222222";
    pr1->runwhile(DataSize,bufferSize,listBuffer,&mutex,&bufferNotEmpty,&bufferNotFull);
qDebug()<<"222222222222";

    while(true)
           {
               QMutexLocker locker(&mutex);
               if (listBuffer.isEmpty())
                   bufferNotEmpty.wait(&mutex);

               QString strText = listBuffer.front();
               listBuffer.pop_front();
               bufferNotFull.wakeAll();

               //在这里手动unlock.
               locker.unlock();
//   #ifdef Q_OS_WIN
//               QThread::sleep(2000);
//   #endif
               //最好在这里来消费，如果多个消费者，就不会卡主其它线程消费了。
               qDebug()<<"consmer------"<<strText<<endl;

           }
}

MainWindow::~MainWindow()
{
}


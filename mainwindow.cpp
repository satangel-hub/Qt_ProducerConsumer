#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    pd=new produce();
    pd->moveToThread(&th_pd);
    th_pd.start();

    cs=new consume();
    cs->moveToThread(&th_cs);
    th_cs.start();

    connect(pd,&produce::siggoods,cs,&consume::slotgoods);

//    pr1->runwhile(DataSize,bufferSize,listBuffer,&mutex,&bufferNotEmpty,&bufferNotFull);
//    emit sigproducer(DataSize,bufferSize,listBuffer,&mutex,&bufferNotEmpty,&bufferNotFull);
//qDebug()<<"222222222222";
//QMutexLocker locker(&mutex);

//    while(true)
//           {
//               if (listBuffer.isEmpty())
//                   bufferNotEmpty.wait(&mutex);

//               QString strText = listBuffer.front();
//               listBuffer.pop_front();
//               bufferNotFull.wakeAll();

               //在这里手动unlock.
//               locker.unlock();
//   #ifdef Q_OS_WIN
//               QThread::sleep(2000);
//   #endif
               //最好在这里来消费，如果多个消费者，就不会卡主其它线程消费了。
//               qDebug()<<"consmer------"<<strText<<endl;

//           }
}

MainWindow::~MainWindow()
{
}


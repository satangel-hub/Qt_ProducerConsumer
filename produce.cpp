#include "produce.h"
#include <QDebug>

produce::produce(QObject *parent) : QObject(parent)
{

}
void produce::runwhile(const int DataSize,const int bufferSize,QStringList listBuffer,QMutex *mutex,QWaitCondition *bufferNotEmpty,QWaitCondition *bufferNotFull)
{
    qDebug()<<"11111111111111";
 for (int i = 0; i < DataSize; ++i)
         {
         qDebug()<<"11111111111111";
             QMutexLocker locker(mutex);
             if (listBuffer.size() == bufferSize)
                 bufferNotFull->wait(mutex);

             QString strNumer = QString::number(i);
                 qDebug()<<"11111111111111";
             //假设生产者比较慢,一秒一个
//    #ifdef Q_OS_WIN
//                QThread::sleep(1000);
                 qDebug()<<"11111111111111";
//    #endif
             qDebug()<<"producer----------"<<strNumer<<endl;
             listBuffer.push_back(strNumer);

             bufferNotEmpty->wakeAll();

         }
                 qDebug()<<"33333333333";
}



#include "produce.h"
#include <QDebug>

produce::produce(QObject *parent) : QObject(parent)
{

    connect(&ptime,&QTimer::timeout,this,[=](){
        static int i = 0;
        QString strNumer = QString::number(i++);
        emit siggoods(strNumer);
        qDebug()<<"producer------"<<strNumer<<endl;
    });
    ptime.start(1000);

}




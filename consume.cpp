#include "consume.h"
#include <QDebug>
consume::consume(QObject *parent) : QObject(parent)
{

}
void consume::slotgoods(QString Data )
{

    qDebug()<<"consumer------"<<Data<<endl;

}

#ifndef PRODUCE_H
#define PRODUCE_H

#include <QObject>
#include <QMutexLocker>
#include <QThread>
#include <QWaitCondition>

class produce : public QObject
{
    Q_OBJECT
public:
    explicit produce(QObject *parent = nullptr);
    void runwhile(const int DataSize=1000,const int bufferSize=10,QStringList listBuffer={""},QMutex *mutex=0,QWaitCondition *bufferNotEmpty=0,QWaitCondition *bufferNotFull=0);
signals:

};

#endif // PRODUCE_H

#ifndef PRODUCE_H
#define PRODUCE_H

#include <QObject>
#include <QThread>
#include <QTimer>

class produce : public QObject
{
    Q_OBJECT
public:
    explicit produce(QObject *parent = nullptr);
    QTimer ptime;

signals:
    void siggoods(QString);
};

#endif // PRODUCE_H

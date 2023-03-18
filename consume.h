#ifndef CONSUME_H
#define CONSUME_H

#include <QObject>

class consume : public QObject
{
    Q_OBJECT
public:
    explicit consume(QObject *parent = nullptr);

signals:
public slots:
    void slotgoods(QString);

};

#endif // CONSUME_H

#ifndef RUNNER_H
#define RUNNER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Runner : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Runner();
public slots:
    void move();
};

#endif // RUNNER_H

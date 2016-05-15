#ifndef PLAYER_H
#define PLAYER_H

#include "bluedrum.h"
#include "reddrum.h"
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsRectItem>

class Player : public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
public slots:
    void spawn();
};

#endif // PLAYER_H

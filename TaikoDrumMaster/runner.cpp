#include "runner.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>

extern Game * game;

Runner::Runner(){
    //draw the runner
    setPos(600,270);
    setPixmap(QPixmap(":/Drums/Runner.png"));

    //move the runner
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Runner::move(){
    //move the runner leftward
    setPos(x()-5,y());
    if(pos().x()+102 < 0){
        scene()->removeItem(this);
        delete this;
    }
}

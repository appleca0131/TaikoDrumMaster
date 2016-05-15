#include "time.h"
#include "game.h"
#include <QFont>

extern Game * game;

Time::Time(QGraphicsItem * parent) : QGraphicsTextItem(parent){
    //initailize the time
    time = 30;

    //draw the text
    setPlainText(QString("Timer: ") + QString::number(time));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Kristen ITC",35));
    setPos(470,10);
}

void Time::decrease(){
    time--;
    setPlainText(QString("Timer: ") + QString::number(time));
    if(time < 0){
        game->gameOver();
    }
}

int Time::getTime(){
    return time;
}

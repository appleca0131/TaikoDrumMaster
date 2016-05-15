#include "reddrum.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>

//there is an external global object called game
extern Game * game;

RedDrum::RedDrum(){
    //draw the red drum
    setPos(640,108);
    setPixmap(QPixmap(":/Drums/BigRedDrum.png"));

    //move the red drum
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

    //set drum sound
    drumsound = new QMediaPlayer();
    drumsound->setMedia(QUrl("qrc:/Sounds/DrumBeat.mp3"));
}

void RedDrum::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_J){
        //display the drum picture
        //QGraphicsPixmapItem * rightdrum = new QGraphicsPixmapItem();
        //rightdrum->setPos(437,200);
        //rightdrum->setPixmap(QPixmap(":/Drums/Right.png"));
        //scene()->addItem(rightdrum);

        //increase the score
        game->score->increase();

        //eliminate the blue drum
        scene()->removeItem(this);
        delete this;

        //play drum sound
        if(drumsound->state() == QMediaPlayer::PlayingState){
            drumsound->setPosition(0);
        }
        else if(drumsound->state() == QMediaPlayer::StoppedState){
            drumsound->play();
        }
    }
}

void RedDrum::move(){
    //move the red drum leftward
    setPos(x()-7,y());
    if(pos().x()+70 < 0){
        scene()->removeItem(this);
        delete this;
    }

    //make the red drum focusable
    if((45 < pos().x()) && (pos().x() < 70)){
        this->setFlag(QGraphicsItem::ItemIsFocusable);
        this->setFocus();
    }

    //make the red drum unfocusable
    if(pos().x() < 45){
        this->clearFocus();
    }
}

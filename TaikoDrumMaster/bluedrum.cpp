#include "bluedrum.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>

//there is an external global object called game
extern Game * game;

BlueDrum::BlueDrum(){
    //draw the blue drum
    setPos(640,108);
    setPixmap(QPixmap(":/Drums/BigBlueDrum.png"));

    //move the blue drum
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

    //set drum sound
    drumsound = new QMediaPlayer();
    drumsound->setMedia(QUrl("qrc:/Sounds/DrumBeat.mp3"));
}

void BlueDrum::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_F){
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

void BlueDrum::move(){
    //move the blue drum leftward
    setPos(x()-7,y());
    if(pos().x()+70 < 0){
        scene()->removeItem(this);
        delete this;
    }

    //make the blue drum focusable
    if((45 < pos().x()) && (pos().x() < 70)){
        this->setFlag(QGraphicsItem::ItemIsFocusable);
        this->setFocus();
    }

    //make the blue drum unfocusable
    if(pos().x() < 45){
        this->clearFocus();
    }
}

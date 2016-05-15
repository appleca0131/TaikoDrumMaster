#include "player.h"
#include "bluedrum.h"
#include "reddrum.h"
#include "runner.h"
#include "stdlib.h"
#include <QGraphicsScene>

Player::Player(QGraphicsItem * parent) : QGraphicsRectItem(parent){

}

void Player::spawn(){
    //randomly generate drums
    //srand(time(NULL));
    int randnum = rand()%4;

    if(randnum < 2){
        //create a blue drum
        BlueDrum * bluedrum = new BlueDrum();
        scene()->addItem(bluedrum);
    }
    else{
        //create a red drum
        RedDrum * reddrum = new RedDrum();
        scene()->addItem(reddrum);
    }

    //generate runners
    Runner * runner = new Runner();
    scene()->addItem(runner);
}

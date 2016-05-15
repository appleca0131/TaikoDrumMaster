#include "game.h"
#include "bluedrum.h"
#include "reddrum.h"
#include "button.h"
#include "score.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>
#include <QImage>

QTimer * countdowntimer; //for countdown
QTimer * timer; //for create drums
QMediaPlayer * music; //for background music

Game::Game(QWidget * parent){
    //set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(708,393);

    //set up the scene
    startscene = new QGraphicsScene();
    startscene->setSceneRect(0,0,708,393);
    setBackgroundBrush(QBrush(QImage(":/Backgrounds/StartScreen.jpg")));
    setScene(startscene);
}

void Game::start(){
    //clear the screen
    startscene->clear();
    setBackgroundBrush(QBrush(QImage(":/Backgrounds/BackGround.jpg")));

    //create the player
    player = new Player();
    player->setRect(0,0,0,0);
    startscene->addItem(player);

    //create the time
    time = new Time();
    startscene->addItem(time);
    countdowntimer = new QTimer();
    QObject::connect(countdowntimer,SIGNAL(timeout()),this,SLOT(countdown()));
    countdowntimer->start(1000);

    //create the score
    score = new Score();
    startscene->addItem(score);

    //create drums
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(1500);

    //play background music
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/Sounds/BackgroundMusic.mp3"));
    music->play();

    show();
}

void Game::restartGame(){
    //clear some stuff then call start
    music->stop();
    startscene->clear();
    start();
}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    //draw a panel at the specified location with the specified properties
    QGraphicsRectItem * panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    startscene->addItem(panel);
}

void Game::displayMainMenu(){
    //create the play button
    Button * playButton = new Button(QString("Play"));
    playButton->setPos(230,320);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    startscene->addItem(playButton);

    //create the quit button
    Button * quitButton = new Button(QString("Quit"));
    quitButton->setPos(370,320);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    startscene->addItem(quitButton);
}

void Game::gameOver(){
    countdowntimer->stop();
    timer->stop();

    displayGameOverWindow();
}

void Game::displayGameOverWindow(){
    //disable all scene items
    for(size_t i=0 ; i<startscene->items().size() ; i++){
        startscene->items()[i]->setEnabled(false);
    }

    //draw panel
    drawPanel(0,0,708,393,Qt::lightGray,1);

    //create playAgain button
    Button * playAgain = new Button(QString("Play Again"));
    playAgain->setPos(240,250);
    startscene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGame()));

    //create quit button
    Button * quit = new Button(QString("Quit"));
    quit->setPos(370,250);
    startscene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));

    //show result
    QGraphicsTextItem * resultscore = new QGraphicsTextItem();
    resultscore->setPlainText(QString("Score: ") + QString::number(score->getScore()));
    resultscore->setDefaultTextColor(Qt::blue);
    resultscore->setFont(QFont("Kristen ITC",35));
    resultscore->setPos(250,100);
    startscene->addItem(resultscore);
}

void Game::countdown()
{
    time->decrease();
}

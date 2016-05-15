#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "score.h"
#include "time.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>

class Game : public QGraphicsView{
    Q_OBJECT
public:
    //constructors
    Game(QWidget * parent=NULL);

    //public member functions
    void displayMainMenu();
    void gameOver();
    void displayGameOverWindow();

    //public data members
    QGraphicsScene * startscene;
    Player * player;
    Score * score;
    Time * time;
public slots:
    void countdown();
    void start();
    void restartGame();
private:
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
};

#endif // GAME_H

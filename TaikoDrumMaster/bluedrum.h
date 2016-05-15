#ifndef BLUEDRUM_H
#define BLUEDRUM_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>

class BlueDrum : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    BlueDrum();
    void keyPressEvent(QKeyEvent *event);
public slots:
    void move();
private:
    QMediaPlayer * drumsound;
};

#endif // BLUEDRUM_H

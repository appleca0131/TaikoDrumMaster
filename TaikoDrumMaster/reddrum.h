#ifndef REDDRUM_H
#define REDDRUM_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>

class RedDrum : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    RedDrum();
    void keyPressEvent(QKeyEvent *event);
public slots:
    void move();
private:
    QMediaPlayer * drumsound;
};

#endif // REDDRUM_H

#ifndef TIME_H
#define TIME_H

#include <QGraphicsTextItem>

class Time : public QGraphicsTextItem{
public:
    Time(QGraphicsItem * parent=0);
    void decrease();
    int getTime();
private:
    int time;
};

#endif // TIME_H

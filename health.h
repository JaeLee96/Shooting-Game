#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include "enemy.h"
#include "player.h"

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem * parent = nullptr);
    void decrease();
    int getHealth();
private:
    int health;
    Player * player;
    Enemy * enemy;
};

#endif // HEALTH_H

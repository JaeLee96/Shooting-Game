#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
private:
    int health;
    void move();
public:
    Enemy(QGraphicsItem * parent=0);
    void strongEnemy();
    void fastEnemy();
public slots:
    void move1();
    void move2();
    void move3();
};

#endif // ENEMY_H

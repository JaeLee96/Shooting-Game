#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <random>

#include "Game.h"
#include "Enemy.h"
#include "bullet.h"
#include "health.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QGraphicsPixmapItem(parent), health(1) {
    //set random x position
    int random_number = rand() % 700;
    setPos(random_number,0);

    QPixmap trump(":/Background/trump.png");
    setPixmap(trump.scaled(150, 150, Qt::KeepAspectRatio));

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move1()));

    // start the timer
    timer->start(50);
}


void Enemy::move(){

    if (health == 0) {
        scene()->removeItem(this);
        delete this;
        return;
    }

    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (auto item : colliding_items)
    {
        if (typeid(*item) == typeid(Bullet))
        {
            health--;
            scene()->removeItem(item);
            delete item;
            return;
        }
    }

    // destroy enemy when it goes out of the screen
    if (pos().y() > 600){
        //decrease the health
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}

void Enemy::fastEnemy()
{
    //set random x position
    int random_number = rand() % 700;
    setPos(random_number,0);

    QPixmap bolt(":/Background/bolt.png");
    setPixmap(bolt.scaled(200, 200, Qt::KeepAspectRatio));

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);

    disconnect(timer,SIGNAL(timeout()),this,SLOT(move1()));
    connect(timer,SIGNAL(timeout()),this,SLOT(move2()));

    // start the timer
    timer->start(50);
}

void Enemy::strongEnemy()
{
    health += 20;

    //set random x position
    int random_number = rand() % 700;
    setPos(random_number,0);

    QPixmap rock(":/Background/rock.png");
    setPixmap(rock.scaled(300, 300, Qt::KeepAspectRatio));

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);

    disconnect(timer,SIGNAL(timeout()),this,SLOT(move1()));
    connect(timer,SIGNAL(timeout()),this,SLOT(move3()));

    // start the timer
    timer->start(50);
}

void Enemy::move1(){
    // move enemy down
    setPos(x(),y()+3);
    move();
}

void Enemy::move2(){
    // move enemy down
    setPos(x(),y()+10);
    move();
}

void Enemy::move3(){
    // move enemy down
    setPos(x(),y()+0.3);
    move();
}

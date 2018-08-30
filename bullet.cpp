#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"

extern Game * game; // there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    QPixmap img(":/Background/bullet.png");
    setPixmap(img.scaled(50, 50, Qt::KeepAspectRatio));
    setTransformOriginPoint(25, 25);
    setRotation(-90);

    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(20);
}

void Bullet::move(){

    // if there was no collision with an Enemy, move the bullet forward
    setPos(x(),y()-15);
    // if the bullet is off the screen, destroy it

    if (pos().y() + pixmap().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}

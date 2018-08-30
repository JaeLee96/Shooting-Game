#include "Health.h"
#include <QFont>
#include <QGraphicsTextItem>
#include <QCoreApplication>
#include <QGraphicsScene>
#include <QTime>
#include "game.h"
#include "player.h"
#include "enemy.h"

extern Game * game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2
}

int Health::getHealth(){
    return health;
}


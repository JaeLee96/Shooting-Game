#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    bulletsound = new QMediaPlayer;
    bulletsound->setMedia(QUrl("qrc:/sounds/Gun_Shot-Marvin-1140816320 (1).wav"));

    QPixmap img(":/Background/kim jong un.png");
    setPixmap(img.scaled(200, 200, Qt::KeepAspectRatio));
}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x() + pixmap().width()/2 - 10 ,y() - bullet->pixmap().height());
        scene()->addItem(bullet);

        if (bulletsound->state() == QMediaPlayer::PlayingState)
            bulletsound->setPosition(0);
        else if (bulletsound->state() == QMediaPlayer::StoppedState)
            bulletsound->play();
    }
}

void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

void Player::spawn2(){
    // create an enemy
    Enemy * enemy = new Enemy();
    enemy->fastEnemy();
    scene()->addItem(enemy);
}

void Player::spawn3(){
    // create an enemy
    Enemy * enemy = new Enemy();
    enemy->strongEnemy();
    scene()->addItem(enemy);
}


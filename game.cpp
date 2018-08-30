#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QFont>
#include "Enemy.h"

Game::Game(QWidget *){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    QImage img2(":/Background/background.jpg");// make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(img2.scaled(800, 600)));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create the player
    player = new Player(); // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(x(),y()+25);
    scene->addItem(health);

    // spawn enemies
    QTimer * timer = new QTimer();
    QTimer * timer2 = new QTimer();
    QTimer * timer3 = new QTimer();

    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    QObject::connect(timer2,SIGNAL(timeout()),player,SLOT(spawn2()));
    timer2->start(7000);

    QObject::connect(timer3,SIGNAL(timeout()),player,SLOT(spawn3()));
    timer3->start(12000);

    QMediaPlayer * music = new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/maplestory bgm.mp3"));
    music->play();

}

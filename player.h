#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Player : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent = nullptr);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
    void spawn2();
    void spawn3();
private:
    QMediaPlayer * bulletsound;

};

#endif // PLAYER_H

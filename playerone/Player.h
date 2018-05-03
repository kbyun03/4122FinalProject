#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <vector>
#include "Enemy.h"
#include "Bullet.h"
#include <QMap>


class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    QVector<Enemy *> enemies;
    QVector<Bullet *> bullets;
    bool master;
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    void changeDirection();
    void showImage();
    QImage playerImage;

public slots:
    void moveFunc();
    void spawn();
private:
    QMediaPlayer * bulletsound;
    QMap <int, bool> keys;
    int bulletCounter;
    bool direction;
};

#endif // PLAYER_H

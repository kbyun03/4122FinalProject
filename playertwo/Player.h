#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <vector>
#include "Enemy.h"
#include "Bullet.h"
class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    QVector<Enemy *> enemies;
    QVector<Bullet *> bullets;
    bool master;
private:
    QMediaPlayer * bulletsound;
};

#endif // PLAYER_H

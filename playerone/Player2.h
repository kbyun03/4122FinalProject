#ifndef PLAYER2_H
#define PLAYER2_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <vector>
#include "Enemy.h"
#include "Bullet.h"


class Player2:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player2(QGraphicsItem * parent=0);

    QVector<Enemy *> enemies;
    QVector<Bullet *> bullets;
    bool master;
private:
    QMediaPlayer * bulletsound;
    int canSpawn;
};

#endif // PLAYER2_H

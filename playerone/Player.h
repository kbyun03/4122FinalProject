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
    void keyPressEvent(QKeyEvent * event);
    QVector<Enemy *> enemies;
    QVector<Bullet *> bullets;
    bool master;
    void stopSpawn();
public slots:
    void spawn();
private:
    QMediaPlayer * bulletsound;
    int canSpawn;
};

#endif // PLAYER_H

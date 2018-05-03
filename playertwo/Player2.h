#ifndef PLAYER2_H
#define PLAYER2_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <vector>
#include "Enemy.h"
#include "Bullet.h"
#include <QMap>


class Player2:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player2(QGraphicsItem * parent=0);
    QVector<Enemy *> enemies;
    QVector<Bullet *> bullets;
    bool master;
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
public slots:
    void moveFunc();
    void spawn();
private:
    QMediaPlayer * bulletsound;
    QMap <int, bool> keys;
    int bulletCounter;
};

#endif // PLAYER2_H

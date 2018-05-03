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
public slots:
    void moveFunc();
    void spawn(int x, int y);
private:
    QMediaPlayer * bulletsound;
    QMap <int, bool> keys;
    int bulletCounter;
};

#endif // PLAYER_H

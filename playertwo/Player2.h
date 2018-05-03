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
    void keyPressEvent(QKeyEvent * event);
    QVector<Enemy *> enemies;
    QVector<Bullet *> bullets;
    bool master;
public slots:
    void spawn(int x, int y);
private:
    QMediaPlayer * bulletsound;
};


#endif // PLAYER2_H

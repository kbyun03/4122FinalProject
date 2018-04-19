#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QMap>

class Player:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    //void keyPressEvent(QKeyEvent * event);
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
public slots:
    void moveFunc();
    void spawn();
private:
    QMediaPlayer *bulletsound;
    QMap<int,bool> keys;
};

#endif // PLAYER_H

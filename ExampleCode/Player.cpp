#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsRectItem(parent){
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/smb_coin.wav"));
}

void Player::keyPressEvent(QKeyEvent *e)
{
    keys[e->key()] = true;
    //QWidget::keyPressEvent(e);
}

void Player::keyReleaseEvent(QKeyEvent *e)
{
    keys[e->key()] = false;
}

void Player::moveFunc()
{

    if (keys[Qt::Key_Left]){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    if (keys[Qt::Key_Right]){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    // shoot with the spacebar
    if (keys[Qt::Key_Space]){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);

        // play bulletsound
        if(bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        } else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
    }
}

void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

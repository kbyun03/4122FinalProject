#include "Player.h"

#include <QGraphicsScene>
#include <QKeyEvent>
#include "QDebug"
#include "QThread"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/smb_coin.wav"));
    bulletCounter = 0;
    setPixmap(QPixmap(":/images/mariosprite.png"));



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

    if (keys[Qt::Key_A]){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    if (keys[Qt::Key_S]){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    // shoot with the spacebar
    if (keys[Qt::Key_Space]&&bulletCounter==0){
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
        bulletCounter = 5;
    }

    if(bulletCounter>0)
    {
        bulletCounter= bulletCounter - 1;
    }
}

void Player::spawn(int x, int y){
    // create an enemy
    Enemy * enemy = new Enemy(x,y);
    enemies.append(enemy);
    scene()->addItem(enemy);
}


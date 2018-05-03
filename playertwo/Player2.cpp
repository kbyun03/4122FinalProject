#include "Player2.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "QDebug"
#include "QThread"

Player2::Player2(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/smb_coin.wav"));
    bulletCounter = 0;
    setPixmap(QPixmap(":/images/luigi.png"));
}

void Player2::keyPressEvent(QKeyEvent *e)
{
    keys[e->key()] = true;
    //QWidget::keyPressEvent(e);
}

void Player2::keyReleaseEvent(QKeyEvent *e)
{
    keys[e->key()] = false;
}

void Player2::moveFunc()
{

    if (keys[Qt::Key_A]){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    if (keys[Qt::Key_D]){
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



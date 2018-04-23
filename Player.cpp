#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include "QDebug"
#include "QThread"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/smb_coin.wav"));

    setPixmap(QPixmap(":/images/mariosprite.png"));



}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A){
        if(pos().x()>0){
            setPos(x()- 10, y());
        }
    }
    else if(event->key() ==Qt::Key_D){
        if(pos().x() + 100< 800){
            setPos(x()+ 10, y());
        }
    }

    else if(event->key() == Qt::Key_Space){
        //create a bullet
        Bullet * bullet = new Bullet();
        bullet ->setPos(x(), y());
        scene()->addItem(bullet);

        // play bulletsound
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
    }

    else if(event->key() == Qt::Key_W){
        int jumpy;
        for(jumpy = 0; jumpy < 10 ; jumpy++){
            setPos(x(), y()- jumpy);
            qDebug()<< QString::number(y() - jumpy);
            QThread::sleep(1);

        }
    }
}

void Player::jump()
{

}

void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}


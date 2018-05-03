#include "Player2.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "QDebug"
#include "QThread"

Player2::Player2(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/smb_coin.wav"));

    setPixmap(QPixmap(":/images/luigi.png"));
}

void Player2::keyPressEvent(QKeyEvent *event)
{
    if (this->master)
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
            bullets.append(bullet);
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
    }
}


void Player2::spawn(){
    // create an enemy
    if(canSpawn){
        Enemy * enemy = new Enemy();
        enemies.append(enemy);
        scene()->addItem(enemy);
    }
}

void Player2::stopSpawn(){
    canSpawn = 0;
}


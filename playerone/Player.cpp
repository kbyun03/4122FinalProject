#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "QDebug"
#include "QThread"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/smb_coin.wav"));
    bulletCounter = 0;

    showImage();
    direction = true;
}

void Player::showImage()
{
    playerImage.load(":/images/mariosprite.png");
    QPixmap playerLabel(QPixmap::fromImage(playerImage));
    /*
    QTransform transform;
    QTransform trans = transform.scale(playerLabel.width(),playerLabel.height());
    trans
    */
    setPixmap(playerLabel);

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


void Player::changeDirection(){
    qDebug() << "code gets to change Direction";
    /*
    playerImage.mirrored();
    QPixmap playerLabel(QPixmap::fromImage(playerImage));
    setPixmap(playerLabel);
    */
}


void Player::moveFunc()
{

    if (keys[Qt::Key_A]){
        if(direction == false){
            changeDirection();
        }

        if (pos().x() > 0)
        setPos(x()-10,y());

        direction = true;
    }
    if (keys[Qt::Key_D]){

        if(direction == true){
            changeDirection();
        }

        if (pos().x() + 100 < 800)
        setPos(x()+10,y());

        direction = false;
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

void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    enemies.append(enemy);
    scene()->addItem(enemy);
}


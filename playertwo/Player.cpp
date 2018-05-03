#include "Player.h"

#include <QGraphicsScene>
#include <QKeyEvent>
#include "QDebug"
#include "QThread"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/smb_coin.wav"));

    setPixmap(QPixmap(":/images/mariosprite.png"));



}





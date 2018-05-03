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


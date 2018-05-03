#include "Health.h"
#include <QFont>

#include "Game.h"

extern Game * game;

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    // initialize the score to 0
    health = 3;

    // draw the score text

    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times", 24));


}

void Health::decrease()
{
    // initialize the score to 0
    health--;
    if(health>=0){
        setPlainText(QString("Health: ") + QString::number(health));
        setDefaultTextColor(Qt::red);
    }
    if(health==0){
        game->gameOver();
    }
}

int Health::getHealth()
{
    return health;
}

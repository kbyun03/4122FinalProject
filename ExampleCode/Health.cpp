#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //initialize score to 0;
    health = 3;

    //draw text
    setPlainText("Health: " + QString::number(health));//Health
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease()
{
    health--;
    setPlainText("Score: " + QString::number(health));
}

int Health::getHealth()
{
    return health;
}

#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    // initialize the score to 0
    health = 3;

    // draw the score text

    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times", 16));


}

void Health::decrease()
{
    health--;
    setPlainText(QString("Helath: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
}

int Health::getHealth()
{
    return health;
}

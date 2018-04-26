#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "client.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);
    void bla();
    void create_json();
    void UpdateGameScreen();
    QGraphicsScene * scene;
    Player * player;
    Player * player2;
    Score * score;
    Health * health;
    Client *client = NULL;
};

#endif // GAME_H

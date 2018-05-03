#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "Enemy.h"
#include "Score.h"
#include <QSplashScreen>

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);
    void StartGame();
    void UpdateGameScreen(char *cData);
    QGraphicsScene * scene;
    Player * player;
    Player * player2;
    Score * score;
    Health * health;
    void gameOver();
};

#endif // GAME_H

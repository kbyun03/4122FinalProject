#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
Game::Game(QWidget *parent){

}

void Game::StartGame()
{
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/images/bg.png")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create the player
    player = new Player();
    player->master = false;
    //player->setRect(0,0,100,100); // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(400,415); // TODO generalize to always be in the middle bottom of screen
    // add the player to the scene
    scene->addItem(player);


    player2 = new Player2();
    player2->master = true;
    player2->setPos(300,408);
    player2->setFlag(QGraphicsItem::ItemIsFocusable);
    player2->setFocus();
    scene->addItem(player2);


    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);


    //play background music
    QMediaPlayer * music = new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/bgsound.mp3"));
    music->play();

    show();
}

void Game::UpdateGameScreen(char *cData)
{
    QJsonDocument document = QJsonDocument::fromJson(cData);
    QJsonObject object = document.object();
    if(object["player1_x"].toDouble())
        player->setPos(object["player1_x"].toDouble(),object["player1_y"].toDouble());

    if(object["enemy_x"].toDouble())
        player->spawn(object["enemy_x"].toDouble(), 0);

    if (object["bullet"].toDouble())
    {
        Bullet * bullet = new Bullet();
        bullet ->setPos(object["player1_x"].toDouble(),object["player1_y"].toDouble());
        scene->addItem(bullet);
    }

}

void Game::gameOver()
{

    QString gameOverText = "Game Over";

    QGraphicsRectItem* panel = new QGraphicsRectItem(0,0,800,600);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    panel->setBrush(brush);
    panel->setOpacity(.65);
    scene->addItem(panel);

    QGraphicsTextItem* overText = new QGraphicsTextItem(gameOverText);
    overText->setPos(250,225);
    overText->setFont(QFont("times",50));
    overText->setDefaultTextColor(Qt::red);

    scene->addItem(overText);
    player->hide();
    player2->hide();
}

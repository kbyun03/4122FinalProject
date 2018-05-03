#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include "Score.h"
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QInputDialog>
#include <QDir>
#include <QGraphicsTextItem>

Game::Game(QWidget *parent){

    // prompt for player2's ip address
    bool ok;
    QString ipAddress = QInputDialog::getText(this, tr("User Linker"), tr("Enter IP Address:"),
                                         QLineEdit::Normal, QDir::home().dirName(), &ok);
    if (ok && !ipAddress.isEmpty())
        qDebug() <<"ip address entered";

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
    player->master = true;
    //player->setRect(0,0,100,100); // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(400,415); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);


    player2 = new Player2();
    player2->setPos(300,408);
    player2->master = false;
    scene->addItem(player2);


    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);



    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,&QTimer::timeout,this,&Game::bla);
    timer->start(2000);
    // Send Json to other player
    QTimer * timer2 = new QTimer();
    QObject::connect(timer2,&QTimer::timeout,this,&Game::create_json);
    timer2->start(50);

    client = new Client(ipAddress, 10000);
    //client = new Client("128.61.116.71", 10000);
    qDebug() << ipAddress;

    // Update game screen on message receivng
    QObject::connect(client->tcpSocket, &QIODevice::readyRead, this,&Game::UpdateGameScreen);

    //play background music
    QMediaPlayer * music = new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/bgsound.mp3"));
    music->play();

    show();
}

void Game::bla()
{
    player->spawn();
}

void Game::create_json()
{
    QJsonObject json_data;
    Enemy *e;
    Bullet *b;
    for(int i = 0; i<player->enemies.size(); i++)
    {
        e = player->enemies[i];
        if (!e->sent)
        {
            json_data["enemy_x"] = e->x();
            e->sent = true;
            player->enemies.remove(i);
            i = i-1;
            break;
        }
        player->enemies.remove(i);
        i = i-1;
    }
    for(int i = 0; i<player->bullets.size(); i++)
    {
        b = player->bullets[i];
        if (!b->sent)
        {
            json_data["bullet"] = b->x();
            b->sent = true;
            player->bullets.remove(i);
            i = i-1;
            break;
        }
        player->bullets.remove(i);
        i = i-1;
    }

    json_data["player1_x"] = player->x();
    json_data["player1_y"] = player->y();

    QJsonDocument doc(json_data);
    client->SendData(doc.toJson(QJsonDocument::Compact).constData());
}

void Game::UpdateGameScreen()
{
    client->ReadData();
    for (int i = 0; i<1024; i++)
    {
        if (client->cData[i] == '}')
        {
            //buff[i+1] - '"';
            client->cData[i+1] = '\0';
            break;
        }
    }
    QJsonDocument document = QJsonDocument::fromJson(client->cData);
    QJsonObject object = document.object();
    if(object["player2_x"].toDouble()){
        player2->setPos(object["player2_x"].toDouble(),object["player2_y"].toDouble());
    }
    if (object["bullet"].toDouble())
    {
        Bullet * bullet = new Bullet();
        bullet ->setPos(object["player2_x"].toDouble(),object["player2_y"].toDouble());
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
    player->stopSpawn();

}

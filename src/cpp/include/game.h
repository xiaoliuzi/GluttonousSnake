#ifndef GAME_H
#define GAME_H

#include <QObject>

#include <QVector>
#include <QTimer>
#include "constant.h"
#include <ctime>


class GameView;

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = 0);
    ~Game();

    void start(GameView &view);
    void start_timer();
    void stop_timer();
    bool dead_();
    int score_();
    QVector<QPoint>& snake_();
    QPoint& seed_();

    bool is_dead(QPoint new_head);
    QPoint& new_seed();
    void control(int code);

signals:

public slots:
    void one_step();
private:
    int last_update;
    int score;
    QTimer *timer = new QTimer(this);
    QVector<QPoint> snake;
    bool dead;
    int curdir;
    GameView *view;
    QPoint seed;
};

#endif // GAME_H

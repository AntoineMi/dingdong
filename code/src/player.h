#ifndef HEADER_PLAYER
#define HEADER_PLAYER

#include "ball.h"
#include "bar.h"

#define P_MAX 12

typedef struct Player {
    int score;
    int theme;
    int id;
} Player;

void initPlayers();
int checkScore(Player *p, Ball *b, Bar *bar);
void showScore();

Player p1, p2;

#endif

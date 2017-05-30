#ifndef HEADER_PLAYER
#define HEADER_PLAYER

#include "ball.h"
#include "bar.h"

#define P_MAX 12

typedef struct Player {
    int score;
    int health;
    int theme;
    int id;
} Player;

void initPlayers();
int checkHealth(Player *p, Ball *b, Bar bar);

Player p1, p2;

#endif
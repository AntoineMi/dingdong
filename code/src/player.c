#include <stdio.h>

#include "player.h"
#include "ball.h"
#include "bar.h"

void initPlayers() {
    p1.score = 0;
    p1.health = 5;
    p1.theme = 0;
    p1.id = 1;

    p2.score = 0;
    p2.health = 5;
    p2.theme = 0;
    p2.id = 2;
}

int checkHealth(Player *p, Ball *b, Bar bar) {
    if (p->health > 1) {
        int y, dy;
        if (p->id == 1) {
            y = 100;
            dy = 1;
        } else {
            y = 492;
            dy = -1;
        }
        p->health--;
        initBall(b, bar.x, y, dy, p->id);
        return 1;
    }
    else return 0;
}

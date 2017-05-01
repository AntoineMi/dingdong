#include "bar.h"

void moveBar(Bar *bar, int dir) {
    if(dir) { /* gauche */
        if(bar->x > 0) bar->x -= 1 * bar->speed;
    }
    else { /* droite */
        if(bar->x < 700) bar->x += 1 * bar->speed;
    }
}

void initBars() {
    bar1.speed = 1;
    bar1.x = 350;
    bar1.y = 10;

    bar2.speed = 1;
    bar2.x = 350;
    bar2.y = 580;
}
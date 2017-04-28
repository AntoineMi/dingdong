#include "bar.h"

void barMove(Bar *bar, int dir) {
    if(dir) { /* gauche */
        if(bar->x > 0) bar->x -= 1 * bar->speed;
    }
    else { /* droite */
        if(bar->x < 700) bar->x += 1 * bar->speed;
    }
}
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "ball.h"
#include "bar.h"
#include "game.h"
#include "brick.h"

void initBall(Ball *b, int x, int y) {
    b->speed = 1;
    b->x = x;
    b->y = y;
    b->dx = 1;
    b->dy = 1;
}

void drawBall(Ball b) {
    center.x = b.x;
    center.y = b.y;
    center.h = 16;
    center.w = 16;
    img = IMG_Load("img/ball.png");
    SDL_BlitSurface(img, NULL, screen, &center);
}

void bounceBall(Ball *b, int isSide) {
    if (isSide) /* côtés */
        b->dx = -b->dx;
    else /* haut/bas */
        b->dy = -b->dy;
}

void deathBall(Ball *b) {
    b->dx = 0;
    b->dy = 0;
    printf("Game over!\n");
}

void moveBall(Ball *b) {
    if(b->dx != 0 || b->dy != 0) {

        /* position au prochain draw */
        targetX = b->x + b->dx * b->speed;
        targetY = b->y + b->dy * b->speed;

        /* limites zone de jeu */
        if (targetX > 8 && targetX < 792) {
            b->x = targetX;
        }
        if (targetY > 0 && targetY < 584) {
            b->y = targetY;
        } else deathBall(b);
        
        /* côtés */
        if (targetX <= 8 || targetX >= 792) {
            bounceBall(b, 1);
        }

        /* barres */
        if ((b->x >= bar1.x &&
             b->x <= (bar1.x - 5) + 105 &&
             b->y == 20) ||
            (b->x >= bar2.x &&
             b->x <= (bar2.x - 5) + 105 &&
             b->y == 564))
            bounceBall(b, 0);

        /* briques */
        if (checkCollide(targetX, targetY)) {
            bounceBall(b, 1);
        }
        
    }
}
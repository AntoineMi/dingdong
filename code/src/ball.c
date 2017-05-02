#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "ball.h"
#include "bar.h"
#include "game.h"

void initBall() {
    b.speed = 1;
    b.x = 392;
    b.y = 292;
    b.dx = 1;
    b.dy = 1;
    printf("Balle initialisée\n");
}

void drawBall() {
    center.x = b.x;
    center.y = b.y;
    center.h = 16;
    center.w = 16;
    img = IMG_Load("ball.png");
    SDL_BlitSurface(img, NULL, screen, &center);
}

void bounceBall(int isSide) {
    if (isSide) /* côtés */
        b.dx = -b.dx;
    else /* haut/bas */
        b.dy = -b.dy;
}

void deathBall() {
    b.dx = 0;
    b.dy = 0;
    printf("x = %d y = %d\n", b.x, b.y);
    printf("Game over!\n");
}

void moveBall() {
    if(b.dx != 0 || b.dy != 0) {
        targetX = b.x + b.dx * b.speed;
        targetY = b.y + b.dy * b.speed;
        if (targetX > 8 && targetX < 792) {
            b.x = targetX;
        }
        if (targetY > 0 && targetY < 584) {
            b.y = targetY;
        } else deathBall();
        
        /* côtés */
        if (targetX <= 8 || targetX >= 792) {
            bounceBall(1);
        }

        /* barres */
        if ((b.x >= bar1.x &&
             b.x <= bar1.x + 100 &&
             b.y == 20) ||
            (b.x >= bar2.x &&
             b.x <= bar2.x + 100 &&
             b.y == 564))
            bounceBall(0);
    }
}
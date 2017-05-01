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

void bounceBall() {
    b.dx -= b.dx * 2;
    b.dy -= b.dy * 2;
    printf("x = %d y = %d\n", b.x, b.y);
}

void deathBall() {
    b.dx = 0;
    b.dy = 0;
    printf("x = %d y = %d\n", b.x, b.y);
    printf("Game over!\n");
}

void moveBall() {
    if(b.dx != 0 || b.dy != 0) {
        /* côtés */
        if (b.x + b.dx * b.speed > 8 && b.x + b.dx * b.speed < 792) {
            b.x += b.dx * b.speed;
        } else bounceBall();

        /* haut / bas */
        if (b.y + b.dy * b.speed > 0 && b.y + b.dy * b.speed < 584) {
            b.y += b.dy * b.speed;
        } else deathBall();

        if (b.x >= bar1.x &&
            b.x <= bar1.x + 100 &&
            b.y == 20)
            bounceBall();
        if (b.x >= bar2.x &&
            b.x <= bar2.x + 100 &&
            b.y == 564)
            bounceBall();

    }
}
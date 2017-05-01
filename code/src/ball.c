#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "ball.h"
#include "game.h"

void initBall() {
    b.speed = 1;
    b.x = 393;
    b.y = 293;
    b.dx = 1;
    b.dy = 0;
    printf("Balle initialisée\n");
}

void drawBall() {
    center.x = b.x;
    center.y = b.y;
    center.h = 15;
    center.w = 15;
    img = IMG_Load("ball.png");
    SDL_BlitSurface(img, NULL, screen, &center);
}

void bounceBall() {
    b.dx -= b.dx * 2;
    b.dy -= b.dy * 2;
}

void moveBall() {
    if(b.dx != 0 || b.dy != 0) {
        if (b.x + b.dx * b.speed > 15 && b.x + b.dx * b.speed < 785) {
            b.x += b.dx * b.speed;
        } else bounceBall();
        if (b.y + b.dy * b.speed > 15 && b.y + b.dy * b.speed < 585) {
            b.y += b.dy * b.speed;
        } else bounceBall();
    }
}
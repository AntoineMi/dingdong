#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "ball.h"
#include "game.h"

void initBall() {
    b.speed = 1;
    b.x = 393;
    b.y = 293;
    b.dx = 0;
    b.dy = 0;
}

void drawBall() {
    center.x = b.x;
    center.y = b.y;
    center.h = 15;
    center.w = 15;
    img = IMG_Load("ball.png");
    SDL_BlitSurface(img, NULL, screen, &center);
}
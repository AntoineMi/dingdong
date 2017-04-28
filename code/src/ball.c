#include "ball.h"
#include "game.h"

void drawBall() {
    center.x = b.x;
    center.y = b.y;
    center.h = 15;
    center.w = 15;
    img = IMG_Load("img/ball.png");
    SDL_BlitSurface(img, NULL, screen, &center);
}
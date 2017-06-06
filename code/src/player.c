#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "player.h"
#include "game.h"
#include "ball.h"
#include "bar.h"

void initPlayers() {
    p1.score = 5;
    p1.theme = 0;
    p1.id = 1;

    p2.score = 5;
    p2.theme = 0;
    p2.id = 2;
}

int checkScore(Player *p, Ball *b, Bar *bar) {
    if (p->score > 1) {
        int y, dy;
        if (p->id == 1) {
            y = 100;
            dy = 1;
        } else {
            y = 492;
            dy = -1;
        }
        p->score -= 2;
        bar->speed = 1;
        initBall(b, bar->x, y, dy, p->id);

        return 1;
    }
    else return 0;
}

void showScore() {
    int i, x, y;
    center.h = 20;
    center.w = 20;
    if (!game.theme)
    img = IMG_Load("img/classic/score.png");
    else img = IMG_Load("img/gta/score.png");

    /* score j1 */
    x = 845;
    y = 135;
    for (i = 0; i <= p1.score; i++) {
        center.x = x;
        center.y = y;
        SDL_BlitSurface(img, NULL, screen, &center);
        x += 20;
        if ((i%5 == 0) && (i != 0)) {
            x = 845;
            y += 20;
        }        
    }

    /* score j2 */
    x = 845;
    y = 450;
    for (i = 0; i <= p2.score; i++) {
        center.x = x;
        center.y = y;
        SDL_BlitSurface(img, NULL, screen, &center);
        x += 20;
        if ((i%5 == 0) && (i != 0)) {
            x = 845;
            y += 20;
        }        
    }
}
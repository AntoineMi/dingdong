#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "ball.h"
#include "bar.h"
#include "game.h"
#include "brick.h"
#include "player.h"

void initBall(Ball *b, int x, int y, int dy, int owner) {
    b->speed = 1;
    b->x = x;
    b->y = y;
    b->dx = 1;
    b->dy = dy;
    b->owner = owner;
}

void drawBall(Ball b) {
    center.x = b.x;
    center.y = b.y;
    center.h = 16;
    center.w = 16;
    if (!game.theme)
        img = IMG_Load("img/classic/ball.png");
    else img = IMG_Load("img/gta/ball.png");
    SDL_BlitSurface(img, NULL, screen, &center);
}

void bounceBall(Ball *b, int isSide) {
    if (isSide) /* côtés */
        b->dx = -b->dx;
    else /* haut/bas */
        b->dy = -b->dy;
}

void deathBall(Ball *b) {
    int owner = b->owner;
    int gameOver = 0;

    /* joueur 1 */
    if (owner == 1) {
        if (checkScore(&p1, b, &bar1)) {
            /*printf("Score J1 : %d\n", p1.score);*/
        } else {
            gameOver = 1;
        }
    }

    /* joueur 2 */
    else if (owner == 2) {
        if (checkScore(&p2, b, &bar2)) {
            /*printf("Score J2 : %d\n", p2.score);*/
        } else {
            gameOver = 1;
        }
    }

    if (gameOver) {
        b->dx = 0;
        b->dy = 0;

        center.x = 0;
        center.y = 0;
        center.h = 1000;
        center.w = 600;

        if (!game.theme) /* classic */
            img = IMG_Load("img/classic/gameOver.png");
        else img = IMG_Load("img/gta/gameOver.png");

        /*printf("Game over!\n");*/
        SDL_BlitSurface(img, NULL, screen, &center);
        SDL_Flip(screen);
        SDL_Delay(5000);
        loop = 0;
    }
    
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
        if (b->x >= bar1.x
        && b->x <= (bar1.x - 5) + 105
        && b->y == 20) {
            b->owner = 1;
            bounceBall(b, 0);
        }
        if (b->x >= bar2.x
        && b->x <= (bar2.x - 5) + 105
        && b->y == 564) {
            b->owner = 2;
            bounceBall(b, 0);
        }

        /* briques */
        if (checkCollide(targetX, targetY, b)) {
            if (targetX > b->x)
                bounceBall(b, 0);
            else
                bounceBall(b, 1);
        } 
    }
}

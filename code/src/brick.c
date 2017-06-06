#include <GL/gl.h>
#include <stdio.h>
#include "brick.h"
#include "game.h"
#include "ball.h"
#include "player.h"
#include "bar.h"

Brick initBrick(int x, int y, int bonus) {
    Brick br;
    br.x = x;
    br.y = y;
    br.bonus = bonus;
    br.alive = 1;
    return br;
}

void initBrickArray(Brick brArray[600][300]) {
    int gridX = 385 - ((game.gridW * 30) / 2) + 15;
    int gridY = 285 - ((game.gridH * 30) / 2) + 15;
    printf("gridX = %d\ngridY = %d\n", gridX, gridY);
    
    int i, j;
    for (i = 0; i < game.gridH; i++) {
        for (j = 0; j < game.gridW; j++) {
            brArray[i][j] = initBrick(gridX, gridY, settingsArray[i + j]);
            gridX += 30;
        }
        gridX = 385 - ((game.gridW * 30) / 2) + 15;
        gridY += 30;
    }
}

void drawBricks() {
    int i, j;
    for (i = 0; i < game.gridH; i++) {
        for (j = 0; j < game.gridW; j++) {
            if (game.brArray[i][j].alive) {
                center.x = game.brArray[i][j].x;
                center.y = game.brArray[i][j].y;
                center.h = 30;
                center.w = 30;
                if (!game.theme)
                    img = IMG_Load("img/classic/brick.png");
                else img = IMG_Load("img/gta/brick.png");
                SDL_BlitSurface(img, NULL, screen, &center);
            }
        }
    }
}

void deathBrick(Brick *br, Ball *b) {
    br->alive = 0;
    if (b->owner == 1) {
        switch (br->bonus) {
            /* 1 point bonus */
            case 1:
                p1.score++;
                printf("pt bonus p1\n");
                break;
            /* malus 1 point */
            case 2:
                p1.score--;
                printf("malus pt p1\n");
                break;
            /* bonus vitesse */
            case 3:
                bar1.speed += 1;
                printf("bonus vitesse p1\n");
                break;
            /* malus vitesse */
            case 4:
                bar1.speed = 0.5;
                printf("bonus vitesse p1\n");
                break;
            default:
                break;
        }
        p1.score++;

    }
    else if (b->owner == 2) {
        switch (br->bonus) {
            case 1:
                p2.score++;
                printf("pt bonus p2\n");
                break;
            /* malus 1 point */
            case 2:
                p2.score--;
                printf("malus pt p1\n");
                break;
            /* bonus vitesse */
            case 3:
                bar2.speed += 1;
                printf("bonus vitesse p2\n");
                break;
            /* malus vitesse */
            case 4:
                bar2.speed = 0.5;
                printf("malus vitesse p2\n");
                break;
            default:
                break;
        }
        p2.score++;
    }

    printf("\nscore p1 : %d\n", p1.score);
    printf("score p2 : %d\n", p2.score);
}

int checkCollide(int x, int y, Ball *b) {
    int collision = 0;

    int i, j;
    for (i = 0; i < game.gridH; i++) {
        for (j = 0; j < game.gridW; j++) {
            if ((x > game.brArray[i][j].x + 30)  /* droite */
            || (x + 30 < game.brArray[i][j].x)  /* gauche */
            || (y > game.brArray[i][j].y + 30)  /* bas */
            || (y + 30 < game.brArray[i][j].y)) /* haut */
                collision = 0;
            else if (game.brArray[i][j].alive) {
                collision = 1;
                deathBrick(&game.brArray[i][j], b);
            }
            else
                collision = 0;
        }
    }
    return collision;
}


/* OpenGL

void drawSquare() {
    printf("drawing square\n");
    glBegin(GL_QUADS);
        glVertex2f(-500, -500);
        glVertex2f(-500, 500);
        glVertex2f(500, 500);
        glVertex2f(500, -500);
    glEnd();
}

void drawBricks(Brick br) {
    glPushMatrix();
        glTranslatef(br.x, br.y, 0);
        glScalef(50, 50, 0);
        glColor3ub(br.r, br.v, br.b);
        drawSquare();
    glPopMatrix();
}

*/

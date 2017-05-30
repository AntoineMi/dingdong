#include <GL/gl.h>
#include <stdio.h>
#include "brick.h"
#include "game.h"
#include "ball.h"

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
            brArray[i][j] = initBrick(gridX, gridY, settingsArray[i]);
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
                img = IMG_Load("img/brick.png");
                SDL_BlitSurface(img, NULL, screen, &center);
            }
        }
    }
}

void deathBrick(Brick *br) {
    br->alive = 0;

}

int checkCollide(int x, int y) {
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
                deathBrick(&game.brArray[i][j]);
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

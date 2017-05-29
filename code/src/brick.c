#include <GL/gl.h>
#include <stdio.h>
#include "brick.h"
#include "game.h"

Brick initBrick(int x, int y, int bonus) {
    Brick br;
    br.x = x;
    br.y = y;
    br.bonus = bonus;
    br.alive = 1;
    return br;
}

void initBrickArray(Brick brArray[600][300]) {
    int gridX = 385 - ((brArrayW * 30));
    int gridY = 285 - ((brArrayH * 30));
    
    int i, j;
    for (i = 0; i < game.gridH; i++) {
        for (j = 0; j < game.gridW; j++) {
            brArray[i][j] = initBrick(gridX, gridY, settingsArray[i]);
            gridX += 30;
        }
        gridX = 385 - ((brArrayW * 30) / 2);
        gridY += 30;
    }
}

void drawBrick() {
    int i, j;
    for (i = 0; i < game.gridH; i++) {
        for (j = 0; j < game.gridW; j++) {
            center.x = game.brArray[i][j].x;
            center.y = game.brArray[i][j].y;
            center.h = 30;
            center.w = 30;
            img = IMG_Load("img/brick.png");
            SDL_BlitSurface(img, NULL, screen, &center);
        }   
    }
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

void drawBrick(Brick br) {
    glPushMatrix();
        glTranslatef(br.x, br.y, 0);
        glScalef(50, 50, 0);
        glColor3ub(br.r, br.v, br.b);
        drawSquare();
    glPopMatrix();
}

*/
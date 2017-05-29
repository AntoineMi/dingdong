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

void initBrickArray(Brick **brArray) {
    int gridX = 385 - ((brArrayW * 30) / 2);
    int gridY = 285 - ((brArrayH * 30) / 2);
    
    int i, j;
    for (i = 0; i < game.gridW; i++) {
        for (j = 0; j < game.gridH; j++) {
            brArray[i][j] = initBrick(gridX, gridY, settingsArray[i]);
            gridY += 30;
        }
        gridY = 285 - ((brArrayH * 30) / 2);
        gridX += 30;
    }
}

void drawBrick() {
    int i;
    for (i = 2; i < brCount; i++) {
        center.x = brArray[i].x;
        center.y = brArray[i].y;
        center.h = 30;
        center.w = 30;
        img = IMG_Load("img/brick.png");
        SDL_BlitSurface(img, NULL, screen, &center);
        printf("i = %d\n", i);
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
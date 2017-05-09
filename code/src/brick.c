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


int settingsArray[] = {5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void readSettings() {
    fp = fopen("settings","r");

    if(fp == NULL)
        printf("Error while opening the file.\n");
    
    /*  
    while( ( ch = fgetc(fp) ) != EOF )
        printf("%c",ch);
    */
 
    fclose(fp);

    brArrayW = 0; /* settings.x * 30 */
    brArrayH = 0; /* settings.y * 30 */

    if (brArrayW > MAX_BRICKS_W)
        brArrayW = MAX_BRICKS_W;
    else if (brArrayW < 0)
        brArrayW = 0;

    if (brArrayH > MAX_BRICKS_H)
        brArrayH = MAX_BRICKS_H;
    else if (brArrayH < 0)
        brArrayH = 0;
}

void initBrickArray(int settingsArray) {
    int gridSize = brArrayW * brArrayH, i;
    int gridX = 385 - ((brArrayW * 30) / 2);
    int gridY = 285 - ((brArrayH * 30) / 2);
    
    for (i = 0; i <= gridSize - 1; i++) {
        brArray[i] = initBrick(
            gridX,
            gridY,
            settingsArray[i]
            );
        gridX += 30;
        gridY += 30;
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
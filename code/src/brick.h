#ifndef HEADER_BRICK
#define HEADER_BRICK

#include "ball.h"

#define MAX_BRICKS_W 600 /* 600px */
#define MAX_BRICKS_H 300 /* 300px */
#define MAX_BRICKS 200
#define BRICK_SIZE 30

typedef struct Brick {
    int x, y;
    int alive;
    int bonus;
} Brick;

/* Tableau de paramètres */
int settingsArray[100];

int brArrayW, brArrayH;
int brCount;

/*Brick brArray[] = malloc(sizeof(Brick) * MAX_BRICKS);*/

Brick initBrick(int x, int y, int bonus);
void initBrickArray(Brick brArray[600][300]);
void drawBricks();
void deathBrick(Brick *br, Ball *b);

int checkCollide(int x, int y, Ball *b);

void readSettings();

#endif

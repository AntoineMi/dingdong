#include "game.h"

/**
 * Brique avec une position x, y, un état alive/dead et une couleur RVB
 */
typedef struct Brick {
    int x, y;
    int alive;
    int bonus;
} Brick;

/* Tableau de paramètres */
int settingsArray[MAX_BRICKS];

int brArrayW, brArrayH;


Brick brArray[MAX_BRICKS];
/*Brick brArray[] = malloc(sizeof(Brick) * MAX_BRICKS);*/


Brick initBrick(int x, int y, int bonus);
void initBrickArray(int settingsArray);
void deathBrick();

void readSettings();


/* OpenGL
void drawSquare();
void drawBrick(Brick br);

*/
#ifndef HEADER_BRICK
#define HEADER_BRICK

#define MAX_BRICKS_W 600 /* 600px */
#define MAX_BRICKS_H 300 /* 300px */
#define MAX_BRICKS 200
#define BRICK_SIZE 30

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
int brCount;

/*Brick brArray[] = malloc(sizeof(Brick) * MAX_BRICKS);*/


Brick initBrick(int x, int y, int bonus);
void initBrickArray(Brick **brArray);
void drawBrick();
void deathBrick();

void readSettings();


/* OpenGL
void drawSquare();
void drawBrick(Brick br);

*/

#endif
#ifndef HEADER_BALL
#define HEADER_BALL

/**
 * Balle avec une position x, y et une vitesse
 */
typedef struct Ball {
    int x, y;
    float dx, dy;
    unsigned int speed;
} Ball;

void initBall(Ball *b, int x, int y);
void drawBall(Ball b);
void moveBall(Ball *b);
void deathBall(Ball *b);
void bounceBall(Ball *b, int isSide);

Ball b1, b2;

/* Positions à la prochaine frame */
int targetX;
int targetY;

#endif
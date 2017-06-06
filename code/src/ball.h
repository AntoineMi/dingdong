#ifndef HEADER_BALL
#define HEADER_BALL

typedef struct Ball {
    int x, y;
    float dx, dy;
    int speed;
    int owner;
} Ball;

void initBall(Ball *b, int x, int y, int dy, int owner);
void drawBall(Ball b);
void moveBall(Ball *b);
void deathBall(Ball *b);
void bounceBall(Ball *b, int isSide);

Ball b1, b2;

/* Positions à la prochaine frame */
int targetX;
int targetY;

#endif

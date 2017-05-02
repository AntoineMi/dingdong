/**
 * Balle avec une position x, y et une vitesse
 */
typedef struct Ball {
    int x, y;
    float dx, dy;
    unsigned int speed;
} Ball;

void initBall();
void drawBall();
void moveBall();
void deathBall();
void bounceBall(int surface);

Ball b;

/* Positions à la prochaine frame */
int targetX;
int targetY;
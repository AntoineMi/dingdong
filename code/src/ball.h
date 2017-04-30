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

Ball b;
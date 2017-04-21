#define P_MAX 12

/**
 * Balle avec une position x, y et une vitesse
 */
typedef struct Ball {
    int x, y;
    float dx, dy;
    unsigned int speed;
} Ball;

/**
 * Barre avec une position x, y, une vitesse et une longueur
 */
typedef struct Bar {
    int x, y;
    unsigned int speed;
    unsigned int length;
} Bar;


/**
 * Joueur avec un nom, un score, une vie et un thème
 */
typedef struct Player {
    char name[P_MAX];
    unsigned int health;
    unsigned int theme;
} Player;
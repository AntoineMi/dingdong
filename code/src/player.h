#define P_MAX 12

/**
 * Joueur avec un nom, un score, une vie et un thème
 */
typedef struct Player {
    char name[P_MAX];
    unsigned int health;
    unsigned int theme;
} Player;
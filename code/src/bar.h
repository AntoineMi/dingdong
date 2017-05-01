/**
 * Barre avec une position x, y, une vitesse et une longueur
 */
typedef struct Bar {
    int x, y;
    unsigned int speed;
    unsigned int length;
} Bar;

/**
 * Déplacer la barre sur l'axe x
 * @param bar Barre 1 ou 2
 * @param dir Direction gauche (1) ou droite (0)
 */
void moveBar(Bar *bar, int dir);
void initBars();

Bar bar1;
Bar bar2;
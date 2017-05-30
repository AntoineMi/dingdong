#ifndef HEADER_BAR
#define HEADER_BAR

/**
 * Barre avec une position x, y, une vitesse et une longueur
 */
typedef struct Bar {
    int x, y;
    int speed;
    int length;
    int owner;
} Bar;

/**
 * Déplacer la barre sur l'axe x
 * @param bar Barre 1 ou 2
 * @param dir Direction gauche (1) ou droite (0)
 */
void moveBar(Bar *bar, int dir);

void initBars();
void drawBar(Bar bar);

Bar bar1;
Bar bar2;

#endif

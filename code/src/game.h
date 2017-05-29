#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct Game {
    int gridW, gridH;
    Brick brArray[MAX_BRICKS_W][MAX_BRICKS_H];
} Game;

SDL_Surface *framebuffer;
SDL_Surface *screen;
SDL_Surface *img;
SDL_Rect center;

FILE *fp;

void initGame();
void readSettings(Game *game, int *settingsArray);
#ifndef HEADER_GAME
#define HEADER_GAME

#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "brick.h"

typedef struct Game {
    int gridW, gridH;
    Brick brArray[600][300];
    int theme;
    int ia;
} Game;

Game game;

SDL_Surface *framebuffer;
SDL_Surface *screen;
SDL_Surface *img;
SDL_Rect center;

FILE *fp;

int menu(int *idMenu);
void showMenu(int id);
void readSettings(Game *game, int *settingsArray);

#endif

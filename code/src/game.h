#ifndef HEADER_GAME
#define HEADER_GAME

#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

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
Mix_Music *music;
int loop;

FILE *fp;

void initGame();
int menu(int *idMenu);
void showMenu(int id);
void playMusic(int theme, int title);
void setTheme(int theme);
void readSettings(Game *game, int *settingsArray);
void drawArea();

#endif

#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#define MAX_BRICKS_W 20 /* 600px */
#define MAX_BRICKS_H 10 /* 300px */
#define MAX_BRICKS 200

SDL_Surface *framebuffer;
SDL_Surface *screen;
SDL_Surface *img;
SDL_Rect center;

FILE *fp;

void initGame();
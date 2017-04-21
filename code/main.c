#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "functions.h"

FILE * testFile;

static unsigned int WINDOW_WIDTH = 800;
static unsigned int WINDOW_HEIGHT = 600;
static const unsigned int BIT_PER_PIXEL = 32;

int main(int argc, char** argv) {
    if(-1 == SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Impossible d'initialiser la SDL. Fin du programme.\n");
        return EXIT_FAILURE;
    }
    
    SDL_Surface* screen = NULL;
    if(NULL == (screen = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL, 
        SDL_DOUBLEBUF | SDL_RESIZABLE))) {
        fprintf(stderr, "Impossible d'ouvrir la fenetre. Fin du programme.\n");
        return EXIT_FAILURE;
    }
    SDL_WM_SetCaption("ARKANOPONG", NULL);
    
    /* Création d'une surface SDL dans laquelle le raytracer dessinera */
    SDL_Surface* framebuffer = NULL;
    if(NULL == (framebuffer = SDL_CreateRGBSurface(SDL_SWSURFACE, WINDOW_WIDTH, 
        WINDOW_HEIGHT, BIT_PER_PIXEL, 0, 0, 0, 0))) {
        fprintf(stderr, "Erreur d'allocation pour le framebuffer. Fin du programme.\n");
        return EXIT_FAILURE;
    }
    
    int loop = 1;
    while(loop) {
        /* Nettoyage du framebuffer */
        SDL_FillRect(framebuffer, NULL, SDL_MapRGB(framebuffer->format, 0, 0, 0));
        SDL_BlitSurface(framebuffer, NULL, screen, NULL);
        
        /******************************************
         *               CODE DU JEU              *
         ******************************************/
        
        Ball b;
        b.speed = 1;
        b.x = 0;
        b.y = 0;
        b.dx = 1;
        b.dy = 0;

        SDL_Surface * img = NULL;
            SDL_Rect center;
            center.x = 400;
            center.y = 300;
            center.h = 15;
            center.w = 15;
            img = IMG_Load("img/ball.gif");
            SDL_BlitSurface(img, NULL, screen, &center);

        if(b.dx != 0 || b.dy != 0) {
            b.x += b.dx;
            b.y += b.dy;
        }
        















        /*testFile = fopen ("tests", "w+");
        fprintf(testFile, "%d\n", b.speed);
        fclose(testFile);*/

        /******************************************/

        
        SDL_Flip(screen);
    
        SDL_Event e;
        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT) {
                loop = 0;
                break;
            }
        }
    }
  
    SDL_Quit();
    
    return EXIT_SUCCESS;
}
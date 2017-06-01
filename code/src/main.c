#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "ball.h"
#include "bar.h"
#include "brick.h"
#include "game.h"
#include "player.h"

static unsigned int WINDOW_WIDTH = 1000;
static unsigned int WINDOW_HEIGHT = 600;
static const unsigned int BIT_PER_PIXEL = 32;

/*void reshape() {
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
}*/

int main() {
    
    /* Initialisation SDL */
    if(-1 == SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Impossible d'initialiser la SDL. Fin du programme.\n");
        return EXIT_FAILURE;
    }
    
    /* Création de la fenêtre (screen) */
    if(NULL == (screen = SDL_SetVideoMode(
      WINDOW_WIDTH,
      WINDOW_HEIGHT,
      BIT_PER_PIXEL, 
      SDL_DOUBLEBUF | SDL_RESIZABLE))) {
        fprintf(stderr, "Impossible d'ouvrir la fenetre. Fin du programme.\n");
        return EXIT_FAILURE;
    }
    SDL_WM_SetCaption("ARKANOPONG", NULL);
    
    /* Création d'une surface SDL (framebuffer) dans laquelle le raytracer dessinera */
    SDL_Surface* framebuffer = NULL;
    if(NULL == (framebuffer = SDL_CreateRGBSurface(SDL_SWSURFACE,
      WINDOW_WIDTH, 
      WINDOW_HEIGHT,
      BIT_PER_PIXEL,
      0, 0, 0, 0))) {
        fprintf(stderr, "Erreur d'allocation pour le framebuffer. Fin du programme.\n");
        return EXIT_FAILURE;
    }

    if(-1 == (Mix_OpenAudio(
      44100,
      MIX_DEFAULT_FORMAT,
      MIX_DEFAULT_CHANNELS,
      1024))) {
        fprintf(stderr, "Erreur d'initialisation de l'API Mixer. Fin du programme.\n");
        return EXIT_FAILURE;
   }

    /******************************************
     *               CODE DU JEU              *
     ******************************************/
    
    Uint8 *keyboard = 0; /* tableau de Uint8 */


    
    int settingsArray[] = {9, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    readSettings(&game, settingsArray);

    initPlayers();
    initBall(&b1, 392, 100, 1, 1);
    initBall(&b2, 392, 492, -1, 2);
    initBars();

    game.theme = 0;
    int idMenu = 1;
    int gameStart = 0;

    initBrickArray(game.brArray);
    playMusic(game.theme, 0);

    int loop = 1;
    while(loop) {
        /* Nettoyage du framebuffer */
        SDL_FillRect(framebuffer, NULL, SDL_MapRGB(framebuffer->format, 0, 0, 0));
        SDL_BlitSurface(framebuffer, NULL, screen, NULL);

        SDL_PumpEvents(); /* Récupérer un tableau d'events */
        keyboard = SDL_GetKeyState(NULL);

        /* MENU */

        while (!gameStart) {
            gameStart = menu(&idMenu);
        }

        /* JEU */

            /* Zone de jeu */
            center.x = 800;
            center.y = 0;
            center.h = 200;
            center.w = 600;
            img = IMG_Load("img/bg_ui.png");
            SDL_BlitSurface(img, NULL, screen, &center);


            /* Balles */
            drawBall(b1);
            drawBall(b2);
            
            /* Barres */
            drawBar(bar1);
            drawBar(bar2);

            /* Briques */
            drawBricks();

        /* JEU */


        moveBall(&b1);
        moveBall(&b2);


        /* Déplacement joueur 1 */
        if (keyboard[SDLK_LEFT]) moveBar(&bar1, 1);
        if (keyboard[SDLK_RIGHT]) moveBar(&bar1, 0);

        /* Déplacement joueur 2 */
        if (keyboard['q']) moveBar(&bar2, 1);
        if (keyboard['d']) moveBar(&bar2, 0);

        if (keyboard[SDLK_ESCAPE]) loop = 0;

        /* Contrôles */
        SDL_Event e;
        while(SDL_PollEvent(&e)) {
          if(e.type == SDL_QUIT) {
              loop = 0;
              break;
          }
          
          /* Lors d'un événement souris/clavier */
          switch(e.type) {

            /* Fenêtre */
            case SDL_VIDEORESIZE:
              WINDOW_WIDTH = e.resize.w;
              WINDOW_HEIGHT = e.resize.h;
              break;

            /* Souris */
            case SDL_MOUSEBUTTONUP:
              break;

            /* Clavier */
              
            default:
              break;
          }
        }

        /******************************************/

        /* Afficher à l'écran */
        SDL_Flip(screen);
    } /* fin du loop */
    
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();
    
    return EXIT_SUCCESS;
}

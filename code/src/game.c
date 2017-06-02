#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include "game.h"
#include "brick.h"

void readSettings(Game *game, int *settingsArray) {
    /* READ SETTINGS FROM FILE

    fp = fopen("settings","r");

    if(fp == NULL)
        printf("Error while opening the file.\n");
    
    while( ( ch = fgetc(fp) ) != EOF )
        printf("%c",ch);
    
 
    fclose(fp);
    */

    game->gridW = settingsArray[0];
    game->gridH = settingsArray[1];

    if (game->gridW * BRICK_SIZE > MAX_BRICKS_W) {
        game->gridW = MAX_BRICKS_W / BRICK_SIZE;
    }
    else if (game->gridW < 0) {
        game->gridW = 0;
    }

    if (game->gridH * BRICK_SIZE > MAX_BRICKS_H) {
        game->gridH = MAX_BRICKS_H / BRICK_SIZE;
    }
    else if (game->gridH < 0) {
        game->gridH = 0;
    }
}

void showMenu(int id) {
    center.x = 0;
    center.y = 0;
    center.h = 1000;
    center.w = 600;
    
    if (!game.theme) { /* classic */
        switch (id) {
            case 1:
                img = IMG_Load("img/classic/1.png");
                break;
            case 2:
                img = IMG_Load("img/classic/1_clk.png");
                break;
            case 3:
                img = IMG_Load("img/classic/2_1.png");
                break;
            case 4:
                img = IMG_Load("img/classic/2_2.png");
                break;
            case 5:
                img = IMG_Load("img/classic/3_1.png");
                break;
            case 6:
                img = IMG_Load("img/classic/3_2.png");
                break;
            case 7:
                img = IMG_Load("img/classic/4_1.png");
                break;
            case 8:
                img = IMG_Load("img/classic/4_2.png");
                break;
            case 9:
                img = IMG_Load("img/classic/gameOver.png");
                break;
        }
    }

    else { /* gta */
        switch (id) {
            case 1:
                img = IMG_Load("img/gta/1.png");
                break;
            case 2:
                img = IMG_Load("img/gta/1_clk.png");
                break;
            case 3:
                img = IMG_Load("img/gta/2_1.png");
                break;
            case 4:
                img = IMG_Load("img/gta/2_2.png");
                break;
            case 5:
                img = IMG_Load("img/gta/3_1.png");
                break;
            case 6:
                img = IMG_Load("img/gta/3_2.png");
                break;
            case 7:
                img = IMG_Load("img/gta/4_1.png");
                break;
            case 8:
                img = IMG_Load("img/gta/4_2.png");
                break;
            case 9:
                img = IMG_Load("img/gta/gameOver.png");
                break;
        }
    }

    SDL_BlitSurface(img, NULL, screen, &center);
    SDL_Flip(screen);
}

void playMusic(int theme, int title) {
    if (!title) { /* title */
        if (!theme) {  /* classic */
            music = Mix_LoadMUS("img/classic/title.mp3");
            Mix_PlayMusic(music, -1);
        } else { /* gta */
            music = Mix_LoadMUS("img/gta/title.mp3");
            Mix_PlayMusic(music, -1);
        }
    }
    else { /* game */
        if (!theme) { /* classic */
            music = Mix_LoadMUS("img/classic/game.mp3");
            Mix_PlayMusic(music, -1);
        } else { /* gta */
            music = Mix_LoadMUS("img/gta/game.mp3");
            Mix_PlayMusic(music, -1);
        }
    }
}

int menu(int *idMenu) {
    SDL_Event e;
    SDL_PollEvent(&e);

        if (e.key.keysym.sym == SDLK_ESCAPE) {
            Mix_FreeMusic(music);
            Mix_CloseAudio();
            SDL_Quit();
        }

            switch (*idMenu) {
                /* écran titre */
                case 1:
                    showMenu(1);
                    if (e.key.keysym.sym == SDLK_RETURN) *idMenu = 2;
                    e.key.keysym.sym = SDLK_DELETE;
                    break;
                case 2:
                    e.key.keysym.sym = SDLK_DELETE;
                    showMenu(2);
                    SDL_Delay(100);
                    *idMenu = 3;
                    break;

                /* accès au jeu ou aux thèmes */
                case 3:
                    showMenu(3);
                    if (e.key.keysym.sym == SDLK_RETURN) {
                        e.key.keysym.sym = SDLK_DELETE;
                        *idMenu = 5;
                        break;
                    }
                    if (e.key.keysym.sym == SDLK_DOWN) {
                        e.key.keysym.sym = SDLK_DELETE;
                        *idMenu = 4;
                        break;
                    }
                    break;
                case 4:
                    showMenu(4);
                    if (e.key.keysym.sym == SDLK_RETURN) {
                        e.key.keysym.sym = SDLK_DELETE;
                        *idMenu = 7;
                        break;
                    }
                    if (e.key.keysym.sym == SDLK_UP) {
                        e.key.keysym.sym = SDLK_DELETE;
                        *idMenu = 3;
                        break;
                    }
                    break;

                /* choix du mode de jeu */
                case 5:
                    showMenu(5);
                    if (e.key.keysym.sym == SDLK_RETURN) {
                        printf("1 JOUEUR\n");
                        return 1;
                    }
                    if (e.key.keysym.sym == SDLK_DOWN) {
                        e.key.keysym.sym = SDLK_DELETE;
                        *idMenu = 6;
                        break;
                    }
                    if (e.key.keysym.sym == SDLK_BACKSPACE) {
                        e.key.keysym.sym = SDLK_DELETE;
                        *idMenu = 3;
                        break;
                    }
                    break;
                case 6:
                    showMenu(6);
                    if (e.key.keysym.sym == SDLK_RETURN) {
                        printf("2 JOUEURS\n");
                        return 1;
                    }
                    if (e.key.keysym.sym == SDLK_UP) {
                        *idMenu = 5;
                        e.key.keysym.sym = SDLK_DELETE;
                        break;
                    }
                    if (e.key.keysym.sym == SDLK_BACKSPACE) {
                        e.key.keysym.sym = SDLK_DELETE;
                        *idMenu = 3;
                        break;
                    }
                    break;

                /* choix du thème */
                case 7:
                    showMenu(7);
                    if (e.key.keysym.sym == SDLK_RETURN) {
                        e.key.keysym.sym = SDLK_DELETE;
                        if (!game.theme) {
                            printf("theme is already %d\n", game.theme);
                            break;
                        }
                        else {
                            game.theme++;
                            playMusic(game.theme, 0);
                            printf("theme is now %d\n", game.theme);
                            *idMenu = 1;
                            break;
                        }
                    }
                    if (e.key.keysym.sym == SDLK_DOWN) {
                        e.key.keysym.sym = SDLK_DELETE;
                        *idMenu = 8;
                        break;
                    }
                    if (e.key.keysym.sym == SDLK_BACKSPACE) {
                        e.key.keysym.sym = SDLK_DELETE;
                        *idMenu = 3;
                        break;
                    }
                    break;
                case 8:
                    showMenu(8);
                    if (e.key.keysym.sym == SDLK_RETURN) {
                        e.key.keysym.sym = SDLK_DELETE;
                        if (game.theme) {
                            printf("theme is already %d\n", game.theme);
                            break;
                        }
                        else {
                            game.theme--;
                            playMusic(game.theme, 0);
                            printf("theme is now %d\n", game.theme);
                            *idMenu = 1;
                            break;
                        }
                    }
                    if (e.key.keysym.sym == SDLK_UP) {
                        e.key.keysym.sym = SDLK_DELETE;
                        *idMenu = 7;
                        break;
                    }
                    if (e.key.keysym.sym == SDLK_BACKSPACE) {
                        e.key.keysym.sym = SDLK_DELETE;
                        *idMenu = 3;
                        break;
                    }
                    break;

                default:
                    break;
            }
            return 0;
}
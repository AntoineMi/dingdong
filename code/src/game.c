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
#ifndef _GAME_CONTROLER_H_
#define _GAME_CONTROLER_H_
#include "config.h"

typedef enum{
    GAME_START,
    GAME_PAUSE,
    GAME_STOP
}GameStates;

typedef struct{
    GameStates state;
    int HEIGHT;
    int WIDTH;
    char title[TITLE_SIZE];
}GameConfig;

void init_game(GameConfig * config);

#endif
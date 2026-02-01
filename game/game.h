#ifndef _GAME_H_
#define _GAME_H_
#include "config.h"

typedef struct SDLContext SDLContext;

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
void update_game(GameConfig * config, SDLContext * context);

#endif
#ifndef _GAME_H_
#define _GAME_H_
#include "config.h"

typedef struct SDLContext SDLContext;
typedef struct Player Player;
typedef struct Input_type Input_type;

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

typedef struct{
    Player * player;
}GameObjects;

void init_game(GameConfig * config,GameObjects * objects);
void init_game_config(GameConfig * config);
void init_game_objects(GameObjects * objects, GameConfig * config);

void update_game(GameConfig * config, SDLContext * context, GameObjects * objects);

void game_shutdown(GameObjects * objects);

#endif
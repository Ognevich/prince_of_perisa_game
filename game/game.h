#ifndef _GAME_H_
#define _GAME_H_
#include "config.h"
#include "scene/scene.h"
#include <stdbool.h>

typedef struct SDLContext   SDLContext;
typedef struct Player       Player;
typedef struct Wall         Wall;
typedef struct Input_type   Input_type;

typedef enum{
    GAME_START,
    GAME_PAUSE,
    GAME_STOP
}GameStates;

typedef struct{
    GameStates state;

    SceneType  scene_type;
    bool       scene_changed;

    int        HEIGHT;
    int        WIDTH;
    char       title[TITLE_SIZE];
}GameConfig;

void init_game(GameConfig * config,Player * player);
void init_game_config(GameConfig * config);
void init_player(Player * player);

void update_game(GameConfig * config, SDLContext * context, Player * player);

void game_shutdown();

#endif
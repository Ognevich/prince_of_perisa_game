#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include <string.h>
#include <stdlib.h>
#include <SDL3/SDL.h>
#include "../platform/sdl.h"
#include "../graphics/renderer.h"
#include "player/player.h"
#include "../input/input.h"

void init_game(GameConfig * config, GameObjects * objects)
{
    init_game_config(config);
    init_game_objects(objects,config);
}

void init_game_config(GameConfig * config)
{
    config->state = GAME_START; 
    config->HEIGHT = 576;
    config->WIDTH = 1024;
    strcpy(config->title, "Prince of Persia");
}

void init_game_objects(GameObjects * objects, GameConfig * config)
{
    rgba color = {255,127,0,255};
    Player* player = create_player(config->WIDTH  / 2.0f,
                                   config->HEIGHT / 2.0f,
                                   50, 45,              
                                   color, 0.0f, 0.0f);

    objects->player = player;
}

void update_game(GameConfig * config, SDLContext * context, GameObjects * objects)
{

    Input_type input;

    while (config->state != GAME_STOP)
    {
        poll_events(config);
        proccess_input(&input);
        update_player(objects->player, &input, config);
        render(context,objects);
    }
}

void game_shutdown(GameObjects * objects)
{
    free(objects->player);
}
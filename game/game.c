#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include <string.h>
#include <stdlib.h>
#include <SDL3/SDL.h>
#include "../platform/sdl.h"
#include "../graphics/renderer.h"
#include "player/player.h"
#include "../input/input.h"

void init_game(GameConfig * config,Player * player)
{
    init_game_config(config);
    init_player(player, config);
}

void init_game_config(GameConfig * config)
{
    config->state = GAME_START; 
    config->HEIGHT = 576;
    config->WIDTH = 1024;
    strcpy(config->title, "Prince of Persia");
}

void init_player(Player * player, GameConfig * config)
{
    rgba color = {255,127,0,255};
    create_player(player, config->WIDTH  / 2.0f,
                                   config->HEIGHT / 2.0f,
                                   50, 45,              
                                   color, 0.0f, 0.0f);
}

void update_game(GameConfig * config, SDLContext * context, Player * player)
{

    Input_type input;

    while (config->state != GAME_STOP)
    {
        poll_events(config);
        proccess_input(&input);
        update_player(player, &input, config);
        render(context,player);
    }
}

void game_shutdown(GameObjects * scene)
{

}
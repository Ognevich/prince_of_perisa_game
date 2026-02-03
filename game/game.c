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
    init_player(player);
}

void init_game_config(GameConfig * config)
{
    config->state = GAME_START; 
    config->HEIGHT = GAME_HEIGHT;
    config->WIDTH = GAME_WIDTH;
    config->scene_type = SCENE_LEVE1;
    strcpy(config->title, "Prince of Persia");
}

void init_player(Player * player)
{
    rgba color = {255,127,0,255};
    create_player(player, GAME_WIDTH / 2.0f,
                                   GAME_HEIGHT / 2.0f,
                                   50, 45,              
                                   color, 0.0f, 0.0f);
}

void update_game(GameConfig * config, SDLContext * context, Player * player)
{

    Input_type input;
    Uint32 frameStart;
    int frameTime;

    while (config->state != GAME_STOP)
    {
        switch (config->scene_type)
        {
        case SCENE_LEVE1:
        {
            frameStart = SDL_GetTicks();
            poll_events(config);
            proccess_input(&input);
            update_player(player, &input);
            render(context,player);

            frameTime = SDL_GetTicks() - frameStart;
            if (FRAME_DELAY > frameTime)
            SDL_Delay(FRAME_DELAY - frameTime);
            break;
        }
        default:
            break;
        }
    }
}

void game_shutdown()
{

}
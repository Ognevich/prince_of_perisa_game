#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include <string.h>
#include <SDL3/SDL.h>
#include "../platform/sdl.h"
#include "../graphics/renderer.h"
#include "player/player.h"

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

    while (config->state != GAME_STOP)
    {
        SDL_Event event;

        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                config->state = GAME_STOP;   
            }
        }
        SDL_SetRenderDrawColor(context->renderer, 0, 0, 0, 255);
        SDL_RenderClear(context->renderer);
        draw_player(context,objects->player);
        SDL_RenderPresent(context->renderer);

        SDL_Delay(FRAME_RATE);
    }

    free_player(objects->player);
}
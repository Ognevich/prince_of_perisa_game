#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include <string.h>
#include <SDL3/SDL.h>
#include "../platform/sdl.h"
#include "player/player.h"
#include "../graphics/renderer.h"

void init_game(GameConfig * config)
{
    config->state = GAME_START; 
    config->HEIGHT = 576;
    config->WIDTH = 1024;
    strcpy(config->title, "Prince of Persia");
}

void update_game(GameConfig * config, SDLContext * context)
{

    rgba color = {255,255,0,255};
Player* player = create_player(config->WIDTH  / 2.0f,
                            config->HEIGHT / 2.0f,
                            50, 50,              
                            color, 0.0f, 0.0f);

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
        draw_player(context,player);
        SDL_RenderPresent(context->renderer);

        SDL_Delay(FRAME_RATE);
    }

    free_player(player);
}
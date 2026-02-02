#include "input.h"
#include <stdint.h>
#include <stdbool.h>
#include <SDL3/SDL.h>
#include "../game/player/player.h"

void proccess_input(Input_type * type)
{
    const bool* keys = SDL_GetKeyboardState(NULL);

    type->left  =  keys[SDL_SCANCODE_A];   
    type->right =  keys[SDL_SCANCODE_D];   
}

void poll_events(GameConfig * cfg)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT)
            {
                cfg->state = GAME_STOP;   
            }
    }
}
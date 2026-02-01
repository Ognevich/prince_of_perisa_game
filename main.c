#include <stdio.h>
#include <SDL3/SDL_main.h>
#include "core/gameControler.h"
#include "platform/sdl.h"

int main(int argc, char* argv[])
{
    SDLContext context;
    GameConfig config; 
    init_game(&config); 
    if(!sdl_init(&context,&config))
        return 1;

    while (config.state != GAME_STOP)
    {
        SDL_Event event;

        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                config.state = GAME_STOP;   
            }
        }

    }

    sdl_shutdown(&context);

    return 0;
}
#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "engine/gameControler.h"

int main(int argc, char* argv[])
{

    GameConfig config; 
    initGame(&config);

    SDL_Window * window;

    const char * title = "Prince Of Persia";

    window = SDL_CreateWindow(title,config.WIDTH,config.HEIGHT,SDL_WINDOW_OPENGL);

    if (!window)
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

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
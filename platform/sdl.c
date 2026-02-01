#include "sdl.h"

int sdl_init(SDLContext * context, GameConfig * cfg)
{
    SDL_Init(SDL_INIT_VIDEO);
    context->window = SDL_CreateWindow(cfg->title,cfg->WIDTH,cfg->HEIGHT,SDL_WINDOW_OPENGL);
    if (!context->window){
        SDL_Quit();
        return 0;
    }

    context->renderer = SDL_CreateRenderer(context->window, -1);
    if (!context->renderer){
        SDL_DestroyWindow(context->window);
        return 0;
    }

    return 1;
}

void sdl_shutdown(SDLContext * context)
{
    SDL_DestroyWindow(context->window);
    SDL_Quit();

}
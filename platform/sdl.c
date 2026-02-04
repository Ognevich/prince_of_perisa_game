#include "sdl.h"

int sdl_init(SDLContext * context, GameConfig * cfg)
{
    SDL_Init(SDL_INIT_VIDEO);
    context->window = SDL_CreateWindow(cfg->title,cfg->WIDTH,cfg->HEIGHT,SDL_WINDOW_OPENGL);
    if (!context->window){
        SDL_Quit();
        return 0;
    }
    
    context->renderer = SDL_CreateRenderer(context->window, NULL);
    if (!context->renderer){
        SDL_DestroyWindow(context->window);
        return 0;
    }
    SDL_SetRenderDrawBlendMode(context->renderer, SDL_BLENDMODE_BLEND);

    return 1;
}

void sdl_shutdown(SDLContext * context)
{
    SDL_DestroyWindow(context->window);
    SDL_Quit();

}

void limit_frame(Uint32 frameStart, int targetFrameTime)
{
    Uint32 frameTime = SDL_GetTicks() - frameStart;
    if (frameTime < targetFrameTime)
        SDL_Delay(targetFrameTime - frameTime);
}
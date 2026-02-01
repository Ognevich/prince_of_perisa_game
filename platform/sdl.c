#include "sdl.h"

int sdl_init(SDLContext * context, GameConfig * cfg)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window * window;
    window = SDL_CreateWindow(cfg->title,cfg->WIDTH,cfg->HEIGHT,SDL_WINDOW_OPENGL);
    if (!window)
        return 0;
    return 1;
}

void sdl_shutdown(SDLContext * context)
{
    SDL_DestroyWindow(context->window);
    SDL_Quit();

}
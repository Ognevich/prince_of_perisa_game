#ifndef _SDL_H_
#define _SDL_H_
#include <SDL3/SDL.h>
#include "../game/game.h"

struct SDLContext{
    SDL_Window * window;
    SDL_Renderer * renderer;
};

int     sdl_init(SDLContext * context, GameConfig * cfg);
void    sdl_shutdown(SDLContext * context);
void    limit_frame(Uint32 frameStart, int targetFrameTime);
float   calculate_delta_time(Uint32 * lastFrameTime);
#endif
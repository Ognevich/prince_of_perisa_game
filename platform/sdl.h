#ifndef _SDL_H_
#define _SDL_H_
#include <SDL3/SDL.h>
#include "../core/gameControler.h"

typedef struct{
    SDL_Window * window;
    SDL_Renderer * renderer;
}SDLContext;

int     sdl_init(SDLContext * context, GameConfig * cfg);
void    sdl_shutdown(SDLContext * context);

#endif
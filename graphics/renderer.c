#include "renderer.h"
#include "../game/player/player.h"
#include <SDL3/SDL.h>

void render(SDLContext * context, GameObjects* objects)
{
    SDL_SetRenderDrawColor(context->renderer, 0, 0, 0, 255);
    SDL_RenderClear(context->renderer);
    draw_player(context,objects->player);
    SDL_RenderPresent(context->renderer);
    SDL_Delay(FRAME_RATE);

}
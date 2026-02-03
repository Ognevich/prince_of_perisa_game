#include "renderer.h"
#include "../game/player/player.h"
#include <SDL3/SDL.h>

void render(SDLContext * context, Player * player)
{
    SDL_SetRenderDrawColor(context->renderer, 0, 0, 0, 255);
    SDL_RenderClear(context->renderer);
    draw_player(context,player);
    SDL_RenderPresent(context->renderer);
    SDL_Delay(FRAME_RATE);

}

void draw_player(SDLContext * context, Player * plr)
{
    SDL_SetRenderDrawColor(context->renderer, plr->color.r, plr->color.g, plr->color.b, plr->color.a);
    SDL_FRect rect = {plr->x, plr->y, plr->width, plr->height};
    SDL_RenderFillRect(context->renderer, &rect);
}
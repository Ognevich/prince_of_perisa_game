#include "renderer.h"
#include "../game/player/player.h"
#include "../game/static_objects/wall.h"
#include "../game/scene/scene.h"
#include <SDL3/SDL.h>

static void draw_player(SDLContext * context, Player * plr)
{
    SDL_SetRenderDrawColor(context->renderer, plr->color.r, plr->color.g, plr->color.b, plr->color.a);
    SDL_FRect rect = {plr->x, plr->y, plr->width, plr->height};
    SDL_RenderFillRect(context->renderer, &rect);
}

static void draw_scene(SDLContext * context, GameScene * scene)
{
    for (int i = 0; i < scene->wallsCount; i++)
    {
        Wall *wall = &scene->walls[i];
        SDL_SetRenderDrawColor(context->renderer, wall->color.r,wall->color.g,wall->color.b,wall->color.a);
        SDL_FRect rect = {wall->x, wall->y, wall->w, wall->h};
        SDL_RenderFillRect(context->renderer, &rect);
    }
}

static void clear_screen(SDLContext * context, rgba color)
{
    SDL_SetRenderDrawColor(context->renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(context->renderer);
}

static void present_screen(SDLContext * context)
{
    SDL_RenderPresent(context->renderer);
}

void render(SDLContext * context, Player * player, GameScene * scene)
{
    rgba color = {0,0,0,255};
    clear_screen(context, color);
    draw_player(context,player);
    draw_scene(context, scene);
    present_screen(context);

}
#include "player.h"
#include <stdlib.h>

Player * create_player(float x, float y, float height, float width, rgba c, float dx, float dy)
{
    Player * player = malloc(sizeof(Player));

    player->x = x;
    player->y = y;
    player->width = width;
    player->height = height;
    player->dx = dx;
    player->dy = dy;
    player->color = c;

    return player;
}

void free_player(Player * player)
{
    free(player);
}

void draw_player(SDLContext * context, Player * player)
{
    SDL_SetRenderDrawColor(context->renderer, 255, 0, 0, 255);
    SDL_FRect rect = {20.0f, 20.0f, 100.0f, 50.0f};
    SDL_RenderFillRect(context->renderer, &rect);
}
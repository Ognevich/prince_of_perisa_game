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

void draw_player(SDLContext * context, Player * plr)
{
    SDL_SetRenderDrawColor(context->renderer, plr->color.r, plr->color.g, plr->color.b, plr->color.a);
    SDL_FRect rect = {plr->x, plr->y, plr->width, plr->height};
    SDL_RenderFillRect(context->renderer, &rect);
}

void update_player_pos(SDLContext * context,Player * player)
{
    
}
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


static void update_player_pos(Player * player, Input_type * type)
{
    if (type->left) player->x -= DEFAULT_SPEED;
    if (type->right) player->x += DEFAULT_SPEED;
}

static void checkPlayerCollision(Player * p, GameConfig * cfg)
{
    if (p->x < 0) p->x = 0;
    if (p->x + p->width > cfg->WIDTH) p->x = cfg->WIDTH - p->width;

}

void update_player(Player * player, Input_type * type, GameConfig * cfg)
{
    update_player_pos(player,type);
    checkPlayerCollision(player, cfg);
}
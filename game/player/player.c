#include "player.h"
#include <stdlib.h>
#include "../config.h"

void create_player(Player * player, float x, float y, float height, float width, rgba c, float dx, float dy)
{

    player->x = x;
    player->y = y;
    player->width = width;
    player->height = height;
    player->dx = dx;
    player->dy = dy;
    player->color = c;
}

void free_player(Player * player)
{
    free(player);
}

static void update_player_pos(Player * player, Input_type * type)
{
    if (type->left) player->x -= DEFAULT_SPEED;
    if (type->right) player->x += DEFAULT_SPEED;
}

void update_player(Player * player, Input_type * type)
{
    update_player_pos(player,type);
}
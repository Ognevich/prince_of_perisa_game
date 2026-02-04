#include "player.h"
#include <stdlib.h>
#include "../config.h"
#include "stdbool.h"

void create_player(Player * player, float x, float y, float height, float width, rgba c, float dx, float dy)
{

    player->x = x;
    player->y = y;
    player->width = width;
    player->height = height;
    player->dx = dx;
    player->dy = dy;
    player->color = c;
    player->v_speed = 0;
    player->on_ground = false;
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

void update_player(Player * p, Input_type * type, CollisionType coll_type)
{


    switch (coll_type)
    {
    case NONE_COLL:
    {
        p->v_speed += GRAVITY;
        break;
    }
    case FlOOR_COLL:
    {
        // p->y = col.wall->y - p->height;
        p->v_speed = 0;
        p->on_ground = true;
        update_player_pos(p,type);
        break;
    }
    default:
        break;
    }

    p->y += p->v_speed;

}
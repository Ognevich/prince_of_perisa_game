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

void update_player(Player * p, Input_type * type)
{
    update_player_pos(p,type);

    p->v_speed += GRAVITY;
    p->y += p->v_speed;
}

void resolve_player_collision(Player *p, CollisionObject coll_obj)
{
    switch (coll_obj.type)
    {
    case FlOOR_COLL:
    {
        if (coll_obj.wall)
        {
            p->y = coll_obj.wall->y - p->height; 
            p->v_speed = 0;
            p->on_ground = true;
        }
        break;
    }

    case NONE_COLL:
    default:
    {
        p->on_ground = false;
        break;
    }
    }
}
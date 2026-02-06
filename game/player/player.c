#include "player.h"
#include <stdlib.h>
#include <stdio.h>
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

    player->health = MAX_HEALTH;
    player->damage_timer = 0.0f;
}

void free_player(Player * player)
{
    free(player);
}

static void update_player_pos(Player * player, Input_type * type)
{
    if (type->left) player->x -= DEFAULT_SPEED;
    if (type->right) player->x += DEFAULT_SPEED;

    if (type->jump && player->on_ground)
    {
        player->v_speed = -JUMP_SPEED;
        player->on_ground = false;
    }
}

void update_player(Player * p, GameConfig * config , Input_type * type)
{
    update_player_pos(p,type);

    p->v_speed += GRAVITY;
    p->y += p->v_speed;

    if (p->damage_timer > 0)
        p->damage_timer -= config->delta_time;
}

void resolve_player_collision(Player *p, CollisionObject coll_obj)
{
    if (coll_obj.is_floor && coll_obj.floor_wall)
    {
        p->y = coll_obj.floor_wall->y - p->height;
        p->v_speed = 0;
        p->on_ground = true;
    }
    else {
        p->on_ground = false;
    }

    if (coll_obj.is_left && coll_obj.left_wall && 
        !(coll_obj.is_floor && coll_obj.floor_wall == coll_obj.left_wall))
    {
        p->x = coll_obj.left_wall->x + coll_obj.left_wall->w;
    }

    if (coll_obj.is_right && coll_obj.right_wall &&
        !(coll_obj.is_floor && coll_obj.floor_wall == coll_obj.right_wall))
    {
        p->x = coll_obj.right_wall->x - p->width;
    }
    if (coll_obj.is_top && coll_obj.top_wall)
    {
        p->y = coll_obj.top_wall->y + coll_obj.top_wall->h + 0.1f;
        p->v_speed = 0; 

    }

    // ПЕРЕНЕСТИ ВІД КОЛІЗІЇ В ОКРЕМУ СИСТЕМУ
    if (coll_obj.is_spike && p->damage_timer <= 0.0f)
    {
        p->health -= 20;
        p->damage_timer = 0.5f; 
        printf("damage_timer: %.3f, health: %f\n", p->damage_timer, p->health);
    }
}
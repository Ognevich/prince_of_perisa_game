#include "player.h"
#include <stdlib.h>
#include <stdio.h>
#include "../config.h"
#include "stdbool.h"
#include <math.h>

void create_player(Player * player, float x, float y, float height, float width, rgba c, float dx, float dy)
{

    player->x            = x;
    player->y            = y;
    player->width        = width;
    player->height       = height;
    player->dx           = dx;
    player->dy           = dy;
    player->knockback_x  = 0.0f;
    player->knockback_y  = 0.0f;
    
    player->color        = c;

    player->on_ground    = false;

    player->health       = MAX_HEALTH;
    player->damage_timer = 0.0f;
}

void free_player(Player * player)
{
    free(player);
}

void update_player_velocity(Player * player, Input_type * type, GameConfig * config)
{
    player->dx = 0;

    if (type->left) player->dx -= DEFAULT_SPEED;
    if (type->right) player->dx += DEFAULT_SPEED;

    if (type->jump && player->on_ground)
    {
        player->dy = -JUMP_SPEED;
        player->on_ground = false;
    }

    player->dy += GRAVITY;

    player->dx += player->knockback_x;
    player->dy += player->knockback_y;

    player->knockback_x *= 0.85f;
    player->knockback_y *= 0.85f;

    if (player->damage_timer > 0)
        player->damage_timer -= config->delta_time;
}

void move_x(Player * p)
{
    p->x += p->dx;
}

void move_y(Player * p)
{
    p->dy += GRAVITY;
    p->y += p->dy;
}

void resolve_player_collisionY(Player * p,CollisionObject collY)
{
    if (collY.is_floor && collY.floor_wall)
    {
        p->y = collY.floor_wall->y - p->height;
        p->dy = 0;
        p->on_ground = true;
    }
    else {
        p->on_ground = false;
    }

    if (collY.is_top && collY.top_wall)
    {
        p->y = collY.top_wall->y + collY.top_wall->h + 0.1f;
        p->dy = 0; 

    }

}

void resolve_player_collisionX(Player *p, CollisionObject collX)
{
    if (collX.is_left && collX.left_wall)
    {
        p->x = collX.left_wall->x + collX.left_wall->w;
    }

    if (collX.is_right && collX.right_wall)
    {
        p->x = collX.right_wall->x - p->width;
    }
}

void apply_damage(Player * p, float damage)
{
    p->health -= damage;
    printf("damage_timer: %.3f, health: %f\n", p->damage_timer, p->health);
}

void apply_knockback(Player *p, StaticObject * obj)
{
    float player_center_x = p->x + p->width / 2.0f;
    float spike_center_x  = obj->x + obj->w / 2.0f;

    float dx = player_center_x - spike_center_x;

    float force_x = 12.0f;
    float force_y = 2.0f;

    p->knockback_x = (dx > 0) ? force_x : -force_x;

    p->knockback_y = -force_y;
}
#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <stdint.h>
#include "../../graphics/renderer.h"
#include "../../platform/sdl.h"
#include "../../input/input.h"
#include "../config.h"
#include "../collisions/collision_types.h"

struct Player{
    float x,y;
    float height,width;
    rgba color;
    float dx, dy;
    
    bool on_ground;

    float health;
    float damage_timer;
};

void create_player(Player * player, float x, float y, float height, float width, rgba c, float dx, float dy);
void free_player(Player * player);

void update_player_velocity(Player * player, Input_type * type, GameConfig * config);
void move_x(Player * p);
void move_y(Player * p);

void resolve_player_collisionY(Player * player,CollisionObject collY);
void resolve_player_collisionX(Player * player,CollisionObject collX);

#endif
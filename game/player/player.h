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
    float v_speed;
    rgba color;
    float dx, dy;
    
    bool on_ground;

    float health;
    float damage_timer;
};

void create_player(Player * player, float x, float y, float height, float width, rgba c, float dx, float dy);
void free_player(Player * player);

void update_player(Player * p, GameConfig * config , Input_type * type);
void resolve_player_collision(Player *p, CollisionObject coll_obj);

#endif
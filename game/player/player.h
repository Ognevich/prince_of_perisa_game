#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <stdint.h>
#include "../../graphics/renderer.h"
#include "../../platform/sdl.h"
#include "../../input/input.h"
#include "../config.h"

struct Player{
    float x,y;
    float height,width;
    float v_speed;
    rgba color;
    float dx, dy;
    
    bool on_ground;
};

void create_player(Player * player, float x, float y, float height, float width, rgba c, float dx, float dy);
void free_player(Player * player);

void update_player(Player * player, Input_type * type, CollisionType coll_type);


#endif
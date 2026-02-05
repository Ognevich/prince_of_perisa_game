#ifndef _COLLISIONS_TYPES_H_
#define _COLLISIONS_TYPES_H_
#include "../static_objects/objects.h"

typedef struct {
    bool is_floor;
    bool is_left;
    bool is_right;
    bool is_top;

    bool is_spike;

    StaticObject * floor_wall;
    StaticObject * left_wall;
    StaticObject * right_wall;
    StaticObject * top_wall;
} CollisionObject;

#endif

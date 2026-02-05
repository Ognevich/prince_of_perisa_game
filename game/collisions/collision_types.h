#ifndef _COLLISIONS_TYPES_H_
#define _COLLISIONS_TYPES_H_
#include "../static_objects/wall.h"

typedef struct {
    bool is_floor;
    bool is_left;
    bool is_right;
    bool is_top;

    Wall * floor_wall;
    Wall * left_wall;
    Wall * right_wall;
    Wall * top_wall;
} CollisionObject;

#endif

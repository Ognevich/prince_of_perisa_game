#ifndef _COLLISIONS_TYPES_H_
#define _COLLISIONS_TYPES_H_
#include "../static_objects/wall.h"

typedef struct {
    bool is_floor;
    bool is_left;
    bool is_right;

    Wall * floor_wall;
    Wall * left_wall;
    Wall * right_wall;
} CollisionObject;

#endif

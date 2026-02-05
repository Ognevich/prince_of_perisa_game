#ifndef _COLLISIONS_TYPES_H_
#define _COLLISIONS_TYPES_H_
#include "../static_objects/wall.h"

typedef enum{
    FlOOR_COLL,
    WALL_COLL,
    NONE_COLL
}CollisionType;

typedef struct{
    Wall * wall;
    CollisionType type;
}CollisionObject;


#endif

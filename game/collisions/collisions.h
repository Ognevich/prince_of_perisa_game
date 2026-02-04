#ifndef _COLLISIONS_H_
#define _COLLISIONS_H_
#include "../player/player.h"
#include "../scene/scene.h"

typedef enum{
    FlOOR_COLL,
    WALL_COLL,
    NONE_COLL
}CollisionType;


CollisionType checkCollision(Player * p, GameScene * scene);

#endif
#ifndef _COLLISIONS_H_
#define _COLLISIONS_H_
#include "../player/player.h"
#include "../scene/scene.h"
#include "collision_types.h"
#include "../static_objects/objects.h"

CollisionObject checkCollision(Player * p, GameScene * scene);

#endif
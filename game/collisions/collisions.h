#ifndef _COLLISIONS_H_
#define _COLLISIONS_H_
#include "../player/player.h"
#include "../scene/scene.h"
#include "collision_types.h"
#include "../static_objects/objects.h"

CollisionObject check_y_collision(Player * player,GameScene * scene);
CollisionObject check_x_collision(Player * player,GameScene * scene);
StaticObject *  check_damage_coliision(Player * player, GameScene * scene);
#endif
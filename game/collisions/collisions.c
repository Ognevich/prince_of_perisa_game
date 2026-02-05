#include "collisions.h"
#include <stdbool.h>
#include <stdio.h>

static bool check_floor_collision(Player *p , GameScene * scene, CollisionObject * object)
{   

    for (int i = 0; i < scene->wallsCount; i++)
    {
        Wall * w = &scene->walls[i];

        bool horizontal_overlap = 
        p->x + p->width > w->x &&
        p->x < w->x + w->w;

        bool falling = p->v_speed>=0;


        bool on_top =
            falling &&
            p->y + p->height >= w->y &&
            p->y + p->height - p->v_speed <= w->y;

        if (horizontal_overlap && on_top)
            {
                object->wall = w;
                return true;
            }
    }
    return false;
}

CollisionObject checkCollision(Player * p, GameScene * scene)
{
    
    CollisionObject object = {0};

    if (check_floor_collision(p,scene, &object))
        {
            printf("Wall collision worked\n");
            object.type = FlOOR_COLL;
            return object;
        }

    object.wall = NULL;
    object.type = NONE_COLL;

    return object;
}
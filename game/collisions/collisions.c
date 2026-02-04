#include "collisions.h"
#include "../static_objects/wall.h"
#include <stdbool.h>
#include <stdio.h>

static bool check_floor_collision(Player *p , GameScene * scene)
{   
    const float epsilon = 0.1f;

    for (int i = 0; i < scene->wallsCount; i++)
    {
        Wall * w = &scene->walls[i];

        bool horizontal_overlap = 
        p->x + p->width > w->x &&
        p->x < w->x + w->w;

        bool on_top = p->y + p->height >= w->y && 
            p->y + p->height <= w->y + epsilon;
        
        if (horizontal_overlap && on_top)
            return true;
    }
    return false;
}

CollisionType checkCollision(Player * p, GameScene * scene)
{
    
    if (check_floor_collision(p,scene))
        {
            printf("Wall collision worked\n");
            return FlOOR_COLL;
        }

    return NONE_COLL;
}
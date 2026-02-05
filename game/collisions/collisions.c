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
                object->floor_wall = w;
                return true;
            }
    }
    return false;
}

static bool check_left_wall_collision(Player *p, GameScene *scene, CollisionObject *obj)
{
    float y_bottom = p->y + p->height;
    float y_top = p->y + p->height - 5.0f; 

    for (int i = 0; i < scene->wallsCount; i++)
    {
        Wall *w = &scene->walls[i];

        bool vertical_overlap =
            (y_bottom > w->y) &&
            (y_top < w->y + w->h) &&
            (w->y + w->h > p->y + p->height - 1.0f);

        bool touching_left = 
            p->x <= w->x + w->w &&
            p->x >= w->x;

        if (vertical_overlap && touching_left)
        {
            obj->is_left = true;
            obj->left_wall = w;
            return true;
        }
    }
    return false;
}

static bool check_right_wall_collision(Player * p, GameScene * scene, CollisionObject * obj)
{
    const float bottom_height = 5.0f; 

    float y_bottom = p->y + p->height;
    float y_top = y_bottom - bottom_height;

    for (int i = 0; i < scene->wallsCount; i++)
    {
        Wall *w = &scene->walls[i];

        bool vertical_overlap =
            (y_bottom > w->y) &&
            (y_top < w->y + w->h) &&
            (w->y + w->h > p->y + p->height - 1.0f);

        bool touching_right = 
            p->x + p->width >= w->x &&  
            p->x <= w->x + w->w;           

        if (vertical_overlap && touching_right)
        {
            obj->is_right = true;
            obj->right_wall = w;
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
        printf("floor collision\n");
        object.is_floor = true;
    }
    if (check_left_wall_collision(p,scene, &object))
    {
        printf("left collision\n");
        object.is_left = true;
    }
    if (check_right_wall_collision(p,scene, &object))
    {
        printf("right collision\n");
        object.is_right = true;
    }

    return object;
}
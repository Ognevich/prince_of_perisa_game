#include "collisions.h"
#include <stdbool.h>
#include <stdio.h>


static inline bool is_spike(const StaticObject *object)
{
    return object->type == SPIKE_OBJ;
}

static bool check_floor_collision(Player *p, GameScene *scene, CollisionObject *object)
{   

    StaticObject * closer_obj = NULL;
    float closer_obj_y = 999999;

    for (int i = 0; i < scene->obj_count; i++)
    {
        StaticObject *w = &scene->obj[i];

        bool horizontal_overlap = 
            p->x + p->width > w->x &&
            p->x < w->x + w->w;

        bool falling = p->dy >= 0;

        bool on_top =
            falling &&
            p->y + p->height >= w->y &&
            p->y + p->height - p->dy <= w->y;

        if (horizontal_overlap && on_top)
        {
            if (w->y < closer_obj_y)
            {
                closer_obj_y = w->y;
                closer_obj = w;
            }
        }
    }
    if (closer_obj)
    {
        object->floor_wall = closer_obj;
        return true;
    }
    return false;
}

bool check_top_collision(Player *p, GameScene *scene, CollisionObject *object)
{
    for (int i = 0; i < scene->obj_count; i++)
    {
        StaticObject *w = &scene->obj[i];

        bool horizontal_overlap = 
            p->x + p->width > w->x &&
            p->x < w->x + w->w;

        bool moving_up = p->dy < 0;

        bool touch_top = 
            moving_up &&
            (p->y + p->dy) <= (w->y + w->h) &&  
            p->y >= w->y + w->h;                      

        if (horizontal_overlap && touch_top)
        {
            object->top_wall = w;
            return true;
        }
    }
    return false;
}

static bool check_left_wall_collision(Player *p, GameScene *scene, CollisionObject *obj)
{
    const float bottom_margin = 5.0f;
    const float floor_tolerance = 1.0f; 
    
    float y_bottom = p->y + p->height;
    float y_top = y_bottom - bottom_margin;

    StaticObject * closer_obj = NULL;
    float closer_obj_x = -999999;

    for (int i = 0; i < scene->obj_count; i++)
    {
        StaticObject *w = &scene->obj[i];

        bool vertical_overlap =
            (y_bottom > w->y) &&
            (y_top < w->y + w->h);

        bool touching_left = 
            p->x < w->x + w->w &&         
            p->x + p->width > w->x + w->w - 1.0f;


        if (obj->floor_wall && w == obj->floor_wall)
        {
            bool standing_on_top = p->y + p->height <= w->y + floor_tolerance;
            if (standing_on_top)
            {
                continue;
            }
        }

        if (vertical_overlap && touching_left)
        {
            float right_edge = w->x + w->w;

            if (right_edge > closer_obj_x)
            {
                closer_obj_x = right_edge;
                closer_obj = w;
            }
        }
    }

    if (closer_obj)
    {
        obj->left_wall = closer_obj;       
        return true; 
    }

    return false;
}

static bool check_right_wall_collision(Player *p, GameScene *scene, CollisionObject *obj)
{
    const float bottom_margin = 5.0f;
    const float floor_tolerance = 1.0f;
    
    float y_bottom = p->y + p->height;
    float y_top = y_bottom - bottom_margin;

    StaticObject *closer_obj = NULL;
    float closer_obj_x = 999999;

    for (int i = 0; i < scene->obj_count; i++)
    {
        StaticObject *w = &scene->obj[i];

        bool vertical_overlap =
            (y_bottom > w->y) &&
            (y_top < w->y + w->h);

        bool touching_right = 
            p->x + p->width > w->x &&         
            p->x < w->x + 1.0f; 
            
        if (obj->floor_wall && w == obj->floor_wall)
        {
            bool standing_on_top = p->y + p->height <= w->y + floor_tolerance;
            if (standing_on_top)
            {
                continue;
            }
        }

        if (vertical_overlap && touching_right)
        {
            if (w->x < closer_obj_x)
            {
                closer_obj_x = w->x;
                closer_obj = w;
            }
        }
    }
    if (closer_obj){
        obj->right_wall = closer_obj;
        return true;
    }
    return false;
}

CollisionObject check_y_collision(Player * player,GameScene * scene)
{
    CollisionObject obj = {0};

    if (check_floor_collision(player,scene,&obj))
        obj.is_floor = true;

    if (check_top_collision(player,scene,&obj))
        obj.is_top = true;

    return obj;
}

CollisionObject check_x_collision(Player * player,GameScene * scene)
{
    CollisionObject object = {0};

    if (check_left_wall_collision(player, scene, &object))
    {
        object.is_left = true;
    }
    
    if (check_right_wall_collision(player, scene, &object))
    {
        object.is_right = true;
    }

    return object;
}

StaticObject * check_damage_coliision(Player * p, GameScene * scene)
{
    for (int i = 0; i < scene->obj_count; i++)
    {
        StaticObject * w = &scene->obj[i];

        if (w->type != SPIKE_OBJ)
        {
            continue;
        }

        int padding = 2;

        bool overlap =
            p->x < (w->x + w->w + padding) &&
            p->x + p->width > (w->x - padding) &&
            p->y < (w->y + w->h + padding) &&
            p->y + p->height > (w->y - padding);

        if (overlap)
            {
                return w;
            }
    }
    return NULL;

}
#include "collisions.h"
#include <stdbool.h>
#include <stdio.h>


static inline bool is_spike(const StaticObject *object)
{
    return object->type == SPIKE_OBJ;
}

static bool check_floor_collision(Player *p, GameScene *scene, CollisionObject *object)
{   
    for (int i = 0; i < scene->obj_count; i++)
    {
        StaticObject *w = &scene->obj[i];

        bool horizontal_overlap = 
            p->x + p->width > w->x &&
            p->x < w->x + w->w;

        bool falling = p->v_speed >= 0;

        bool on_top =
            falling &&
            p->y + p->height >= w->y &&
            p->y + p->height - p->v_speed <= w->y;

        if (horizontal_overlap && on_top)
        {
            if (is_spike(w))
                object->is_spike = true;

            object->floor_wall = w;
            return true;
        }
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

        bool moving_up = p->v_speed < 0;

        bool touch_top = 
            moving_up &&
            (p->y + p->v_speed) <= (w->y + w->h) &&  
            p->y >= w->y + w->h;                      

        if (horizontal_overlap && touch_top)
        {
            if (is_spike(w))
                object->is_spike = true;
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
            if (is_spike(w))
                obj->is_spike = true;
            obj->left_wall = w;
            return true;
        }
    }
    return false;
}

static bool check_right_wall_collision(Player *p, GameScene *scene, CollisionObject *obj)
{
    const float bottom_margin = 5.0f;
    const float floor_tolerance = 1.0f;
    
    float y_bottom = p->y + p->height;
    float y_top = y_bottom - bottom_margin;

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
            if (is_spike(w))
                obj->is_spike = true;
            obj->right_wall = w;
            return true;
        }
    }
    return false;
}

CollisionObject checkCollision(Player *p, GameScene *scene)
{
    CollisionObject object = {0};

    if (check_floor_collision(p, scene, &object))
    {
        object.is_floor = true;
    }
    
    if (check_left_wall_collision(p, scene, &object))
    {
        object.is_left = true;
    }
    
    if (check_right_wall_collision(p, scene, &object))
    {
        object.is_right = true;
    }

    if (check_top_collision(p,scene, &object))
    {
        object.is_top = true;
    }

    return object;
}


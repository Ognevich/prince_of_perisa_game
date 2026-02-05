#include "objects.h"

void createWall(struct StaticObject * wall, rgba color, int x, int y, int w, int h)
{
    wall->x = x;
    wall->y = y;
    wall->w = w;
    wall->h = h;
    wall->color.r = color.r;
    wall->color.g = color.g;
    wall->color.b = color.b;
    wall->color.a = color.a;
    wall->type = WALL_OBJ;
}

void createSpike(struct StaticObject * spike, rgba color, int x, int y, int w, int h)
{
    spike->x = x;
    spike->y = y;
    spike->w = w;
    spike->h = h;
    spike->color.r = color.r;
    spike->color.g = color.g;
    spike->color.b = color.b;
    spike->color.a = color.a;
    spike->type = SPIKE_OBJ;
}
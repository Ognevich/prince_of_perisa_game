#include "wall.h"

void createWall(struct Wall * wall, rgba color, int x, int y, int w, int h)
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
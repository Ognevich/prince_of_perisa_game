#include "wall.h"

void createWall(struct Wall * wall, int x, int y, int w, int h)
{
    wall->x = x;
    wall->y = y;
    wall->w = w;
    wall->h = h;
    wall->type = WALL_OBJ;
}
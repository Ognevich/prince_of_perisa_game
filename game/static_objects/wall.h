#ifndef _WALL_H_
#define _WALL_H_
#include "static_objects.h"
#include "../config.h"

struct Wall{
    int x;
    int y;
    int w;
    int h;
    rgba color;
    StaticObjectType type;
};

void createWall(struct Wall * wall, rgba color, int x, int y, int w, int h);

#endif
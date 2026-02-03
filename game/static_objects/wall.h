#ifndef _WALL_H_
#define _WALL_H_
#include "static_objects.h"

struct Wall{
    int x, y;
    int h, w;
    StaticObjectType type;
};

void createWall(struct Wall * wall, int x, int y, int w, int h);

#endif
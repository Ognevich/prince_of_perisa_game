#ifndef _WALL_H_
#define _WALL_H_
#include "static_objects.h"
#include "../config.h"

struct StaticObject{
    int x;
    int y;
    int w;
    int h;
    rgba color;
    StaticObjectType type;
};

void createObject(struct StaticObject * wall, StaticObjectType type,rgba color, int x, int y, int w, int h);

#endif
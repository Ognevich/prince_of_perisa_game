#ifndef _SCENE_H_
#define _SCENE_H_
#include <stddef.h>
#include "../static_objects/wall.h"


typedef struct{
    struct Wall * walls;
    size_t wallsCount;
}GameScene;

typedef enum{
    SCENE_MENU,
    SCENE_LEVE1
}SceneType;

void loadScene(GameScene * scene, SceneType type);
void unloadScene(GameScene  *scene);

#endif

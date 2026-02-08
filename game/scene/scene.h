#ifndef _SCENE_H_
#define _SCENE_H_
#include <stddef.h>
#include "../static_objects/objects.h"
#include <stdbool.h>


typedef struct{
    struct StaticObject * obj;
    size_t obj_count;
}GameScene;

typedef enum{
    SCENE_MENU,
    SCENE_LEVE1
}SceneType;

void loadScene(GameScene * scene, SceneType type);
void unloadScene(GameScene  *scene);
void control_scene(GameScene * scene, SceneType type, bool * scene_loaded, bool * scene_changed);

#endif

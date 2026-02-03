#include "scene.h"
#include <stdlib.h>

static void loadFirstScene(GameScene * scene)
{
    scene->wallsCount = 1;
    scene->walls = malloc(sizeof(struct Wall*)  * scene->wallsCount);
    scene->walls[0] = (struct Wall){0,};


}

void loadScene(GameScene *scene, SceneType type)
{
    switch (type)
    {
    case SCENE_LEVE1:
    {
        loadFirstScene(scene);
        break;
    }    
    default:
        break;
    }

}
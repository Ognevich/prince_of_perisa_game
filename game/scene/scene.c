#include "scene.h"
#include <stdlib.h>
#include "../config.h"

static void load_first_scnene(GameScene *scene)
{
    scene->obj_count = 9;
    scene->obj = malloc(sizeof(struct StaticObject) * scene->obj_count);

    createWall(&scene->obj[0], (rgba){80, 50, 30, 255}, 0, 550, 1024, 26);
    createWall(&scene->obj[1], (rgba){50, 50, 50, 255}, 0, 0, 25, 576);
    createWall(&scene->obj[2], (rgba){50, 50, 50, 255}, 999, 0, 25, 576);
    createWall(&scene->obj[3], (rgba){70, 70, 70, 255}, 400, 400, 224, 25);
    createWall(&scene->obj[4], (rgba){60, 60, 60, 255}, 25, 350, 300, 20);
    createWall(&scene->obj[5], (rgba){60, 60, 60, 255}, 724, 350, 200, 20);
    createWall(&scene->obj[6], (rgba){70, 70, 70, 255}, 150, 300, 25, 50);
    createWall(&scene->obj[7], (rgba){70, 70, 70, 255}, 849, 300, 25, 50);

    createSpike(&scene->obj[8], (rgba){120, 0, 0, 255}, 500, 525, 50, 25);
}
void loadScene(GameScene *scene, SceneType type)
{
    switch (type)
    {
    case SCENE_LEVE1:
    {
        load_first_scnene(scene);
        break;
    }    
    default:
        break;
    }

}

void unloadScene(GameScene  *scene)
{
    free(scene->obj);
    scene->obj = NULL;
    scene->obj_count = 0;
}
#include "scene.h"
#include <stdlib.h>
#include "../config.h"

static void load_first_scnene(GameScene *scene)
{
    scene->wallsCount = 9;
    scene->walls = malloc(sizeof(struct Wall) * scene->wallsCount);

    createWall(&scene->walls[0], (rgba){80, 50, 30, 255}, 0, 550, 1024, 26);
    createWall(&scene->walls[1], (rgba){50, 50, 50, 255}, 0, 0, 25, 576);
    createWall(&scene->walls[2], (rgba){50, 50, 50, 255}, 999, 0, 25, 576);
    createWall(&scene->walls[3], (rgba){70, 70, 70, 255}, 400, 400, 224, 25);
    createWall(&scene->walls[4], (rgba){60, 60, 60, 255}, 25, 350, 300, 20);
    createWall(&scene->walls[5], (rgba){60, 60, 60, 255}, 724, 350, 200, 20);
    createWall(&scene->walls[6], (rgba){70, 70, 70, 255}, 150, 300, 25, 50);
    createWall(&scene->walls[7], (rgba){70, 70, 70, 255}, 849, 300, 25, 50);
    createWall(&scene->walls[8], (rgba){120, 0, 0, 255}, 500, 525, 50, 25);
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
    free(scene->walls);
    scene->walls = NULL;
    scene->wallsCount = 0;
}
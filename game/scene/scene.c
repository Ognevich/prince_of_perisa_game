#include "scene.h"
#include <stdlib.h>
#include "../config.h"

static void loadFirstScene(GameScene * scene)
{
    scene->wallsCount = 5;
    scene->walls = malloc(sizeof(struct Wall)  * scene->wallsCount);
    
    createWall(&scene->walls[0],(rgba){220, 218, 23, 255},700,400,325,176);
    createWall(&scene->walls[1],(rgba){100, 90, 100, 255},300,450,325,126);
    createWall(&scene->walls[2],(rgba){100, 90, 100, 255},0,0,1025,50);
    createWall(&scene->walls[3],(rgba){100, 90, 100, 255},300,50,325,75);
    createWall(&scene->walls[4],(rgba){100, 90, 100, 255},1000,0,25,576);

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

void unloadScene(GameScene  *scene)
{
    free(scene->walls);
    scene->walls = NULL;
    scene->wallsCount = 0;
}
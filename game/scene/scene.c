#include "scene.h"
#include <stdlib.h>
#include "../config.h"
#include "scenes_array.h"

size_t found_active_objects(const int sceneMap[][WIDTH_CELLS])
{
    int obj_count = 0;
    for (int i = 0; i < HEIGHT_CELLS; i++)
        for (int j = 0; j < WIDTH_CELLS; j++)
            if (sceneMap[i][j] == 1)    obj_count++;
    
    return obj_count;
}

static void load_first_scnene(GameScene *scene)
{

    scene->obj_count = found_active_objects(sceneMap);
    scene->obj = malloc(sizeof(struct StaticObject) * scene->obj_count);

    int current_obj_size = 0; 

    for (int j = 0; j < HEIGHT_CELLS; j++)     
    {
        for (int i = 0; i < WIDTH_CELLS; i++)  
        {
            if (sceneMap[j][i] == 1)
            {
                createWall(&scene->obj[current_obj_size], (rgba){60, 60, 60, 255},
                    i * TILE_SIZE, j * TILE_SIZE,
                    TILE_SIZE, TILE_SIZE);
                current_obj_size++;
            }
        }
    }

    // createSpike(&scene->obj[8], (rgba){120, 0, 0, 255}, 500, 525, 50, 25);
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

void control_scene(GameScene * scene, SceneType type, bool * scene_loaded, bool * scene_changed)
{
        switch (type)
        {
        case SCENE_LEVE1:
        {
            if (!*scene_loaded)
            {
                loadScene(scene, type);
                *scene_loaded = true;
            }

          if (*scene_changed)
            {
                unloadScene(scene);
                *scene_changed = false;
                *scene_loaded = false;
            }

            break;
        }
        default:
            break;
        }    
}

#include "scene.h"
#include <stdlib.h>
#include "../config.h"
#include "scenes_array.h"

size_t found_active_objects(const int sceneMap[][WIDTH_CELLS])
{
    int obj_count = 0;
    for (int i = 0; i < HEIGHT_CELLS; i++)
        for (int j = 0; j < WIDTH_CELLS; j++)
            if (sceneMap[i][j] == WALL_POSITON || 
                sceneMap[i][j] == SPIKE_POSITION)
                {
                    obj_count++;
                }
    
    return obj_count;
}

static void load_first_scene(GameScene *scene)
{

    scene->obj_count = found_active_objects(sceneMap);
    scene->obj = malloc(sizeof(struct StaticObject) * scene->obj_count);

    int current_obj_size = 0; 

    for (int j = 0; j < HEIGHT_CELLS; j++)     
    {
        for (int i = 0; i < WIDTH_CELLS; i++)  
        {
            if (sceneMap[j][i] == WALL_POSITON)
            {
                createObject(
                    &scene->obj[current_obj_size],
                    WALL_OBJ,
                    (rgba){60, 60, 60, 255},
                    i * TILE_SIZE, j * TILE_SIZE,
                    TILE_SIZE, TILE_SIZE);
                current_obj_size++;
            }
            else if (sceneMap[j][i] == SPIKE_POSITION)
            {
                int pos_y = (j * TILE_SIZE) + (TILE_SIZE/2);
                int pos_x = i * TILE_SIZE + (TILE_SIZE/4); 
                createObject(
                    &scene->obj[current_obj_size],
                    SPIKE_OBJ,
                    (rgba){120, 0, 0, 255},
                    pos_x,pos_y,
                    TILE_SIZE/2, (TILE_SIZE/2));    
                current_obj_size++;      
            }
        }
    }

}
void loadScene(GameScene *scene, SceneType type)
{
    switch (type)
    {
    case SCENE_LEVE1:
    {
        load_first_scene(scene);
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

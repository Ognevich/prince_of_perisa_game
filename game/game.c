#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include <string.h>
#include <stdlib.h>
#include "../platform/sdl.h"
#include "../graphics/renderer.h"
#include "player/player.h"
#include "../input/input.h"
#include "collisions/collisions.h"

void init_game(GameConfig * config,Player * player)
{
    init_game_config(config);
    init_player(player);
}

void init_game_config(GameConfig * config)
{
    config->state         = GAME_START; 
    config->HEIGHT        = GAME_HEIGHT;
    config->WIDTH         = GAME_WIDTH;

    config->scene_type    = SCENE_LEVE1;
    config->scene_changed = false;

    config->delta_time    = 0.0f;

    strcpy(config->title, "Prince of Persia");
}

void init_player(Player * player)
{
    rgba color = {255,127,0,255};
    create_player(player, 820,
                                   100,
                                   32, 32,              
                                   color, 0.0f, 0.0f);
}

void update_game(GameConfig * config, SDLContext * context, Player * player)
{

    Input_type input;
    Uint32 frameStart = SDL_GetTicks();

    GameScene scene;
    bool scene_loaded = false;

    while (config->state != GAME_STOP)
    {
        switch (config->scene_type)
        {
        case SCENE_LEVE1:
        {
            if (!scene_loaded)
            {
                loadScene(&scene, config->scene_type);
                scene_loaded = true;
            }

            config->delta_time = calculate_delta_time(&frameStart);

            poll_events(config);
            proccess_input(&input);
            update_player(player, config, &input);
            CollisionObject coll_obj = checkCollision(player,&scene);
            resolve_player_collision(player,coll_obj);
            render(context,player, &scene);

            limit_frame(frameStart,FRAME_DELAY);

            if (config->scene_changed)
            {
                unloadScene(&scene);
                config->scene_changed = false;
                scene_loaded = false;
            }

            break;
        }
        default:
            break;
        }
    }
}

void game_shutdown()
{

}
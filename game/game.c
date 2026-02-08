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

        control_scene(&scene,config->scene_type,&scene_loaded,&config->scene_changed);

        config->delta_time = calculate_delta_time(&frameStart);

        poll_events(config);
        proccess_input(&input);

        update_player_velocity(player,&input, config);

        move_y(player);
        CollisionObject collY = check_y_collision(player,&scene);
        resolve_player_collisionY(player,collY);

        move_x(player);
        CollisionObject collX = check_x_collision(player,&scene);
        resolve_player_collisionX(player,collX);

        render(context,player, &scene);
        limit_frame(frameStart,FRAME_DELAY);
    }
}

void game_shutdown()
{

}
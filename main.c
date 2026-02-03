#include <stdio.h>
#include <SDL3/SDL_main.h>
#include "game/game.h"
#include "game/player/player.h"
#include "platform/sdl.h"


int main(int argc, char* argv[])
{
    SDLContext context;
    GameConfig config; 
    Player player;

    init_game(&config, &player); 
    if(!sdl_init(&context,&config))
        return 1;

    update_game(&config, &context, &player);

    sdl_shutdown(&context);


    // DOESN'T USING NOW
    game_shutdown();
    return 0;
}
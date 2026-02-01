#include <stdio.h>
#include <SDL3/SDL_main.h>
#include "game/game.h"
#include "platform/sdl.h"

int main(int argc, char* argv[])
{
    SDLContext context;
    GameConfig config; 
    init_game(&config); 
    if(!sdl_init(&context,&config))
        return 1;

    update_game(&config, &context);

    sdl_shutdown(&context);

    return 0;
}
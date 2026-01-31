#include "gameControler.h"
#include <SDL3/SDL.h>

void initGame(GameConfig * config)
{
    config->state = GAME_START; 
    config->HEIGHT = 576;
    config->WIDTH = 1024;

    SDL_Init(SDL_INIT_VIDEO);

}
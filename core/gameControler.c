#define _CRT_SECURE_NO_WARNINGS
#include "gameControler.h"
#include <string.h>

void init_game(GameConfig * config)
{
    config->state = GAME_START; 
    config->HEIGHT = 576;
    config->WIDTH = 1024;
    strcpy(config->title, "Prince of Persia");
}
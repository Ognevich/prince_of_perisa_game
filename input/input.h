#ifndef _INPUT_H_
#define _INPUT_H_
#include "../game/game.h"
#include <stdbool.h>

struct Input_type{
    bool left;
    bool right;    
};

void proccess_input(Input_type * type);
void poll_events(GameConfig * cfg);

#endif
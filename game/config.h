#ifndef _CONFIG_H_
#define _CONFIG_H_
#include <stdint.h>

////////////BASE SETTINGS////////////
#define TITLE_SIZE 20
#define GAME_HEIGHT 576
#define GAME_WIDTH  1024
/////////////////////////////////////

////////////RENDER SETTINGS//////////
#define FRAME_DELAY 1000/60 
/////////////////////////////////////

/////PLAYER PHYSICS SETTUNGS////////
#define DEFAULT_SPEED 4
#define GRAVITY 0.5f
#define MAX_FALL_SPEED 12.0f
#define JUMP_SPEED 15.0f
/////////////////////////////////////

typedef struct{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
}rgba;
#endif
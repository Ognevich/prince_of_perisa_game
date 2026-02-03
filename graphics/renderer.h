#ifndef _RENDERER_H_
#define _RENDERER_H_
#include <stdint.h>
#include "../game/game.h"
#include "../platform/sdl.h"

typedef struct{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
}rgba;

void render(SDLContext * context, Player * player);

#endif

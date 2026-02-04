#ifndef _RENDERER_H_
#define _RENDERER_H_
#include <stdint.h>
#include "../game/game.h"
#include "../platform/sdl.h"

void render(SDLContext * context, Player * player, GameScene * scene);

#endif

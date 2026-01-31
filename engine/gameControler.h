#ifndef _GAME_CONTROLER_H_
#define _GAME_CONTROLER_H_

typedef enum{
    GAME_START,
    GAME_PAUSE,
    GAME_STOP
}GameStates;

typedef struct{
    GameStates state;
    int HEIGHT;
    int WIDTH;
}GameConfig;

void initGame(GameConfig * config);

#endif
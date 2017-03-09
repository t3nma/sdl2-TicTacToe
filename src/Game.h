// Game.h
// Game class definition. Member-functions defined in Game.cpp
//
// Author: yat0 - https://github.com/yat0

#ifndef _GAME_
#define _GAME_

#include <SDL2/SDL.h>
#include "Board.h"
#include "Bot.h"

class Game
{
public:
    enum GAME_STATE {STATE_RUNNING, STATE_STOPPED};

    Game();

    void update(SDL_Event *event);
    void render() const;
    void checkWin();

private:
    GAME_STATE state;
    Bot bot;
    Board board;
    bool humanTurn;

    void restartGame();
};

#endif

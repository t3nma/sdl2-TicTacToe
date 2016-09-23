// Board.h
// Board class definition. Member-functions defined in Board.cpp
//
// Author: yat0 - https://github.com/yat0

#ifndef _BOT_
#define _BOT_

#include "Board.h"

class Bot
{
public:
    enum BOT_LEVEL
    {
        LEVEL_EASY,    // random
        LEVEL_MEDIUM,  // defend + random attack
        LEVEL_HARD,    // defend + win attack
        LEVEL_COUNT
    };

    Bot();

    void play(Board &board) const;
    void restart();

private:
    BOT_LEVEL level;

    void easy(Board &board) const;
    bool medium(Board &board) const;
    bool hard(Board &board) const;
};

#endif

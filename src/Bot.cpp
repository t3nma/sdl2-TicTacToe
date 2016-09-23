// Bot.cpp
// Bot class member-functions definition.
//
// Author: yat0 - https://github.com/yat0

#include "Bot.h"
#include <cstdlib>

Bot::Bot() { restart(); }

// simulates the bot turn
void Bot::play(Board &board) const
{
    switch(level)
    {
        case LEVEL_EASY:
            easy(board); break;
        case LEVEL_MEDIUM:
            if(!medium(board))
                easy(board);
            break;
        case LEVEL_HARD:
            if(!hard(board) && !medium(board))
                easy(board);
            break;
        default:
            break;
    }
}

// randomly chooses the new bot AI level
void Bot::restart() { level = static_cast<BOT_LEVEL>(rand()%LEVEL_COUNT); }

// simulates an easy AI level play
void Bot::Bot::easy(Board &board) const
{
    int x = rand()%3;
    int y = rand()%3;

    while(!board.isFieldEmpty(x,y))
    {
        x = rand()%3;
        y = rand()%3;
    }

    board.place(x, y, false);
}

// simulates a medium AI level play
bool Bot::medium(Board &board) const
{
    // can block a row?
    for(int i=0; i<3; i++)
    {
        if(board.isFieldCross(i,0) && board.isFieldCross(i,1) && board.isFieldEmpty(i,2))
        {
            board.place(i,2,false);
            return true;
        }

        if(board.isFieldCross(i,0) && board.isFieldCross(i,2) && board.isFieldEmpty(i,1))
        {
            board.place(i,1,false);
            return true;
        }

        if(board.isFieldCross(i,1) && board.isFieldCross(i,2) && board.isFieldEmpty(i,0))
        {
            board.place(i,0,false);
            return true;
        }
    }

    // can block a column?
    for(int j=0; j<3; j++)
    {
        if(board.isFieldCross(0,j) && board.isFieldCross(1,j) && board.isFieldEmpty(2,j))
        {
            board.place(2,j,false);
            return true;
        }
        else if(board.isFieldCross(0,j) && board.isFieldCross(2,j) && board.isFieldEmpty(1,j))
        {
            board.place(1,j,false);
            return true;
        }
        else if(board.isFieldCross(1,j) && board.isFieldCross(2,j) && board.isFieldEmpty(0,j))
        {
            board.place(0,j,false);
            return true;
        }
    }

    // can block a diagonal?
    if(board.isFieldCross(0,0) && board.isFieldCross(1,1) && board.isFieldEmpty(2,2))
    {
        board.place(2,2,false);
        return true;
    }
    else if(board.isFieldCross(0,0) && board.isFieldCross(2,2) && board.isFieldEmpty(1,1))
    {
        board.place(1,1,false);
        return true;
    }
    else if(board.isFieldCross(1,1) && board.isFieldCross(2,2) && board.isFieldEmpty(0,0))
    {
        board.place(0,0,false);
        return true;
    }
    else if(board.isFieldCross(0,2) && board.isFieldCross(1,1) && board.isFieldEmpty(2,0))
    {
        board.place(2,0,false);
        return true;
    }
    else if(board.isFieldCross(0,2) && board.isFieldCross(2,0) && board.isFieldEmpty(1,1))
    {
        board.place(1,1,false);
        return true;
    }
    else if(board.isFieldCross(1,1) && board.isFieldCross(2,0) && board.isFieldEmpty(0,2))
    {
        board.place(0,2,false);
        return true;
    }

    return false; // nothing to block
}

// simulates a hard AI level play
bool Bot::hard(Board &board) const
{
    // can win on a row?
    for(int i=0; i<3; i++)
    {
        if(board.isFieldCircle(i,0) && board.isFieldCircle(i,1) && board.isFieldEmpty(i,2))
        {
            board.place(i,2,false);
            return true;
        }

        if(board.isFieldCircle(i,0) && board.isFieldCircle(i,2) && board.isFieldEmpty(i,1))
        {
            board.place(i,1,false);
            return true;
        }

        if(board.isFieldCircle(i,1) && board.isFieldCircle(i,2) && board.isFieldEmpty(i,0))
        {
            board.place(i,0,false);
            return true;
        }
    }

    // can win on a column?
    for(int j=0; j<3; j++)
    {
        if(board.isFieldCircle(0,j) && board.isFieldCircle(1,j) && board.isFieldEmpty(2,j))
        {
            board.place(2,j,false);
            return true;
        }
        else if(board.isFieldCircle(0,j) && board.isFieldCircle(2,j) && board.isFieldEmpty(1,j))
        {
            board.place(1,j,false);
            return true;
        }
        else if(board.isFieldCircle(1,j) && board.isFieldCircle(2,j) && board.isFieldEmpty(0,j))
        {
            board.place(0,j,false);
            return true;
        }
    }

    // can win on a diagonal?
    if(board.isFieldCircle(0,0) && board.isFieldCircle(1,1) && board.isFieldEmpty(2,2))
    {
        board.place(2,2,false);
        return true;
    }
    else if(board.isFieldCircle(0,0) && board.isFieldCircle(2,2) && board.isFieldEmpty(1,1))
    {
        board.place(1,1,false);
        return true;
    }
    else if(board.isFieldCircle(1,1) && board.isFieldCircle(2,2) && board.isFieldEmpty(0,0))
    {
        board.place(0,0,false);
        return true;
    }
    else if(board.isFieldCircle(0,2) && board.isFieldCircle(1,1) && board.isFieldEmpty(2,0))
    {
        board.place(2,0,false);
        return true;
    }
    else if(board.isFieldCircle(0,2) && board.isFieldCircle(2,0) && board.isFieldEmpty(1,1))
    {
        board.place(1,1,false);
        return true;
    }
    else if(board.isFieldCircle(1,1) && board.isFieldCircle(2,2) && board.isFieldEmpty(0,2))
    {
        board.place(0,2,false);
        return true;
    }

    return false; // no possible way to win
}

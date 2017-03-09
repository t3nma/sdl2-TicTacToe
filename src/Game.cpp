// Game.cpp
// Game class member-functions definition.
//
// Author: yat0 - https://github.com/yat0

#include "Game.h"
#include "App.h"
#include <SDL2/SDL.h>
#include <ctime>
#include <cstdlib>

Game::Game()
{
    srand(time(NULL)); // generate new seed
    restartGame();
}

// update current game's state
void Game::update(SDL_Event *event)
{
    // have we reach the current game's end?
    if(state == STATE_STOPPED)
        restartGame();
    else
    {
        bool successfulPlay = false; // to handle change of player turn

        // process human or pc turn
        if(!humanTurn)
        {
            bot.play(board);
            successfulPlay = true;
        }
        else
        {
            // did the human play?
            if(event->type == SDL_MOUSEBUTTONDOWN)
            {
                // get mouse coordinates and normalize to row/col
                int x, y;
                SDL_GetMouseState(&x, &y);
                int row = y/(App::SCREEN_HEIGHT/3);
                int col = x/(App::SCREEN_WIDTH/3);

                // try to validate the move
                if(board.isFieldEmpty(row,col))
                {
                    board.place(row,col);
                    successfulPlay = true;
                }
            }
        }

        // change turns
        if(successfulPlay)
        {
            humanTurn = !humanTurn;
            SDL_Delay(100); // delay between turns
        }
    }
}

// render the game to the window
void Game::render() const
{
    // bg
    SDL_SetRenderDrawColor(App::getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(App::getRenderer());

    // game objects
    board.render();

    // render
    SDL_RenderPresent(App::getRenderer());
}

// check board win conditions
void Game::checkWin()
{
    if(board.hasWinner() || board.isDraw())
        state = STATE_STOPPED; // so the game loop knows the end of the current game
}

void Game::restartGame()
{
    bot.restart();
    board.restart();

    // randomly choose first player
    // 0=pc, 1=human
    humanTurn = (rand()&1) ? true : false;

    // corrects the game state
    state = STATE_RUNNING;
}

// App.cpp
// App class member-functions definition.
//
// Author: yat0 - https://github.com/yat0

#include "App.h"
#include <cstdio>

// static data-members initialization
SDL_Window* App::gWindow = NULL;
SDL_Renderer* App::gRenderer = NULL;

// free game window
App::~App()
{
    if(gRenderer != NULL)
    {
        SDL_DestroyRenderer(gRenderer);
        gRenderer = NULL;
    }

    if(gWindow != NULL)
    {
        SDL_DestroyWindow(gWindow);
        gWindow = NULL;
    }
}

// starts SDL and initializes window
bool App::init()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Couldn't start SDL! SDL error: %s\n", SDL_GetError());
        return false;
    }

    gWindow = SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(gWindow == NULL)
    {
        printf("Couldn't create Window! SDL error: %s\n", SDL_GetError());
        return false;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(gRenderer == NULL)
    {
        printf("Couldn't create Renderer! SDL error: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

// starts the game lifecycle
void App::run()
{
    bool quit = false;
    while(!quit)
    {
        // handle exit events
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                quit = true;
        }

        // update and render the game
        game.update(&event);
        game.render();
        game.checkWin();
    }
}

SDL_Window* App::getWindow()
{
    return gWindow;
}

SDL_Renderer* App::getRenderer()
{
    return gRenderer;
}

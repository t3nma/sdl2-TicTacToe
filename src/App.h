// App.h
// App class definition. Member-functions defined in App.cpp
//
// Author: yat0 - https://github.com/yat0

#ifndef _APP_
#define _APP_

#include <SDL2/SDL.h>
#include "Game.h"

class App
{
public:
    static const int SCREEN_WIDTH = 600;
    static const int SCREEN_HEIGHT = 600;

    // member functions
    ~App();

    bool init();
    void run();

    static SDL_Window *getWindow();
    static SDL_Renderer *getRenderer();

private:
    Game game;

    // SDL components
    static SDL_Window *gWindow;
    static SDL_Renderer *gRenderer;
    SDL_Event event;
};

#endif

// Util.cpp
// Util class member-functions definition.
//
// Author: yat0 - https://github.com/yat0

#include "Util.h"
#include "App.h"
#include <cmath>

// render cross on field (boardX, boardY)
void Util::drawCross(int boardX, int boardY)
{
    int fieldW = App::SCREEN_WIDTH/3;
    int fieldH = App::SCREEN_HEIGHT/3;

    // top left to bottom right
    SDL_RenderDrawLine(App::getRenderer(),
        boardY*fieldW, boardX*fieldH,
        boardY*fieldW+fieldW, boardX*fieldH+fieldH);

    // top right to bottom left
    SDL_RenderDrawLine(App::getRenderer(),
        boardY*fieldW, boardX*fieldH+fieldH,
        boardY*fieldW+fieldW, boardX*fieldH);
}

// render circle on field (boardX, boardY)
void Util::drawCircle(int boardX, int boardY)
{
    int fieldW = App::SCREEN_WIDTH/3;
    int fieldH = App::SCREEN_HEIGHT/3;

    // calculate circle center
    int centerX = boardY*fieldW+(fieldW/2);
    int centerY = boardX*fieldH+(fieldH/2);

    int r = fieldW/2;

    double step = 2*M_PI/30;
    int endX = centerX + r;
    int endY = centerY;

    // draw circle.. Multiple straight lines between consecutive
    // points in the circle
    for(double angle=0; angle<2*M_PI; angle+=step)
    {
        int startX = endX;
        int startY = endY;
        endX = r * cos(angle) + centerX;
        endY = r * sin(angle) + centerY;
        SDL_RenderDrawLine(App::getRenderer(), startX, startY, endX, endY);
    }
}

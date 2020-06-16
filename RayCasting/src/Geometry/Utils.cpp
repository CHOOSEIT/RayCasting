//
//  Utils.cpp
//  RayCasting
//
//  Created by Guillaume Vitalis on 14/06/2020.
//  Copyright © 2020 CHOOSEIT. All rights reserved.
//

#include "Utils.hpp"

#include <iostream>

double DegreesfromRadians(const double Radians)
{
    return Radians * 180 / M_PI;
}

double RadiansfromDegrees(const double Degrees)
{
    return Degrees * M_PI / 180;
}

double distance(double x, double y, double x1, double y1)
{
    return sqrt( pow(x1 - x, 2) + pow(y1 - y, 2));
}

void RenderText(int size, std::string text, SDL_Renderer *renderer, Point pos, int width, int height)
{
    TTF_Font* Font = TTF_OpenFont("PathFontHere.ttf", size);
    if(Font == nullptr)
    {
        std::cout << TTF_GetError() << std::endl;
        return;
    }
    SDL_Color Color = {255, 255, 255};
    SDL_Surface * surface = TTF_RenderText_Solid(Font ,text.c_str(), Color);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect Message_rect;
    Message_rect.x = pos.x;
    Message_rect.y = pos.y;
    Message_rect.w = width;
    Message_rect.h = height;
    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
    
    SDL_FreeSurface(surface);
    TTF_CloseFont(Font);
    SDL_DestroyTexture(Message);
}

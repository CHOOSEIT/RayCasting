//
//  Utils.hpp
//  RayCasting
//
//  Created by Guillaume Vitalis on 14/06/2020.
//  Copyright © 2020 CHOOSEIT. All rights reserved.
//

#ifndef Utils_hpp
#define Utils_hpp

#include <cmath>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <SDL2/SDL.h>
#include "Point.hpp"

double DegreesfromRadians(const double Radians);
double RadiansfromDegrees(const double Degrees);

double distance(double x, double y, double x1, double y1);

void RenderText(int size, std::string text, SDL_Renderer *renderer, Point pos, int width, int height);

#endif /* Utils_hpp */

//
//  Circle.hpp
//  RayCasting
//
//  Created by Guillaume Vitalis on 15/06/2020.
//  Copyright © 2020 CHOOSEIT. All rights reserved.
//

#ifndef Circle_hpp
#define Circle_hpp

#include "Point.hpp"
#include <SDL2/SDL.h>
#include "Utils.hpp"
#include "Line.hpp"
#include <cmath>
#include <vector>


class Circle
{
public:
    Circle(double Radius, Point pt);
    
    void render(SDL_Renderer *renderer, const int color[4]);
    void render(SDL_Renderer *renderer, const int color[4], const bool fill);
    
    std::vector<Point> TouchingLine(const Line &line);
    
private:
    double radius;
    
    Point pos;
};

#endif /* Circle_hpp */

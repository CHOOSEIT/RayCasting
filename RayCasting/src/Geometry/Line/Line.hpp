//
//  Line.hpp
//  RayCasting
//
//  Created by Guillaume Vitalis on 14/06/2020.
//  Copyright © 2020 CHOOSEIT. All rights reserved.
//

#ifndef Line_hpp
#define Line_hpp

#include "Point.hpp"
#include <SDL2/SDL.h>

class Line
{
public:
    
    Line(const Point A, const Point B);
    
    void render(SDL_Renderer *renderer, const int color[4]);
    
    Point* TouchingLines(const Line& other);
    Point* TouchingLines(const Point& other);
    
    Point A, B;
    
    
};

#endif /* Line_hpp */

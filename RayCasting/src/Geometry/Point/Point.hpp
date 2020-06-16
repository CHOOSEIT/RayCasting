//
//  Point.hpp
//  RayCasting
//
//  Created by Guillaume Vitalis on 14/06/2020.
//  Copyright © 2020 CHOOSEIT. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <cmath>
#include <iostream>
#include <ostream>
#include <SDL2/SDL.h>

class Point
{
public:
    double x, y;
    Point(double x, double y);
    
    const double distance(const Point &other);
    
    void render(SDL_Renderer *renderer, const int color[4]);
    
};

std::ostream &operator<<(std::ostream &os, Point const &m);

#endif /* Point_hpp */

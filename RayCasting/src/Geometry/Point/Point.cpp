//
//  Point.cpp
//  RayCasting
//
//  Created by Guillaume Vitalis on 14/06/2020.
//  Copyright © 2020 CHOOSEIT. All rights reserved.
//

#include "Point.hpp"

Point::Point(double x, double y) : x(x), y(y)
{}

const double Point::distance(const Point &other)
{
    return sqrt(pow( (other.x - this->x), 2) + pow( (other.y - this->y), 2));
}

void Point::render(SDL_Renderer *renderer, const int color[4])
{
    SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
    SDL_RenderDrawPoint(renderer, x, y);
}

std::ostream &operator<<(std::ostream &os, const Point &p)
{
    return os << "Point: { " << p.x << " , " << p.y << " }";
}

//
//  Line.cpp
//  RayCasting
//
//  Created by Guillaume Vitalis on 14/06/2020.
//  Copyright © 2020 CHOOSEIT. All rights reserved.
//

#include "Line.hpp"

Line::Line(const Point A, const Point B): A(A), B(B)
{
    
}

void Line::render(SDL_Renderer *renderer, const int color[4])
{
    SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
    SDL_RenderDrawLine(renderer, (int) A.x, (int) A.y, (int) B.x, (int) B.y);
    
    
    
}

Point* Line::TouchingLines(const Line& other)
{
    double x1 = other.A.x;
    double x2 = other.B.x;
    double y1 = other.A.y;
    double y2 = other.B.y;
    double x3 = A.x;
    double x4 = B.x;
    double y3 = A.y;
    double y4 = B.y;
    
    const double d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    
    if (d == 0)
    {
        return nullptr;
    }
    
    const double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / d;
    const double u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / d;
    
    if ( t > 0 and t < 1 and u > 0)
    {
        Point *pt = new Point(x1 + t * (x2 - x1), y1 + t * (y2 - y1));
        return pt;
    }
    else
    {
        return nullptr;
    }
}

Point* Line::TouchingLines(const Point& other)
{
    int x1 = (int) other.x;
    int x2 = (int) other.x;
    int y1 = (int) other.y;
    int y2 = (int) other.y;
    int x3 = (int) A.x;
    int x4 = (int) B.x;
    int y3 = (int) A.y;
    int y4 = (int) B.y;
    
    const double d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    
    if (d == 0)
    {
        return nullptr;
    }
    
    const double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / d;
    const double u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / d;
    
    if ( t > 0 and t < 1 and u > 0)
    {
        Point *pt = new Point(x1 + t * (x2 - x1), y1 + t * (y2 - y1));
        return pt;
    }
    else
    {
        return nullptr;
    }
}

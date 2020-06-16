//
//  Polygone.cpp
//  RayCasting
//
//  Created by Guillaume Vitalis on 14/06/2020.
//  Copyright © 2020 CHOOSEIT. All rights reserved.
//

#include "Polygone.hpp"
#include <limits>



Polygone::Polygone()
{}

void Polygone::addPoint(const Point &p)
{
    points.push_back(p);
}

void Polygone::addPoint(std::vector<Point> p)
{
    for(std::vector<Point>::iterator it = p.begin(); it != p.end(); it += 1)
    {
        points.push_back(*it);
    }
}

std::vector<Line> Polygone::getLines()
{
    std::vector<Line> r;
    if (points.size() == 0)
    {
        return r;
    }
    else if(points.size() == 1)
    {
        r.push_back(Line(points[0], points[0]));
        return r;
    }
    else if(points.size() == 1)
    {
        r.push_back(Line(points[0], points[1]));
        return r;
    }
    else
    {
        for(std::vector<Point>::iterator it = points.begin(); it != points.end() - 1; it += 1)
        {
            r.push_back(Line(*it, *(it + 1)));
        }
        
        r.push_back(Line(points[points.size() - 1], points[0]));
        
        return r;
        
    }
}

void Polygone::getPoints(std::vector<Point> &pts)
{
    pts = points;
}

void Polygone::setPoints(const std::vector<Point> pts)
{
    points = pts;
}

void Polygone::render(SDL_Renderer *renderer)
{
    const int color[4] = {255, 255, 255, SDL_ALPHA_OPAQUE};
    
    std::vector<Line> lines = getLines();
    
    
    for(std::vector<Line>::iterator it = lines.begin(); it != lines.end(); it += 1)
    {
        it->render(renderer, color);
    }
}

void Polygone::clearPoints()
{
    points.clear();
}

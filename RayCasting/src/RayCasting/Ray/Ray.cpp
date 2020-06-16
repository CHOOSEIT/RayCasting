//
//  Ray.cpp
//  RayCasting
//
//  Created by Guillaume Vitalis on 15/06/2020.
//  Copyright © 2020 CHOOSEIT. All rights reserved.
//

#include "Ray.hpp"
#include <iostream>

Ray::Ray(const Point p, const double Radians): pos(p)
{
    Vector2d v = Vector2d();
    v.fromRadians(Radians);
    dir = v;
}


void Ray::LookAt(const Point p)
{
    dir = Vector2d(p.x - pos.x, p.y - pos.y);
    dir.normalize();
}

void Ray::render(SDL_Renderer *renderer, const int color[4])
{
    //Line l = Line(pos, Point((pos.x + dir.x * 25), (pos.y + dir.y * 25)));
    //l.render(renderer, color);
    
    //Circle c = Circle(10, pos);
    //c.render(renderer, color);
    
    
    
}

Point* Ray::cast(Polygone &polygone)
{
    std::vector<Line> lines = polygone.getLines();
    
    Point *r;
    Point *best = nullptr;
    double distance, bestdistance = std::numeric_limits<double>::infinity();
    
    for(std::vector<Line>::iterator it = lines.begin(); it != lines.end(); it++)
    {
        r = this->cast(*it);
        
        if (r != nullptr)
        {
            
            distance = pos.distance(*r);
            if (best != nullptr)
            {
                if(bestdistance > distance)
                {
                    best = new Point(r->x, r->y);
                    bestdistance = distance;
                }
                continue;

            }
            best = new Point(r->x, r->y);
            bestdistance = distance;
        }
    }
    
    return best;
    
}

Point* Ray::cast(Line &line)
{
    return Line(pos, Point(pos.x + dir.x, pos.y + dir.y)).TouchingLines(line);
}

std::vector<Point> Ray::cast(Circle &c)
{
    std::vector<Point> vector_r = c.TouchingLine(Line(pos, Point(pos.x + dir.x, pos.y + dir.y)));
    return vector_r;
}



void Ray::RenderCast(std::vector<Polygone> plist, std::vector<Circle> clist, std::vector<Point> ptslist, SDL_Renderer *renderer, const int color[4])
{
    Point *best = nullptr;
    double distance, bestdistance = std::numeric_limits<double>::infinity();
    
    for(std::vector<Polygone>::iterator it = plist.begin(); it != plist.end(); it++)
    {
        Point *pts = this->cast(*it);
        if(pts != nullptr)
        {
            distance = pos.distance(*pts);
            if (best != nullptr)
            {
                if(bestdistance > distance)
                {
                    best = new Point(pts->x, pts->y);
                    bestdistance = distance;
                }
                continue;

            }
            best = new Point(pts->x, pts->y);
            bestdistance = distance;
        }
        
    }
    for(std::vector<Circle>::iterator it = clist.begin(); it != clist.end(); it++)
    {
        std::vector<Point> vector_r = this->cast(*it);
        if(vector_r.size() > 0)
        {
            for(std::vector<Point>::iterator it_p = vector_r.begin(); it_p != vector_r.end(); it_p++)
            {

                distance = pos.distance(*it_p);
                if (best != nullptr)
                {
                    if(bestdistance > distance)
                    {
                        best = new Point(it_p->x, it_p->y);
                        bestdistance = distance;
                    }
                    continue;

                }
                best = new Point(it_p->x, it_p->y);
                bestdistance = distance;
            }
        }
        
    }
    for(std::vector<Point>::iterator it = ptslist.begin(); it != ptslist.end(); it++)
    {
        Point __p = Point(it->x, it->y);
        Line __l = Line(__p, __p);
        Point *pts = this->cast(__l);
        if(pts != nullptr)
        {
            distance = pos.distance(*pts);
            if (best != nullptr)
            {
                if(bestdistance > distance)
                {
                    best = new Point(pts->x, pts->y);
                    bestdistance = distance;
                }
                continue;

            }
            best = new Point(pts->x, pts->y);
            bestdistance = distance;
        }
        
    }
    //Render Circle
    if (best != nullptr)
    {
        Circle c = Circle(3, *best);
        Line l = Line(Point(pos.x, pos.y), Point(best->x, best->y));
        l.render(renderer, color);
        c.render(renderer, color, true);
    }
        
}

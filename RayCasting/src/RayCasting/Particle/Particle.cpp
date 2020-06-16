//
//  Particle.cpp
//  RayCasting
//
//  Created by Guillaume Vitalis on 15/06/2020.
//  Copyright © 2020 CHOOSEIT. All rights reserved.
//

#include "Particle.hpp"


Particle::Particle(int decalage, Point pos): pos(pos)
{
    for(int i = 0; i < 360; i += decalage)
    {
        rlist.push_back(Ray(pos, RadiansfromDegrees(i)));
    }
}

Particle::Particle(): pos(Point(0, 0))
{
    for(int i = 0; i < 360; i += 10)
    {
        rlist.push_back(Ray(pos, RadiansfromDegrees(i)));
    }
}

void Particle::render(SDL_Renderer *renderer, const int *color)
{
    
    for(std::vector<Ray>::iterator it = rlist.begin(); it != rlist.end(); it ++)
    {
        it->pos = pos;
        it->render(renderer, color);
    }
    
    Circle c = Circle(5, pos);
    c.render(renderer, color, true);
}

void Particle::RenderCast(std::vector<Polygone> plist, std::vector<Circle> clist, std::vector<Point> ptslist , SDL_Renderer *renderer, const int color[4])
{
    for(std::vector<Ray>::iterator it = rlist.begin(); it != rlist.end(); it ++)
    {
        it->RenderCast(plist, clist, ptslist, renderer, color);
    }
}

//
//  Ray.hpp
//  RayCasting
//
//  Created by Guillaume Vitalis on 15/06/2020.
//  Copyright © 2020 CHOOSEIT. All rights reserved.
//

#ifndef Ray_hpp
#define Ray_hpp

#include <SDL2/SDL.h>
#include "Point.hpp"
#include "Polygone.hpp"
#include "Line.hpp"
#include "Vector2d.hpp"
#include "Circle.hpp"

class Ray
{
public:
    Ray(const Point p, const double Radians);

    
    void LookAt(const Point p);
    
    void render(SDL_Renderer *renderer, const int color[4]);
    
    Point* cast(Polygone &polygone);
    Point* cast(Line &line);
    std::vector<Point> cast(Circle &c);
    
    void RenderCast(std::vector<Polygone> plist, std::vector<Circle> clist, std::vector<Point> ptslist, SDL_Renderer *renderer, const int color[4]);
    
    //Variables
    Point pos;
    Vector2d dir;
    
    //Static member
    
    
    
    
};



#endif /* Ray_hpp */

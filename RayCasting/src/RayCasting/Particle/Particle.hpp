//
//  Particle.hpp
//  RayCasting
//
//  Created by Guillaume Vitalis on 15/06/2020.
//  Copyright © 2020 CHOOSEIT. All rights reserved.
//

#ifndef Particle_hpp
#define Particle_hpp

#include "Ray.hpp"
#include "Utils.hpp"

class Particle
{
public:
    Particle(int decalage, Point pos);
    Particle();
    
    void render(SDL_Renderer *renderer, const int color[4]);
    
    void RenderCast(std::vector<Polygone> plist, std::vector<Circle> clist, std::vector<Point> ptslist , SDL_Renderer *renderer, const int color[4]);
    
    
    std::vector<Ray> rlist;
    Point pos;
};

#endif /* Particle_hpp */

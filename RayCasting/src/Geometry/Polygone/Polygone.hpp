//
//  Polygone.hpp
//  RayCasting
//
//  Created by Guillaume Vitalis on 14/06/2020.
//  Copyright © 2020 CHOOSEIT. All rights reserved.
//

#ifndef Polygone_hpp
#define Polygone_hpp

#include <vector>
#include "Point.hpp"
#include "Line.hpp"


class Polygone
{
public:
    Polygone();
    
    void addPoint(const Point &p);
    void addPoint(const std::vector<Point> p);
    
    void clearPoints();
    
    std::vector<Line> getLines();
    
    void getPoints(std::vector<Point> &pts);
    void setPoints(const std::vector<Point> pts);
    
    void render(SDL_Renderer *renderer);
    
    
    
    
private:
    std::vector<Point> points;
};

#endif /* Polygone_hpp */

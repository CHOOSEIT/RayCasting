//
//  Vector2d.hpp
//  RayCasting
//
//  Created by Guillaume Vitalis on 14/06/2020.
//  Copyright © 2020 CHOOSEIT. All rights reserved.
//

#ifndef Vector2d_hpp
#define Vector2d_hpp

#include <cmath>
#include "Point.hpp"
#include "Utils.hpp"

class Vector2d
{
    
public:
    Vector2d(const Point &A, const Point &B);
    Vector2d(const int x, const int y);
    Vector2d(const float x, const float y);
    Vector2d(const double x, const double y);
    Vector2d();
    
    double length();
    
    void fromDegrees(double Degrees);
    void fromRadians(double Radians);
    
    double getDegrees();
    double getRadians();
    
    void normalize();
    
    double x, y;
    
};

#endif /* Vector2d_hpp */

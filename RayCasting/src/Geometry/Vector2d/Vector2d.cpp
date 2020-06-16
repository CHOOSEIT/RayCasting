//
//  Vector2d.cpp
//  RayCasting
//
//  Created by Guillaume Vitalis on 14/06/2020.
//  Copyright © 2020 CHOOSEIT. All rights reserved.
//

#include "Vector2d.hpp"



Vector2d::Vector2d(const Point &A, const Point &B)
{
    x = B.x - A.x;
    y = B.y - A.y;
}

Vector2d::Vector2d(const int x, const int y): x((double) x), y((double) y)
{}

Vector2d::Vector2d(const float x, const float y): x((double) x), y((double) y)
{}

Vector2d::Vector2d(const double x, const double y): x(x), y(y)
{}

Vector2d::Vector2d(): x(0), y(0)
{}

double Vector2d::length()
{
    return sqrt(pow(x, 2) + pow(y, 2));
}

void Vector2d::fromDegrees(double Degrees)
{
    fromRadians(RadiansfromDegrees(360 - Degrees));
}

void Vector2d::fromRadians(double Radians)
{
    x = cos(Radians);
    y = sin(Radians);
}

double Vector2d::getDegrees()
{
    return DegreesfromRadians(getRadians());
}

double Vector2d::getRadians()
{
    return tan(y / x);
}

void Vector2d::normalize()
{
    double l = length();
    x = x / l;
    y = y / l;
}

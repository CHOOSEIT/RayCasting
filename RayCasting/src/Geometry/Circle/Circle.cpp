//
//  Circle.cpp
//  RayCasting
//
//  Created by Guillaume Vitalis on 15/06/2020.
//  Copyright © 2020 CHOOSEIT. All rights reserved.
//

#include "Circle.hpp"

#include <iostream>

Circle::Circle(double Radius, Point pt): radius(Radius), pos(pt)
{
}


void Circle::render(SDL_Renderer *renderer, const int color[4])
{
    render(renderer, color, false);
}

void Circle::render(SDL_Renderer *renderer, const int color[4], const bool fill)
{
    SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
    if (fill)
    {
        for(int r = 0; r < radius; r++)
        {
            for(int a = 0; a < 360; a++)
            {
                SDL_RenderDrawPoint(renderer, pos.x + cos(RadiansfromDegrees(a)) * r, pos.y + sin(RadiansfromDegrees(a)) * r);
            }
        }
    }
    else
    {
        for(int a = 0; a < 360; a++)
        {
            SDL_RenderDrawPoint(renderer, pos.x + cos(RadiansfromDegrees(a)) * radius, pos.y + sin(RadiansfromDegrees(a)) * radius);
        }
    }
}

std::vector<Point> Circle::TouchingLine(const Line &line)
{
    float cx = (float) pos.x;
    float cy = (float) pos.y;
    float r = (float) radius;
    
    float Dx = line.B.x - line.A.x;
    float Dy = line.B.y - line.A.y;
    
    float A = Dx * Dx + Dy * Dy;
    float B = 2 * (Dx * (line.A.x - cx) + Dy * (line.A.y - cy));
    float C = (line.A.x - cx) * (line.A.x - cx) + (line.A.y - cy) * (line.A.y - cy) - r * r;
    
    float det = B * B - 4 * A * C;
    
    std::vector<Point> vector_r;
    
    if (A <= 0.0000001 or det < 0)
    {
        //No intersections
        return vector_r;
    }
    else if(det == 0)
    {
        float t = -B / (2 * A);
        // One intersection
        Point i1 = Point(line.A.x + t * Dx, line.A.y + t * Dy);
        vector_r.push_back(i1);
        return vector_r;
    }
    else
    {
        float t = ((-B + sqrt(det)) / (2 * A));
        Point i1 = Point(line.A.x + t * Dx, line.A.y + t * Dy);
        t = ((-B - sqrt(det)) / (2 * A));
        Point i2 = Point(line.A.x + t * Dx, line.A.y + t * Dy);
        
        vector_r.push_back(i1);
        vector_r.push_back(i2);
        
        return vector_r;
    }
    

}

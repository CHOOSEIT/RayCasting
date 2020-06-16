//
//  PaintingOption.hpp
//  RayCasting
//
//  Created by Guillaume Vitalis on 15/06/2020.
//  Copyright © 2020 CHOOSEIT. All rights reserved.
//

#ifndef PaintingOption_hpp
#define PaintingOption_hpp

#include "Polygone.hpp"
#include "Point.hpp"
#include "Circle.hpp"
#include <vector>
#include <string>


class PaintingOption
{
public:
    PaintingOption();
    
    void render(SDL_Renderer *renderer, int WIDTH, int HEIGHT, int dec, int MouseX, int MouseY, std::vector<Polygone> *polygones);
    
    int optionValue;
    
    void LeftMousePressed(int MouseX, int MouseY, int WIDTH, int HEIGHT, int screendeca, std::vector<Polygone> *polygones, std::vector<Circle> *circle, std::vector<Point> *point);
    void RightMousePressed(int MouseX, int MouseY, int WIDTH, int HEIGHT, int screendeca);
    
    void ChangeOption(std::vector<Polygone> *polygones);
    
private:
    int index_lastpolygoneadded;
    
    int size_circle;
    
    int size = 100;
    
};

#endif /* PaintingOption_hpp */

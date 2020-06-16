//
//  PaintingOption.cpp
//  RayCasting
//
//  Created by Guillaume Vitalis on 15/06/2020.
//  Copyright © 2020 CHOOSEIT. All rights reserved.
//

#include "PaintingOption.hpp"



PaintingOption::PaintingOption(): optionValue(0), size_circle(5)
{
    
}

void PaintingOption::render(SDL_Renderer *renderer, int WIDTH, int HEIGHT, int dec, int MouseX, int MouseY, std::vector<Polygone> *polygones)
{
    int color[4] = {255, 255, 255, SDL_ALPHA_OPAQUE};
    
    Polygone polygoneCase = Polygone();
    
    
    
    int width = 5;
    
    if(optionValue == 3)
    {
        Circle c = Circle(30, Point(WIDTH - dec - size/2, HEIGHT - dec - size/2));
        c.render(renderer, color);
        
        int size_text = 25;
        RenderText(100, std::to_string(size_circle), renderer, Point(WIDTH - dec - size/2 - size_text/2, HEIGHT - dec - size/2- size_text/2), size_text, size_text);
        
        Circle _c = Circle(size_circle, Point(MouseX, MouseY));
        _c.render(renderer, color);
        
    }
    else if(optionValue == 2)
    {
        int color[4] = {255, 255, 255, SDL_ALPHA_OPAQUE};
        Polygone renderoption = Polygone();
        renderoption.addPoint((std::vector<Point>) {Point(WIDTH - size / 3 - dec - size/2, HEIGHT - size / 3 - dec - size/2), Point(WIDTH - size / 3 - dec - size/2, HEIGHT + size /3- dec - size/2), Point(WIDTH + size/3 - dec - size/2, HEIGHT + size / 4 - dec - size/2)});
        renderoption.render(renderer);
        
        std::vector<Point> pts_current_polygone;
        Polygone Current = (*polygones)[index_lastpolygoneadded];
        Current.getPoints(pts_current_polygone);
        if(pts_current_polygone.size() > 0)
        {
            Point last = pts_current_polygone[pts_current_polygone.size() - 1];
            Line new_line = Line(last, Point(MouseX, MouseY));
            new_line.render(renderer, color);
        }
        
        
    }
    
    for(int n = 0; n < width; n++)
    {
        polygoneCase.clearPoints();
        polygoneCase.addPoint((std::vector<Point>){Point(WIDTH - dec - n, HEIGHT - dec - n), Point(WIDTH - dec - size + n, HEIGHT - dec - n), Point(WIDTH - dec - size + n, HEIGHT - dec - size + n), Point(WIDTH - dec - n, HEIGHT - dec - size + n)});
        polygoneCase.render(renderer);
    }
    
}


void PaintingOption::LeftMousePressed(int MouseX, int MouseY, int WIDTH, int HEIGHT, int screendeca, std::vector<Polygone> *polygones, std::vector<Circle> *circle, std::vector<Point> *point)
{
    if(MouseX > WIDTH - size and MouseX < WIDTH and MouseY > HEIGHT - size and MouseY < HEIGHT)
    {
        ChangeOption(polygones);
        return;
    }
    
    if(optionValue == 2)
    {
        std::vector<Polygone>& vec = *polygones;
        Polygone *pol = &vec[index_lastpolygoneadded];
        pol->addPoint(Point(MouseX, MouseY));
    }
    else if(optionValue == 3)
    {
        circle->push_back(Circle(size_circle, Point(MouseX, MouseY)));
    }
    else if(optionValue == 4)
    {
        point ->push_back(Point(MouseX, MouseY));
        
    }
    
}

void PaintingOption::RightMousePressed(int MouseX, int MouseY, int WIDTH, int HEIGHT, int screendeca)
{
    if(MouseX > WIDTH - size and MouseX < WIDTH and MouseY > HEIGHT - size and MouseY < HEIGHT and optionValue == 3)
    {
        size_circle += 1;
        if(size_circle == 51)
        {
            size_circle = 5;
        }
        return;
    }
}

void PaintingOption::ChangeOption(std::vector<Polygone> *polygones)
{
    switch (optionValue) {
        case 1:
            index_lastpolygoneadded = (int) polygones->size();
            polygones->push_back(Polygone());
            break;
        case 2:
            size_circle = 5;
            break;
            
        case 3:
            //disable points 
            optionValue = 0;
            break;
            
        case 4:
            
            optionValue = 0;
            break;
            
            
        default:
            
            break;
    }
    optionValue += 1;
}

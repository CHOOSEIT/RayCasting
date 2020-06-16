//
//  Engine.hpp
//  RayCasting
//
//  Created by Guillaume Vitalis on 14/06/2020.
//  Copyright © 2020 CHOOSEIT. All rights reserved.
//

#ifndef Engine_hpp
#define Engine_hpp

#include <iostream>
#include <SDL2/SDL.h>


#include "Circle.hpp"
#include "Vector2d.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Ray.hpp"
#include "Polygone.hpp"
#include "Utils.hpp"
#include "Particle.hpp"
#include "PaintingOption.hpp"

#include <string>



class Engine
{
public:
    Engine(const char* title, int WIDTH, int HEIGHT);
    ~Engine();
    
    bool isRunning();
    
    void handleEvents();
    
    void render();
    
    void update();
    
    void setup();
    
    int FPS;
    int FrameDelay;
    
    std::vector<Polygone> p;
    std::vector<Circle> c;
    std::vector<Point> ptslist;
    
    int key[2] = {0, 0};

    SDL_Window *window;
    SDL_Renderer *renderer;
    
    bool running = false;
    
    int WIDTH, HEIGHT;
    int screendeca;
    
    
    Particle particle;
    
    PaintingOption paintingOption;
    
    
    
    
};



#endif /* Engine_hpp */

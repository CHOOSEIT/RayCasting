//
//  main.cpp
//  RayTracing
//
//  Created by CHOOSEIT on 14/06/2020.
//  Copyright © 2020 CHOOSEIT. All rights reserved.
//

#include <iostream>

//SDL2
#include <SDL2/SDL.h>

//Include
#include "Engine.hpp"

const int WIDTH = 1000, HEIGHT = 750;

using namespace std;

int main(int argc, const char * argv[])
{

    
    
    Engine *engine = new Engine("RayCasting", WIDTH, HEIGHT);
    
    engine->setup();
    engine->FPS = 60;
    engine->FrameDelay = 1000 / engine->FPS;
    
    Uint32 frameStart;
    int frameTime;
    
    while(engine->isRunning())
    {
        engine->handleEvents();
        
        frameStart = SDL_GetTicks();
        
        engine->render();
        
        frameTime = SDL_GetTicks() - frameStart;
        
        if(engine->FrameDelay > frameTime)
        {
            
            SDL_Delay(engine->FrameDelay - frameTime);
        }
    }
    
    engine->~Engine();
    TTF_Quit();
    return 0;
    
}


//
//  Engine.cpp
//  RayCasting
//
//  Created by Guillaume Vitalis on 14/06/2020.
//  Copyright © 2020 CHOOSEIT. All rights reserved.
//

#include "Engine.hpp"


using namespace std;


Engine::Engine(const char* title, int WIDTH, int HEIGHT) : WIDTH(WIDTH), HEIGHT(HEIGHT), screendeca(3)
{
    
    
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        cout << "Error: SDL2 Load" << endl;
        return;
    }
    
    if(TTF_Init() == -1)
    {
        cout << "Error: SDL2_TTF Load" << endl;
        return;
    }
    
    window = SDL_CreateWindow("RayCasting", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    if (window == nullptr)
    {
        cout << "Error: Screen creation" << endl;
        return;
    }
    
    running = true;
    
    
}

Engine::~Engine()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    
    cout << "Bye :)" << endl;
}

bool Engine::isRunning()
{
    return running;
}

void Engine::setup()
{
    Vector2d(1, 1);
    
    p.push_back(Polygone());
    p[0].addPoint((vector<Point>) {Point(200, 300), Point(250, 140), Point(330, 110)});
    
    p.push_back(Polygone());
    p[1].addPoint((vector<Point>) {Point(300, 400), Point(350, 510), Point(360, 166), Point(120, 160)});
    
    p.push_back(Polygone());
    p[2].addPoint((vector<Point>) {Point(400, 700), Point(650, 710), Point(160, 366), Point(420, 260), Point(220, 560)});
    
    p.push_back(Polygone());
    
    particle = Particle(10, Point(WIDTH/2, HEIGHT/2));
    
    paintingOption.ChangeOption(&p);
    
    
}

void Engine::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    if(key[0] > 0 and paintingOption.optionValue != 1)
    {
        key[0] = key[0] + 1;
        int value = key[0];
        cout << value << endl;
    }
    if(key[0] >= 10 and paintingOption.optionValue != 1)
    {
        int xMouse, yMouse;
        SDL_GetMouseState(&xMouse,&yMouse);
        paintingOption.LeftMousePressed(xMouse, yMouse, WIDTH, HEIGHT, screendeca, &p, &c, &ptslist);
    }
    switch (event.type)
    {
        case SDL_WINDOWEVENT:
            if(event.window.event == SDL_WINDOWEVENT_LEAVE)
            {
                key[0] = 0;
                key[1] = 0;
                break;
            }
            break;
        case SDL_QUIT:
            running = false;
            break;
            
        case SDL_MOUSEBUTTONUP:
            if(event.button.button == (SDL_BUTTON_LEFT))
            {
                key[0] = 0;
                int xMouse, yMouse;
                SDL_GetMouseState(&xMouse,&yMouse);
                paintingOption.LeftMousePressed(xMouse, yMouse, WIDTH, HEIGHT, screendeca, &p, &c, &ptslist);
                break;
            }
            if(event.button.button == (SDL_BUTTON_RIGHT))
            {
                key[1] = 0;
                int xMouse, yMouse;
                SDL_GetMouseState(&xMouse,&yMouse);
                paintingOption.RightMousePressed(xMouse, yMouse, WIDTH, HEIGHT, screendeca);
                break;
            }
            
        case SDL_MOUSEBUTTONDOWN:
            if(event.button.button == (SDL_BUTTON_LEFT))
            {
                
                key[0] = 1;
                break;
            }
            if(event.button.button == (SDL_BUTTON_RIGHT))
            {
                key[1] = 1;
                break;
            }
        
            break;
            
        
                
        default:
            break;
    }
}

void Engine::update()
{
    
    
}

void Engine::render()
{
    int color[4] = {255, 255, 255, SDL_ALPHA_OPAQUE};
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    
    for(std::vector<Polygone>::iterator it = p.begin(); it != p.end(); it++)
    {
        it->render(renderer);
    }
    for(std::vector<Circle>::iterator it = c.begin(); it != c.end(); it++)
    {
        it->render(renderer, color);
    }
    for(std::vector<Point>::iterator it = ptslist.begin(); it != ptslist.end(); it++)
    {
        it->render(renderer, color);
    }
    int xMouse, yMouse;
    SDL_GetMouseState(&xMouse,&yMouse);
    particle.pos = Point(xMouse, yMouse);
    particle.render(renderer, color);
    if (paintingOption.optionValue == 1)
    {
        particle.RenderCast(p, c, ptslist, renderer, color);
    }
    
    
    paintingOption.render(renderer, WIDTH, HEIGHT, screendeca, xMouse, yMouse, &p);
    
    
    
    
    
    
    
    
    
    

    
    
    SDL_RenderPresent(renderer);
}

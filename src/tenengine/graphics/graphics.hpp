#pragma once

#include "../common.h"

#include <string>
#include <SDL2/SDL.h>


class Window
{
public:
    Window(std::string title);
    SDL_Renderer* getRender();
    int width();
    int height();
    void calcFPS();
    float getFPS();
private:
    std::string _title;
    int _w, _h;
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    float _fps;
    float _frameTime;
};

class Camera
{
public:
    Camera(int w, int h, float scale, int x, int y);
    SDL_Rect* getViewport();
private:
    SDL_Rect _rect;
};
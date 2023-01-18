#pragma once

#include "../common.h"

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Window
{
public:
    Window(std::string title);
    SDL_Renderer* getRender();
    int width();
    int height();
    void calcFPS(int period);
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
    Camera(float scale, int w, int h, int cScale);

    SDL_Rect* getViewport(float x, float y);
private:
    SDL_Rect _rect;
    float _cScale;
};

class Debug
{
public:
    Debug(SDL_Renderer* renderer);
    void render(float fps, float x, float y);
private:
    TTF_Font* _font;
    SDL_Renderer* _renderer;
    SDL_Rect _rect;
};
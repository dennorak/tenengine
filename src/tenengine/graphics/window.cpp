#include "graphics.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>



Window::Window(std::string title): _title(title), _window(nullptr), _renderer(nullptr)
{
    // create window
    _window = SDL_CreateWindow(_title.c_str(), 0, 0, 0, 0, SDL_WINDOW_HIDDEN);
    if (_window == nullptr) err("Could not create window.");
    // get the actual display size
    SDL_Rect rect;
    SDL_GetDisplayUsableBounds(0, &rect);
    _w = rect.w;
    _h = rect.h;
    // resize the window to the right size (c'mon sdl... :/ )
    SDL_SetWindowSize(_window, _w, _h);
    // create the renderer + clear
    _renderer = SDL_CreateRenderer(_window, 0, 0);
    if (_renderer == nullptr) err("Could not create renderer.");
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);
    SDL_RenderClear(_renderer);
    // show the window
    SDL_ShowWindow(_window);
    SDL_RenderPresent(_renderer);
};

SDL_Renderer* Window::getRender()
{
    return _renderer;
}

int Window::width()
{
    return _w;
};

int Window::height()
{
    return _h;
};

void Window::calcFPS(int period)
{
    static const int NUM_SAMPLES = 10;
    static float frameTime[NUM_SAMPLES];
    static int currentFrame = 0;
    static float prevTicks = SDL_GetTicks();
    float currentTicks; // one operation
    currentTicks = SDL_GetTicks();
    _frameTime = currentTicks - prevTicks;
    frameTime[currentFrame % NUM_SAMPLES] = _frameTime;
    prevTicks = currentTicks;
    int count;
    currentFrame++;
    if (currentFrame < NUM_SAMPLES)
    {
        count = currentFrame;
    } else {
        count = NUM_SAMPLES;
    }
    float frameTimeAvg = 0;
    for (int i = 0; i < count; i++)
    {
        frameTimeAvg += frameTime[i];
    }
    frameTimeAvg /= count;
    frameTimeAvg /= period;
    if (frameTimeAvg > 0)
    {
        _fps = 1000.0f / frameTimeAvg;
    } else {
        _fps = 60.0f;
    }
}

float Window::getFPS()
{
    return _fps;
};
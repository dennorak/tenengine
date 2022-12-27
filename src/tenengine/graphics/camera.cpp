#include "graphics.hpp"


Camera::Camera(int w, int h, float scale, int x, int y)
{
    _rect.x = x;
    _rect.y = y;
    
    float ar = (float)h / (float)w;

    _rect.w = scale;
    _rect.h = ar*scale;
}

SDL_Rect* Camera::getViewport()
{
    return &_rect;
}
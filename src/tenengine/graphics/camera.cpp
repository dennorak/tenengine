#include "graphics.hpp"


Camera::Camera(int mw, int mh, float scale, int ww, int wh): _ww(ww), _wh(wh), _scale(scale)
{
    _rect.x = 0; // TODO: make the camera move
    _rect.y = 0; // TODO: make the camera move
    
    float ar = (float)mh / (float)mw;

    _rect.w = scale;
    _rect.h = ar*scale;
}

SDL_Rect* Camera::getViewport()
{
    return &_rect;
}

float Camera::getScale()
{
    return (float)_ww/_scale;
}
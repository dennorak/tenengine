#include "graphics.hpp"

Camera::Camera(float scale, int w, int h, int cScale): _cScale(cScale)
{
    _rect.x = 0;
    _rect.y = 0;
    _rect.w = scale * _cScale;

    _ar = (float)h/(float)w;
    _rect.h = _rect.w * _ar;
};

SDL_Rect* Camera::getViewport(float x, float y)
{
    _rect.x = x * _cScale - (_rect.w/2) + 1;
    _rect.y = y * _cScale - (_rect.h/2) + 1;
    return &_rect;
}

float Camera::getAR()
{
    return _ar;
}
#include "entity.hpp"

Player::Player(std::string path, int w, int h, Window window, int x, int y):
    _renderer(window.getRender())
{
    _rect.w = w;
    _rect.h = h;
    _rect.x = (window.width()/2)  - (w/2);
    _rect.y = (window.height()/2) - (h/2);
    _x = (float) x;
    _y = (float) y;
    _texture = IMG_LoadTexture(_renderer, path.c_str());
}

void Player::render(float scale)
{
    SDL_Rect rect = _rect;
    rect.w *= scale;
    rect.h *= scale;
    SDL_RenderCopy(_renderer, _texture, NULL, &rect);
}

void Player::move(float dx, float dy)
{
    if (_x + dx > 0) _x += dx;
    if (_y + dy > 0) _y += dy;
}

float Player::getX() { return _x; }
float Player::getY() { return _y; }
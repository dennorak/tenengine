#include "entity.hpp"

Player::Player(std::string path, int s, Window window, Tiled::Map map):
    _renderer(window.getRender()),
    _window(window),
    _map(map)
{
    _rect.w = s;
    _rect.h = s;
    _rect.x = (window.width()/2);
    _rect.y = (window.height()/2);
    _x = _map.spawnX();
    _y = _map.spawnY();
    _texture = IMG_LoadTexture(_renderer, path.c_str());
}

void Player::render(float scale)
{
    SDL_Rect rect = _rect;
    rect.w *= scale;
    rect.h *= scale;
    rect.x -= _rect.w*scale/2;
    rect.y -= _rect.h*scale/2;
    SDL_RenderCopy(_renderer, _texture, NULL, &rect);
}

void Player::move(float dx, float dy, float ar)
{
    if (_x + dx > (_map.scale()/2) & _x + dx < _map.width()-(_map.scale()/2)) _x += dx;
    if (_y + dy > (_map.scale()/2*ar) & _y + dy < _map.height()-(_map.scale()/2*ar)) _y += dy;
}

float Player::getX() { return _x; }
float Player::getY() { return _y; }
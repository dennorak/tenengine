#include "entity.hpp"
#include <iostream>

Player::Player(std::string path, int x, int y, SDL_Renderer* renderer): _renderer(renderer)
{
    _pos.x = (float)x;
    _pos.y = (float)y;
    _texture = IMG_LoadTexture(_renderer, path.c_str());
}

void Player::render(int w, int h, float mapScale, float renderScale)
{
    std::cout << renderScale << " " << mapScale << std::endl;

    SDL_Rect rect;
    rect.w = w * renderScale;// * 0.8f; // make the player 20% smaller
    rect.h = h * renderScale;// * 0.8f; // make the player 20% smaller
    rect.x = _pos.x * mapScale;
    rect.y = _pos.y * mapScale;

    std::cout << rect.w << " "  << rect.h << " "  << rect.x << " "  << rect.y << " " << std::endl;

    SDL_RenderCopy(_renderer, _texture, NULL, &rect);
};

void Player::move(float dx, float dy)
{
    // TODO: collision goes here somwhere
    _pos.x += dx;
    _pos.y += dy;

    //dbg(std::to_string(_pos.x) + " " + std::to_string(_pos.y));
}
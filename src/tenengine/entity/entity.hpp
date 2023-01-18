#pragma once
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../common.h"
#include "../graphics/graphics.hpp"

class Player
{
public:
    Player(std::string path, int w, int h, Window window, int x, int y);

    void render(float scale);
    void move(float dx, float dy);

    float getX();
    float getY();
private:
    SDL_Texture* _texture;
    SDL_Renderer* _renderer;
    SDL_Rect _rect;
    float _x, _y;
};
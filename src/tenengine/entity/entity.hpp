#pragma once
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../common.h"
#include "../graphics/graphics.hpp"
#include "../tiled/tiled.hpp"

class Player
{
public:
    Player(std::string path, int s, Window window, Tiled::Map map);

    void render(float scale);
    void move(float dx, float dy, float ar);

    float getX();
    float getY();
private:
    SDL_Texture* _texture;
    SDL_Renderer* _renderer;
    SDL_Rect _rect;
    Window _window;
    Tiled::Map _map;
    float _x, _y;
};
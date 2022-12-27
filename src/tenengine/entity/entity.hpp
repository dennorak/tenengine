#pragma once
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../common.h"

struct Position
{
    float x;
    float y;
};

class Player
{
public:
    Player(std::string path, int x, int y, SDL_Renderer* renderer);
    void render(int w, int h, float mapScale, float renderScale);
    void move(float dx, float dy);
private:
    SDL_Texture* _texture;
    Position _pos;
    SDL_Renderer* _renderer;
};
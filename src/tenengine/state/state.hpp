#pragma once

#include "../common.h"
#include "../graphics/graphics.hpp"
#include "../tiled/tiled.hpp"
#include "../entity/entity.hpp"
#include "../input/input.hpp"

// pack defs
#define PACKPATH "assets/data/atlas.tsx"
#define TEXPATH "assets/textures/atlas.png"

#define LEVEL_MENU "assets/data/menu.tmx"

// state defs

class IState
{
public:
    IState(Window window, std::string mapPath);
    virtual void tick(Keyboard& kb);
    virtual void render();
    float playerX();
    float playerY();
    SDL_Rect* getCameraViewport();
protected:
    Window _window;
    Tiled::Set _set;
    Tiled::Map _map;
    Player _player;
    Camera _camera;
};

class LoadState: public IState
{
public:
    LoadState(Window window);
    void render();
    void tick(Keyboard& kb);
};
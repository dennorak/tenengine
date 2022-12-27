#pragma once
#include "tiled/tiled.hpp"
#include "graphics/graphics.hpp"
#include "entity/entity.hpp"
#include "input/input.hpp"
#include "common.h"

enum State {
    LOAD,
    MENU,
    PLAY,
    STOP,
    EXIT
};

class Engine
{
public:
    Engine();

    void run();
private:
    Window _window;
    Tiled::Set _tiles;
    State _state;
    Keyboard _kb;

    // temp
    Tiled::Map _map;
    Camera _camera;
    Player _player;
};
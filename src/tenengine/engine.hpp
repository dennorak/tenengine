#pragma once

#include "common.h"
#include "graphics/graphics.hpp"
#include "tiled/tiled.hpp"
#include "entity/entity.hpp"
#include "state/state.hpp"
#include "input/input.hpp"

#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

enum EState
{
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
    EState _gameState;
    std::vector<IState*> _playStates;
    int _playState;
    Debug _debug;
    bool _showDebug;
    Keyboard _kb;

    // states
    LoadState _loadState;
};
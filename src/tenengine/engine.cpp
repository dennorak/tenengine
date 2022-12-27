#include "engine.hpp"
#include <SDL2/SDL_render.h>

Engine::Engine():
    _window("Tenengine"),
    _tiles(Tiled::Set(PACKPATH, _window.getRender(), TEXPATH)),
    _map(Tiled::Map(_tiles, MAPPATH, _window.getRender(), _window.width())),
    _state(State::LOAD),
    _kb(),
    _camera(_map.width(), _map.height(), _map.getScale() * _tiles.getSize(), 0, 0)
{
    dbg("Engine successfully initialized.");
}

void Engine::run()
{
    while (_state != State::EXIT)
    {
        // poll the events
        SDL_Event e;
        SDL_PollEvent(&e);
        switch (e.key.type)
        {
            case SDL_QUIT:
                _state = State::EXIT;
                break;
            case SDL_KEYDOWN:
                _kb.keyPress(e.key.keysym.sym);
                break;
            case SDL_KEYUP:
                _kb.keyRelease(e.key.keysym.sym);
                break;
        }
        // render the screen
        _map.render(_camera.getViewport(), 1, NULL);
        SDL_RenderPresent(_window.getRender());
    }
}
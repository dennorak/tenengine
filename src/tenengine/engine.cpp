#include "engine.hpp"
#include <SDL2/SDL_render.h>

Engine::Engine():
    _window("Tenengine"),
    _tiles(Tiled::Set(PACKPATH, _window.getRender(), TEXPATH)),
    _state(State::LOAD),
    _kb(),
    _map(Tiled::Map(_tiles, MAPPATH, _window.getRender(), _window.width())),
    _camera(_map.width(), _map.height(), _map.getScale() * _tiles.getSize(), _window.width(), _window.height()),
    _player(PLAYERTEX, _map.spawnX(), _map.spawnY(), _window.getRender())
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

        float PSPEED = 0.001f * _map.getScale();

        // update the player
        if (_kb.isKeyPressed(SDLK_w)) _player.move(0, -PSPEED);
        if (_kb.isKeyPressed(SDLK_a)) _player.move(-PSPEED, 0);
        if (_kb.isKeyPressed(SDLK_s)) _player.move(0, PSPEED);
        if (_kb.isKeyPressed(SDLK_d)) _player.move(PSPEED, 0);

        // TODO: Move the camera if the player is near the edge

        // std::cout << "tile: " << _tiles.getSize() * _camera.getScale() * _map.getScale() << std::endl;

        // render the screen
        _map.render(_camera.getViewport(), 1, NULL);
        _player.render(
            _tiles.getSize(),
            _tiles.getSize(),
            _map.getScale(),
            _camera.getScale()
        );
        SDL_RenderPresent(_window.getRender());
    }
}
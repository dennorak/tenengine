#include "engine.hpp"

Engine::Engine():
    _window("tenengine"),
    _gameState(EState::LOAD),
    _playState(0),
    _debug(_window.getRender()),
    _showDebug(true), // NOTE: remove this from prod
    _kb(),
    _loadState(_window)
{
    // init sdl
    SDL_Init(SDL_INIT_EVERYTHING);
    // load the state
    _playStates.push_back(&_loadState);
};

void Engine::run()
{
    int frameCount = 0;
    while (_gameState != EState::EXIT)
    {
        // tick block
        SDL_Event e;
        SDL_PollEvent(&e);
        switch (e.key.type)
        {
            case SDL_QUIT:
                _gameState = EState::EXIT;
                break;
            case SDL_KEYDOWN:
                if (e.key.keysym.sym == SDLK_F3)
                {
                    _showDebug = !_showDebug;
                } else _kb.keyPress(e.key.keysym.sym);
                break;
            case SDL_KEYUP:
                _kb.keyRelease(e.key.keysym.sym);
                break;
        }
        _playStates[_playState]->tick(_kb);

        float px = _playStates[_playState]->playerX();
        float py = _playStates[_playState]->playerY();

        // render block
        SDL_RenderClear(_window.getRender());
        _playStates[_playState]->render();
        if (_showDebug) _debug.render(_window.getFPS(), px, py, _playStates[_playState]->scale());
        SDL_RenderPresent(_window.getRender());

        // update frame ctr periodically
        frameCount++;
        if (frameCount >= 20)
        {
            _window.calcFPS(20);
            frameCount = 0;
        }
    };
};
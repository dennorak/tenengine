#include "state.hpp"

IState::IState(Window window, std::string mapPath):
    _window(window),
    _set(Tiled::Set(PACKPATH, _window.getRender(), TEXPATH)),
    _map(Tiled::Map(_set, mapPath, _window.getRender(), _window.width())),
    _player(PLAYERTEX, 32, 32, _window, _map.spawnX(), _map.spawnY()),
    _camera(_map.getScale(), _window.width(), _window.height(), _set.getSize())
{

};

void IState::tick(Keyboard& kb)
{
    err("IState tick");
}

void IState::render()
{
    err("IState render");   
}

float IState::playerX()
{
    return _player.getX();
}

float IState::playerY()
{
    return _player.getY();
}

SDL_Rect* IState::getCameraViewport()
{
    return _camera.getViewport(_player.getX(), _player.getY());
}
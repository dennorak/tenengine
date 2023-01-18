#include "state.hpp"

IState::IState(Window window, std::string mapPath):
    _window(window),
    _set(Tiled::Set(PACKPATH, _window.getRender(), TEXPATH)),
    _map(Tiled::Map(_set, mapPath, _window.getRender(), _window.width())),
    _camera(_map.scale(), _window.width(), _window.height(), _set.getSize()),
    _player(PLAYERTEX, _set.getSize() * scale(), _window, _map)
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

float IState::scale()
{
    return (float)_window.width()/(_map.width()*_set.getSize());
}
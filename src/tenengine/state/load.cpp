#include "state.hpp"

LoadState::LoadState(Window window): IState(window, LEVEL_MENU)
{

}

void LoadState::render()
{
    _map.render(_camera.getViewport(_player.getX(), _player.getY()), 1);
    _player.render(_map.width()/_map.scale());
}

void LoadState::tick(Keyboard& kb)
{
    std::vector<unsigned int> pressed = kb.getKeysPressed();

    float PSPEED = 0.001f * _map.scale();

    if (kb.isKeyPressed(SDLK_LSHIFT))
    {
        PSPEED *= 1.5f;
    }

    for (unsigned int key : pressed)
    {
        switch(key)
        {
            case SDLK_w:
                _player.move(0, -PSPEED, _camera.getAR());
                break;
            case SDLK_s:
                _player.move(0, PSPEED, _camera.getAR());
                break;
            case SDLK_a:
                _player.move(-PSPEED, 0, _camera.getAR());
                break;
            case SDLK_d:
                _player.move(PSPEED, 0, _camera.getAR());
                break;
        }
    }
}
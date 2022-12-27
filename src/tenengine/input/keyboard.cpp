#include "input.hpp"

void Keyboard::keyPress(unsigned int keyID)
{
    _keys[keyID] = true;
};

void Keyboard::keyRelease(unsigned int keyID)
{
    _keys[keyID] = false;
};

bool Keyboard::isKeyPressed(unsigned int keyID)
{
    auto it = _keys.find(keyID);
    if (it != _keys.end())
    {
        return it->second;
    } else {
        return false;
    }
};
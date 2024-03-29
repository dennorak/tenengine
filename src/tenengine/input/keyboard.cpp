#include "input.hpp"

void Keyboard::keyPress(unsigned int keyID) { _keys[keyID] = true; };
void Keyboard::keyRelease(unsigned int keyID) { _keys[keyID] = false; };

bool Keyboard::isKeyPressed(unsigned int keyID)
{
    // find the key in the unordered map
    // https://youtu.be/Epyih-LEbig?t=508
    auto it = _keys.find(keyID);
    if (it != _keys.end())
    {
        return it->second;
    } else {
        return false;
    }
};

std::vector<unsigned int> Keyboard::getKeysPressed()
{
    std::vector<unsigned int> pressed;

    for (auto key : _keys)
    {
        if (std::get<bool>(key) == true)
        {
            pressed.push_back(std::get<const unsigned int>(key));
        }
    }

    return pressed;
}
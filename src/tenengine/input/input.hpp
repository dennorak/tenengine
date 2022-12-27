#pragma once
#include <unordered_map>
#include <SDL2/SDL.h>

class Keyboard
{
public:
    void keyPress(unsigned int keyID);
    void keyRelease(unsigned int keyID);
    bool isKeyPressed(unsigned int keyID);
private:
    std::unordered_map<unsigned int, bool> _keys;
};
#pragma once
#include <unordered_map>
#include <vector>
#include <SDL2/SDL.h>
#include <iostream>

class Keyboard
{
public:
    void keyPress(unsigned int keyID);
    void keyRelease(unsigned int keyID);
    bool isKeyPressed(unsigned int keyID);
    std::vector<unsigned int> getKeysPressed();
private:
    std::unordered_map<unsigned int, bool> _keys;
};
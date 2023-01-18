#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

/*
    defs
*/

#define PLAYERTEX "assets/textures/proto.png"
#define FONTPATH "assets/fonts/sofiasans.ttf"

/*
    utils.cpp
*/

extern void err(std::string message);
extern void log(std::string message);
extern void dbg(std::string message);
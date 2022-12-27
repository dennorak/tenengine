#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

/*
    defs
*/
#define PACKPATH "assets/data/atlas.teset"
#define MAPPATH "assets/data/demo.temap"
#define TEXPATH "assets/textures/atlas.png"
#define PLAYERTEX "assets/textures/proto.png"

/*
    utils.cpp
*/

extern void err(std::string message);
extern void log(std::string message);
extern void dbg(std::string message);
#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

/*
    defs
*/
#define PACKPATH "textures/atlas.tsx"
#define MAPPATH "textures/demo.tmx"
#define TEXPATH "textures/atlas.png"
#define PLAYERTEX "textures/proto.png"

/*
    utils.cpp
*/

extern void err(std::string message);
extern void log(std::string message);
extern void dbg(std::string message);
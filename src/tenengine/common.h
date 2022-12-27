#pragma once

#include <iostream>
#include <string>

/*
    defs
*/
#define PACKPATH "textures/atlas.tsx"
#define MAPPATH "textures/demo.tmx"
#define TEXPATH "textures/atlas.png"

/*
    utils.cpp
*/

extern void err(std::string message);
extern void log(std::string message);
extern void dbg(std::string message);
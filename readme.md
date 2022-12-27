# Tenengine
*A new branch of the multiverse extends it's welcome*

## Build Prequisites

Compilers:
- g++ (reccomended)
- Any other c++ compiler*
> ** The Makefile will have to be edited according to changes in your compiler from g++

Libraries:
- SDL2
- SDL2_image
- SDL2_ttf
- OpenGL
- OpenGL Extension Wrangler (GLEW)
- pugixml

## Build Options
| Command | Result |
|---------|--------|
| `make run` | Builds the game and runs it |
| `make tenengine` | builds the game to `bin/tenengine` |
| `make clean` | clears everything from the `bin` and `build` directories |

If certain modules need to be recompiled, either
- check the makefile to see if a build target exists for your needs
- edit the makefile to accomodate your compilation needs

Most of the time, this shouldn't have to be done. The only cases this is needed for are really adding modules to the game, modifying only header files, and recompiling modules after changing a function type to another compatible one (e.g. float <-> int)
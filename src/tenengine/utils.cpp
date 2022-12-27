#include "common.h"


void err(std::string message)
{
    std::cout << "[ ERROR ]: " << message << std::endl;
    SDL_Quit();
    exit(1);
};

void log(std::string message)
{
    std::cout << "[  LOG  ]: " << message << std::endl;
}

void dbg(std::string message)
{
    std::cout << "[ DEBUG ]: " << message << std::endl;
}
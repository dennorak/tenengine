#include "graphics.hpp"

Debug::Debug(SDL_Renderer* renderer):
    _renderer(renderer)
{
    TTF_Init();
    _font = TTF_OpenFont(FONTPATH, 24);

    _rect.w = 300;
    _rect.h = 200;
}

void Debug::render(float fps, float x, float y)
{
    std::string dString = "FPS: " + std::to_string((int)fps) +
    "\nX: " + std::to_string(x) + "\nY: " + std::to_string(y);

    SDL_Surface* surface = TTF_RenderUTF8_Solid_Wrapped(
        _font, 
        dString.c_str(),
        {255, 255, 255, 0},
        200
    );
    SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, surface);

    SDL_RenderCopy(_renderer, texture, NULL, &_rect);
}
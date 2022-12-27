#include "tiled.hpp"


namespace Tiled
{
    Tile::Tile(int tx, int ty, int size, bool collidable)
    {
        // set uv coords
        _uv.x = size * tx;
        _uv.y = size * ty;
        _uv.w = size;
        _uv.h = size;
        // set world coords
        _wc.x = size;
        _wc.y = size;
        _wc.w = size;
        _wc.h = size;
        // set collision
        _doesCollide = collidable;
    };

    SDL_Rect* Tile::getUV()
    {
        return &_uv;
    }

    SDL_Rect Tile::getWC(int wx, int wy, float scale)
    {
        SDL_Rect rect = _wc;
        rect.w *= scale;
        rect.h *= scale;
        rect.x *= wx * scale;
        rect.y *= wy * scale;
        return rect;
    }
}
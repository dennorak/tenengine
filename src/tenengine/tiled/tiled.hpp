#pragma once

#include "../common.h"
#include <vector>
#include <string>
#include <pugixml.hpp>
#include <SDL2/SDL.h>
#include <cassert>
#include <sstream>

namespace Tiled
{
    class Tile
    {
    public:
        Tile(int tx, int ty, int size, bool collidable);

        SDL_Rect* getUV();
        SDL_Rect getWC(int wx, int wy, float scale);
    private:
        SDL_Rect _uv;
        SDL_Rect _wc;
        bool _doesCollide;
    };

    class Set
    {
    public:
        Set(std::string atlas_path, SDL_Renderer* renderer, std::string image_path);
        ~Set();

        void copyTile(int id, int x, int y, float scale);
        void render();
        int getSize();
    private:
        int _size;
        std::string _name;
        Tile *_tiles;
        SDL_Texture* _atlas;
        SDL_Renderer* _renderer;
    };

    class Map
    {
    public:
        Map(Set set, std::string path, SDL_Renderer* renderer, int w);

        void render(SDL_Rect *of, int layer, SDL_Rect *to);
        float getScale();
        int width();
        int height();
    private:
        int _w, _h, _layers, _spawnX, _spawnY;
        float _scale;
        SDL_Texture *_textures[1];
        SDL_Renderer* _renderer;
    };    
}
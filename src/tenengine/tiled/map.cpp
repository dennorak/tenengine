#include "tiled.hpp"
#include <SDL2/SDL_render.h>

namespace Tiled
{
    Map::Map(Set set, std::string path, SDL_Renderer* renderer, int w): _renderer(renderer)
    {
        // load the xml file
        pugi::xml_document atlas;
        pugi::xml_parse_result loadResult = atlas.load_file(path.c_str());
        if (loadResult.status != pugi::status_ok) err("Could not load tile map " + path);

        // get map metadata
        _w = atlas.child("map").attribute("width").as_int();
        _h = atlas.child("map").attribute("height").as_int();
        _layers = atlas.child("map").attribute("nextlayerid").as_int() - 1;
        _scale = atlas.child("map").child("properties")
            .find_child_by_attribute("property", "name", "scale")
            .attribute("value").as_float();
        _spawnX = atlas.child("map").child("properties")
            .find_child_by_attribute("property", "name", "spawn_x")
            .attribute("value").as_int();
        _spawnY = atlas.child("map").child("properties")
            .find_child_by_attribute("property", "name", "spawn_y")
            .attribute("value").as_int();

        // create the tile array
        // for more info see the creation of the _tiles array in set.cpp
        // https://stackoverflow.com/questions/47664127/create-a-multidimensional-array-dynamically-in-c
        _tiles = (int*) calloc(_w * _h * _layers, sizeof(int));
        assert(_tiles);
        // set the tile index to 0
        int tCount = 0;

        // bake the textures
        for (int i = 0; i < _layers; i++)
        {
            // get the layer layout
            std::stringstream layout(atlas.child("map")
                .find_child_by_attribute("layer", "id", std::to_string(i+1).c_str())
                .child_value("data"));
            
            // convert layer data to an array
            std::string line;
            // parse the csv data
            while (std::getline(layout, line, ','))
            {
                _tiles[tCount * (i + 1)] = stoi(line);
                tCount++;
            };
            
            // create the layer and set render target
            SDL_Texture* layer = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, _w * set.getSize(), _h * set.getSize());
            SDL_SetRenderTarget(_renderer, layer);
            int tile = 0;
            for (int y = 0; y < _h; y++)
            {
                for (int x = 0; x < _w; x++)
                {
                    set.copyTile(_tiles[tile * (i + 1)], x, y);
                    tile++;
                }
            }
            SDL_SetRenderTarget(_renderer, NULL);
            _textures[i] = layer;

            dbg("Map layers rendered");
        }
    };

    void Map::render(SDL_Rect* of, int layer, SDL_Rect* to)
    {
        if (layer-1 > _layers) err("Trying to render layer out of bounds: " + std::to_string(layer));
        SDL_RenderCopy(_renderer, _textures[layer-1], of, to);
    }

    int Map::getTileID(int layer, int tx, int ty)
    {
        // convert (x, y) to array position
        // for info see the creation for the _tiles array
        return _tiles[((_w * (ty - 1)) + (tx - 1))*layer];
    };

    Map::~Map()
    {
        // free the tile array
        free(_tiles);
        _tiles = NULL;
    };

    float Map::getScale()
    {
        return _scale;
    };

    int Map::width()
    {
        return _w;
    }

    int Map::height()
    {
        return _h;
    }

    int Map::spawnX()
    {
        return _spawnX;
    }

    int Map::spawnY()
    {
        return _spawnY;
    }
}
#include "tiled.hpp"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

namespace Tiled
{
    Set::Set(std::string atlas_path, SDL_Renderer* renderer, std::string image_path): _renderer(renderer)
    {
        // load the xml file
        pugi::xml_document atlas;
        pugi::xml_parse_result loadResult = atlas.load_file(atlas_path.c_str());
        if (loadResult.status != pugi::status_ok) err("Could not load tile atlas " + atlas_path);

        // get metadata about the pack
        int w = atlas.child("tileset").attribute("tilewidth").as_int();
        int h = atlas.child("tileset").attribute("tileheight").as_int();
        if (w != h) err("Pack does not contain square tiles.");
        _size = w;
        _name = atlas.child("tileset").attribute("name").value();
        int count = atlas.child("tileset").attribute("tilecount").as_int();
        int cols  = atlas.child("tileset").attribute("columns").as_int();

        // create the tile array
        _tiles = (Tile*) calloc(count, sizeof(Tile));
        assert(_tiles);
        // populate said array
        for (int i = 0; i < count; i++)
        {
            int x = i % cols;
            int y = (int) i / cols;
            bool collidable = atlas.child("tileset").find_child_by_attribute("tile", "id", std::to_string(i).c_str())
                .child("properties")
                .find_child_by_attribute("property", "name", "collidable")
                .attribute("value").as_bool();

            Tile tile(x, y, _size, collidable);

            _tiles[i] = tile;
            // dbg("Loaded tile " + std::to_string(i) + " of " + std::to_string(count));
        };

        // create the atlas texture
        _atlas = IMG_LoadTexture(_renderer, image_path.c_str());
        

        dbg("Loaded tiled pack " + _name);
    };

    Set::~Set()
    {
        // free the tile array
        free(_tiles);
        _tiles = NULL;
    };

    int Set::getSize()
    {
        return _size;
    }

    void Set::copyTile(int id, int x, int y, float scale)
    {
        SDL_Rect wc = _tiles[id].getWC(x, y, scale);
        SDL_RenderCopy(_renderer, _atlas, _tiles[id].getUV(), &wc);
    };

    void Set::render()
    {
        SDL_RenderCopy(_renderer, _atlas, NULL, NULL);
    }
}
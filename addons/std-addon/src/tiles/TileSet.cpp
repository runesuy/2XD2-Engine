//
// Created by rune-suy on 1/20/26.
//

#include "2XD2/std_addon/tiles/TileSet.h"


namespace e2XD::std_addon
{
    void TileSet::setTexture(const TileIdType id, const TextureType &texture)
    {
        _tileTextures[id] = &texture;
    }

    const sf::Texture& TileSet::getTexture(const TileIdType id) const
    {
        return *_tileTextures.at(id);
    }
} // std_addon
// e2XD

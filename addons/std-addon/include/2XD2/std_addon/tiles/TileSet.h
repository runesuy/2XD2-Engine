//
// Created by rune-suy on 1/20/26.
//

#ifndef FLATLAND_TILESET_H
#define FLATLAND_TILESET_H
#include <unordered_map>
#include <SFML/Graphics/Texture.hpp>

#include "internal/Tile.h"


namespace e2XD::std_addon
{
    /**
     * A set of tiles, each associated with a texture.
     */
    class TileSet
    {
    public:
        using TileIdType = internal::Tile::TileIdType;
        using TextureType = sf::Texture;

    private:
        std::unordered_map<TileIdType, const TextureType*> _tileTextures;

    public:
        virtual ~TileSet() = default;
        TileSet() = default;

        /**
         * Get the texture associated with a specific tile ID.
         * @param id The ID of the tile.
         * @return The texture associated with the tile ID.
         */
        [[nodiscard]] virtual const TextureType& getTexture(TileIdType id) const;

        /**
         * Set the texture for a specific tile ID.
         * @param id The ID of the tile.
         * @param texture The texture to associate with the tile ID.
         */
        virtual void setTexture(TileIdType id, const TextureType& texture);
    };
} // std_addon
// e2XD

#endif //FLATLAND_TILESET_H

#ifndef FLATLAND_TILEMAP_H
#define FLATLAND_TILEMAP_H

#include <unordered_map>
#include <2XD2/framework/nodes/Node2D.h>
#include <SFML/Graphics/Sprite.hpp>

#include "TileSet.h"
#include "internal/TileChunk.h"
#include "internal/TileMapRenderable.h"

namespace e2XD::std_addon
{

    class TileMap : public framework::Node2D
    {
    public:
        using TileIdType = unsigned short;

        using TileMapSizeType = int;

    private:
        friend class internal::TileMapRenderable;

        /**
         * Type used as key for chunk coordinates.
         */
        using ChunkCoordType = core::Vec2<TileMapSizeType>;

        /**
         * Struct used for hashing chunk coordinates.
         */
        struct Hash_
        {
            Hash_() = default;
            size_t operator()(const ChunkCoordType& coords) const noexcept;
        };

        /**
         * Map of chunks, keyed by their hashed coordinates.
         */
        using ChunkMap = std::unordered_map<ChunkCoordType, internal::TileChunk, Hash_>;

        /**
         * Contains all chunks in the tile map.
         */
        ChunkMap _chunks;

        TileSet _tileSet;

        /**
         * Size of each chunk in tiles.
         * Make this a power of two for optimal performance.
         */
        const internal::TileChunk::ChunkSizeType _chunkSize = 16; // in tiles

        /**
         * Type used for tile size in pixels.
         */
        using TileSizeType = int;
        TileSizeType _tileSize = 32; // in pixels

        /**
         * Calculates the chunk coordinates and relative tile coordinates within that chunk for given tile coordinates.
         * Tile coördinates can be negative and are grid positions, not world positions.
         * @param tileX
         * @param tileY
         * @return (ChunkCoördinates, RelativeTileCoördinates)
         */
        [[nodiscard]] std::pair<core::Vec2<int>, core::Vec2<int>>
        _calculateChunkCoordinates(int tileX, int tileY) const;

        sf::Sprite _sprite; // Reusable sprite for drawing tiles

        internal::TileMapRenderable _renderable;

    public:
        explicit TileMap(const TileSet& tileSet);
        ~TileMap() override = default;

    protected:
        /**
         * Draws the visible chunks of the tile map.
         */
        void onDraw() override;

    public:
        void setTileSize(TileSizeType size);

        [[nodiscard]] TileSizeType getTileSize() const;

        [[nodiscard]] const TileIdType& getTile(int x, int y) const;

        void setTile(int x, int y, TileIdType tileId);
    };
}

#endif //FLATLAND_TILEMAP_H

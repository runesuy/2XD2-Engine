#ifndef FLATLAND_TILEMAP_H
#define FLATLAND_TILEMAP_H

#include <unordered_map>
#include <2XD2/framework/nodes/Node2D.h>
#include <SFML/Graphics/Sprite.hpp>

#include "TileSet.h"
#include "2XD2/framework/drawing/Drawable.h"
#include "internal/TileChunk.h"
#include "internal/TileMapRenderable.h"

namespace e2XD::std_addon
{
    /**
     * A 2D tile map node.
     */
    class TileMap : public framework::Node2D, public framework::Drawable
    {
    public:
        using TileMapSizeType = int;
        using TileIdT = internal::Tile::TileIdType;
        using ChunkCoordT = core::Vec2<TileMapSizeType>;

    private:
        friend class internal::TileMapRenderable;

        /**
         * Struct used for hashing chunk coordinates.
         */
        struct Hash_
        {
            Hash_() = default;
            size_t operator()(const ChunkCoordT& coords) const noexcept;
        };

        /**
         * Map of chunks, keyed by their hashed coordinates.
         */
        using ChunkMap = std::unordered_map<ChunkCoordT, internal::TileChunk, Hash_>;

        using TileSizeT = int;


        const internal::TileChunk::ChunkSizeType _chunkSize = 16; // in tiles

        TileSizeT _tileSize = 32; // in pixels
        internal::TileMapRenderable _renderable;

        ChunkMap _chunks;
        TileSet _tileSet;

        // ------------------ Methods ------------------
        /**
         * Calculates the chunk coordinates and relative tile coordinates within that chunk for given tile coordinates.
         * Tile coördinates can be negative and are grid positions, not world positions.
         * @param tileX
         * @param tileY
         * @return (ChunkCoördinates, RelativeTileCoördinates)
         */
        [[nodiscard]] std::pair<core::Vec2<int>, core::Vec2<int>>
        _calculateChunkCoordinates(int tileX, int tileY) const;

    protected:
        /**
         * Draws the visible chunks of the tile map.
         */
        void onDraw(const framework::DrawTarget& target) override;

    public:
        explicit TileMap(const TileSet& tileSet);
        ~TileMap() override = default;

        /**
         * Set the size of each tile in pixels.
         * @param size
         */
        void setTileSize(TileSizeT size);

        /**
         * Get the size of each tile in pixels.
         * @return The size of each tile in pixels.
         */
        [[nodiscard]] TileSizeT getTileSize() const;

        /**
         * Get the tile ID at the specified tile coordinates.
         * Tile coördinates can be negative and are grid positions, not world positions.
         * @param x Tile X coordinate.
         * @param y Tile Y coordinate.
         * @return The tile ID at the specified coordinates.
         */
        [[nodiscard]] const TileIdT& getTile(int x, int y) const;

        /**
         * Set the tile ID at the specified tile coordinates.
         * Tile coördinates can be negative and are grid positions, not world positions.
         * @param x Tile X coordinate.
         * @param y Tile Y coordinate.
         * @param tileId The tile ID to set.
         */
        void setTile(int x, int y, TileIdT tileId);
    };
}

#endif //FLATLAND_TILEMAP_H

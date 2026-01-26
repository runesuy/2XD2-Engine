#include "2XD2/std_addon/tiles/TileMap.h"

#include "2XD2/framework/drawing/Renderer.h"
#include "2XD2/framework/scene/Scene.h"
#include "../../include/2XD2/std_addon/nodes/Sprite2D.h"

using namespace e2XD::framework;

namespace e2XD::std_addon
{
    //----------------- TileMap Implementation -----------------
    // PRIVATE MEMBERS
    std::pair<core::Vec2<int>, core::Vec2<int>> TileMap::_calculateChunkCoordinates(int tileX, int tileY) const
    {
        int chunkX = tileX / _chunkSize;
        int chunkY = tileY / _chunkSize;

        if (tileX < 0 && tileX % _chunkSize != 0)
        {
            --chunkX;
        }
        if (tileY < 0 && tileY % _chunkSize != 0)
        {
            --chunkY;
        }

        int relativeX = tileX - (chunkX * _chunkSize);
        int relativeY = tileY - (chunkY * _chunkSize);

        return {{chunkX, chunkY}, {relativeX, relativeY}};
    }

    // PROTECTED MEMBERS
    void TileMap::onDraw(const DrawTarget& target)
    {
        const auto& position = getGlobalPosition();
        Renderer::submit({
            renderLayer,
            &_renderable,
            {position.x, position.y},
            zIndex
        });
    }

    // PUBLIC MEMBERS
    TileMap::TileMap(const TileSet& tileSet) : _tileSet(tileSet), _renderable(*this)
    {
        zIndex = -100; // Default z-index for tile maps
    }

    void TileMap::setTileSize(const TileSizeT size)
    {
        _tileSize = size;
    }

    TileMap::TileSizeT TileMap::getTileSize() const
    {
        return _tileSize;
    }

    const TileMap::TileIdT& TileMap::getTile(const int x, const int y) const
    {
        const auto [chunkCoords, relativeCoords] = _calculateChunkCoordinates(x, y);
        const auto& chunkIt = _chunks.find(chunkCoords);
        return _chunks.at(chunkCoords).getTile(relativeCoords.x, relativeCoords.y).id;
    }

    void TileMap::setTile(const int x, const int y, const TileIdT tileId)
    {
        const auto [chunkCoords, relativeCoords] = _calculateChunkCoordinates(x, y);
        auto& chunk = _chunks[chunkCoords];
        chunk.setTile(relativeCoords.x, relativeCoords.y, internal::Tile{tileId, {}});
    }


    //----------------- ChunkMap Hash Implementation -----------------

    size_t TileMap::Hash_::operator()(const ChunkCoordT& coords) const noexcept
    {
        return std::hash<TileMapSizeType>()(coords.x) ^ (std::hash<TileMapSizeType>()(coords.y) << 1); // Combine hashes
    }


    //----------------- Chunk Implementation -----------------
}

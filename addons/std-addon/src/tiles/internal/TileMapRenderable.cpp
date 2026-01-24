//
// Created by rune-suy on 1/20/26.
//

#include "2XD2/std_addon/tiles/internal/TileMapRenderable.h"

#include "2XD2/framework/scene/Scene.h"
#include "2XD2/std_addon/tiles/TileMap.h"
#include "2XD2/std_addon/tiles/internal/TileChunk.h"


namespace e2XD::std_addon::internal
{
    TileMapRenderable::TileMapRenderable(TileMap& tileMap) : _tileMap(tileMap)
    {
    }

    void TileMapRenderable::draw(renderer::IRenderTarget& renderTarget) const
    {
        static sf::Sprite sprite;
        const auto* scene = _tileMap.getScene();
        if (!scene) return;

        const auto* camera = scene->getActiveCamera();
        if (!camera) return;

        // calculate visible chunks
        const int chunksX = static_cast<int>(camera->getSize().x / (_tileMap._tileSize * _tileMap._chunkSize)) + 2;
        const int chunksY = static_cast<int>(camera->getSize().y / (_tileMap._tileSize * _tileMap._chunkSize)) + 2;
        const int cameraTileX = static_cast<int>(camera->getGlobalPosition().x) / _tileMap._tileSize;
        const int cameraTileY = static_cast<int>(camera->getGlobalPosition().y) / _tileMap._tileSize;
        const auto [centerChunkCoords, _] = _tileMap._calculateChunkCoordinates(cameraTileX, cameraTileY);
        const int startChunkX = centerChunkCoords.x - static_cast<int>(chunksX) / 2;
        const int startChunkY = centerChunkCoords.y - static_cast<int>(chunksY) / 2;

        // draw visible chunks
        for (int chunkX = 0; chunkX < chunksX; ++chunkX)
        {
            for (int chunkY = 0; chunkY < chunksY; ++chunkY)
            {
                if (_tileMap._chunks.contains({static_cast<int>(chunkX + startChunkX), chunkY + startChunkY}))
                {
                    const auto& chunk = _tileMap._chunks.at({chunkX + startChunkX, chunkY + startChunkY});
                    for (TileChunk::ChunkSizeType tileX = 0; tileX < _tileMap._chunkSize; ++tileX)
                    {
                        for (TileChunk::ChunkSizeType tileY = 0; tileY < _tileMap._chunkSize; ++tileY)
                        {
                            const auto& [id, metaData] = chunk.getTile(tileX, tileY);
                            if (id != 0) // assuming 0 is empty tile
                            {
                                sprite.setTexture(_tileMap._tileSet.getTexture(id));
                                const auto posX = _tileMap._tileSize * (tileX + (startChunkX + chunkX) * _tileMap._chunkSize);
                                const auto posY = _tileMap._tileSize * (tileY + (startChunkY + chunkY) * _tileMap._chunkSize);
                                sprite.setPosition(posX, posY);
                                // Here you would set the texture rect based on the tile ID and tileset
                                renderTarget.draw(sprite);
                            }
                        }
                    }
                }
            }
        }
    }
} // internal
// std_addon
// e2XD

//
// Created by rune-suy on 1/19/26.
//

#include "2XD2/std_addon/tiles/internal/TileChunk.h"


namespace e2XD::std_addon::internal
{
    constexpr unsigned int TileChunk::_positiveProject(const int key)
    {
        if (key > 0) return 2*key-1;
        return -key*2;
    }

    const Tile& TileChunk::getTile(const ChunkSizeType x, const ChunkSizeType y) const
    {
        return tiles[_positiveProject(x)+_positiveProject(y)*SIZE];
    }

    void TileChunk::setTile(const ChunkSizeType x, const ChunkSizeType y, const Tile& tile)
    {
        tiles[_positiveProject(x)+_positiveProject(y)*SIZE] = tile;
    }

    bool TileChunk::operator==(const TileChunk& other) const
    {
        for (unsigned int i = 0; i < SIZE * SIZE; ++i)
        {
            if (tiles[i].id != other.tiles[i].id || tiles[i].metaData != other.tiles[i].metaData)
            {
                return false;
            }
        }
        return true;
    }
} // std_addon
// e2XD

//
// Created by rune-suy on 1/19/26.
//

#ifndef FLATLAND_CHUNK_H
#define FLATLAND_CHUNK_H
#include "Tile.h"

namespace e2XD::std_addon::internal
{
    class TileChunk
    {
        /**
         * Maps a signed integer key to a positive unsigned integer.
         * Positive keys are mapped to odd numbers, negative keys to even numbers.
         * For example:
         *  0 -> 0
         *  1 -> 1
         * -1 -> 2
         *  2 -> 3
         * -2 -> 4
         * @param key
         * @return
         */
        static constexpr unsigned int _positiveProject(int key);

    public:
        using ChunkSizeType = unsigned char;
        static constexpr ChunkSizeType SIZE = 32;
        Tile tiles[SIZE * SIZE];

        TileChunk() = default;

        bool operator==(const TileChunk&) const;

        void setTile(ChunkSizeType x, ChunkSizeType y, const Tile& tile);

        [[nodiscard]] const Tile& getTile(ChunkSizeType x, ChunkSizeType y) const;
    };
} // std_addon
// e2XD

#endif //FLATLAND_CHUNK_H

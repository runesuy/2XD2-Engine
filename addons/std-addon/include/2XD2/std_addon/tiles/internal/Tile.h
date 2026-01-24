//
// Created by rune-suy on 1/19/26.
//

#ifndef FLATLAND_TILE_H
#define FLATLAND_TILE_H

namespace e2XD::std_addon::internal
    {
        struct Tile
        {
            using TileIdType = unsigned short;
            using TileMetaDataType = unsigned char;
            TileIdType id;
            TileMetaDataType metaData;
        };
    } // std_addon
// e2XD

#endif //FLATLAND_TILE_H
//
// Created by rune-suy on 1/20/26.
//

#ifndef FLATLAND_TILEMAPRENDERABLE_H
#define FLATLAND_TILEMAPRENDERABLE_H
#include "2XD2/renderer/IRenderable.h"

namespace e2XD::std_addon
{
    class TileMap;
} // renderer

namespace e2XD::std_addon::internal
{

    class TileMapRenderable : public renderer::IRenderable
    {
        TileMap& _tileMap;
    public:
        explicit TileMapRenderable(TileMap& tileMap);
        void draw(renderer::IRenderTarget& renderTarget) const override;
    };
} // internal
// std_addon
// e2XD

#endif //FLATLAND_TILEMAPRENDERABLE_H

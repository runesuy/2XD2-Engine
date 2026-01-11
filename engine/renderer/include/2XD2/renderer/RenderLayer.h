//
// Created by rune-suy on 12/19/25.
//

#ifndef FLATLAND_RENDERLAYER_H
#define FLATLAND_RENDERLAYER_H
#include <vector>

/**
 * Basic render layers for renderable objects.
 */
enum class RenderLayer
{
    BACKGROUND,
    WORLD,
    UI,
    OVERLAY
};

const inline std::vector RenderOrder = {
    RenderLayer::BACKGROUND,
    RenderLayer::WORLD,
    RenderLayer::UI,
    RenderLayer::OVERLAY
};

#endif //FLATLAND_RENDERLAYER_H

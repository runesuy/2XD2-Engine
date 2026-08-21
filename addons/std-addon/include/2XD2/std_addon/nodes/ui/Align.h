//
// Created by rune-suy on 6/30/26.
//

#ifndef FLATLAND_ALIGN_H
#define FLATLAND_ALIGN_H
#include <tuple>

namespace e2XD::std_addon
{
    enum class HorizontalAlign
    {
        LEFT,
        CENTER,
        RIGHT
    };
    
    enum class VerticalAlign
    {
        TOP,
        CENTER,
        BOTTOM
    };

    using AlignVec = std::tuple<HorizontalAlign, VerticalAlign>;
}

#endif //FLATLAND_ALIGN_H
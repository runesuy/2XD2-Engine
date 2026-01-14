// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/13/26.
//

#ifndef INC_2XD2_ENGINE_VIEWMODE_H
#define INC_2XD2_ENGINE_VIEWMODE_H

namespace e2XD::renderer
{
    enum class ViewMode
    {
        StretchToFill,
        Letterbox,
        Expand,
        Fill
    };
} // renderer

#endif //INC_2XD2_ENGINE_VIEWMODE_H
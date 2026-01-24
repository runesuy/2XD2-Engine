// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/24/26.
//

#ifndef e2XD_REMOVE_DEBUG
#include "2XD2/framework/debug/DefaultDebugConfig.h"


namespace e2XD::framework
{
    const renderer::IRenderable* DefaultDebugConfig::getOriginMarker() const
    {
        return originMarker.get();
    }
} // framework

#endif

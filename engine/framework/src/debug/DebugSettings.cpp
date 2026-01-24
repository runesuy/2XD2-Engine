// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/24/26.
//

#ifndef e2XD_REMOVE_DEBUG
#include "2XD2/framework/debug/DebugSettings.h"


namespace e2XD::framework
{
    const IDebugConfig* DebugSettings::_debugConfig = nullptr;
    bool DebugSettings::showNodeOrigin = false;
    bool DebugSettings::showCollisionBoxes = false;

    void DebugSettings::initialize(const IDebugConfig* debugConfig)
    {
        _debugConfig = debugConfig;
    }

    const renderer::IRenderable* DebugSettings::getOriginMarker()
    {
        if (_debugConfig)
        {

            return _debugConfig->getOriginMarker();
        }
        return nullptr;
    }
} // framework
#endif

// e2XD

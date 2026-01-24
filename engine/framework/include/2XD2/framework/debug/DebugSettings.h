// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/24/26.
//

#ifndef INC_2XD2_ENGINE_DEBUGSETTINGS_H
#define INC_2XD2_ENGINE_DEBUGSETTINGS_H

#ifndef e2XD_REMOVE_DEBUG
#include "IDebugConfig.h"
#include "2XD2/renderer/DefaultRenderer.h"

namespace e2XD::framework
{
    /**
     * Settings for debugging features.
     * Can be toggled on/off to show various debug information.
     *
     * define e2XD_REMOVE_DEBUG to remove all debug features.
     */
    class DebugSettings
    {
        static const IDebugConfig* _debugConfig;

    public:
        static bool showNodeOrigin;
        static bool showCollisionBoxes;

        static void initialize(const IDebugConfig* debugConfig);

        static const renderer::IRenderable* getOriginMarker();
    };
} // framework
// e2XD

#endif // e2XD_REMOVE_DEBUG
#endif //INC_2XD2_ENGINE_DEBUGSETTINGS_H

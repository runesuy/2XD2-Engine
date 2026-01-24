// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/24/26.
//

#ifndef INC_2XD2_ENGINE_IDEBUGCONFIG_H
#define INC_2XD2_ENGINE_IDEBUGCONFIG_H
#include "2XD2/renderer/DefaultRenderer.h"

#ifndef e2XD_REMOVE_DEBUG

namespace e2XD::framework
{
    class IDebugConfig
    {
    public:
        virtual ~IDebugConfig() = default;

        [[nodiscard]] virtual const renderer::IRenderable* getOriginMarker() const = 0;
    };
} // framework
// e2XD

#endif
#endif //INC_2XD2_ENGINE_IDEBUGCONFIG_H

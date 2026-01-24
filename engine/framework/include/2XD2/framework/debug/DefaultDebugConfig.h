// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/24/26.
//

#ifndef INC_2XD2_ENGINE_DEFAULTDEBUGCONFIG_H
#define INC_2XD2_ENGINE_DEFAULTDEBUGCONFIG_H
#ifndef e2XD_REMOVE_DEBUG

#include <memory>

#include "IDebugConfig.h"
#include "default/DefaultOriginMarker.h"


namespace e2XD::framework
{
    class DefaultDebugConfig : public IDebugConfig
    {
        const std::unique_ptr<renderer::IRenderable> originMarker =
            std::make_unique<DefaultOriginMarker>();

    public:
        DefaultDebugConfig() = default;

        [[nodiscard]] const renderer::IRenderable* getOriginMarker() const override;
    };
} // framework
// e2XD
#endif

#endif //INC_2XD2_ENGINE_DEFAULTDEBUGCONFIG_H

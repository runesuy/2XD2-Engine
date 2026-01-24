// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/20/25.
//

#ifndef INC_2XD2_ENGINE_IGAMECONFIG_H
#define INC_2XD2_ENGINE_IGAMECONFIG_H
#include "../collisions/ICollisionHandler.h"
#include "../input/IInputHandler.h"
#include "../resource_manager/IAnimationManager.h"
#include "../resource_manager/ITextureManager.h"
#include "2XD2/framework/resource_manager/IConfigManager.h"
#include "2XD2/framework/resource_manager/IFontManager.h"
#include "2XD2/renderer/IRenderer.h"

#ifndef e2XD_REMOVE_DEBUG
#include "2XD2/framework/debug/IDebugConfig.h"
#endif

namespace e2XD::framework
{
    /**
     * Game configuration interface to provide various managers to the framework's Game implementation.
     */
    class IGameConfig
    {
    public:
        virtual ~IGameConfig() = default;

        [[nodiscard]] virtual IInputHandler* getInputHandler() const = 0;

        [[nodiscard]] virtual IAnimationManager* getAnimationManager() const = 0;

        [[nodiscard]] virtual ITextureManager* getTextureManager() const = 0;

        [[nodiscard]] virtual ICollisionHandler* getCollisionHandler() const = 0;

        [[nodiscard]] virtual renderer::IRenderer* getRenderer() const = 0;

        [[nodiscard]] virtual IFontManager* getFontManager() const = 0;

        [[nodiscard]] virtual IConfigManager* getConfigManager() const = 0;

#ifndef e2XD_REMOVE_DEBUG
        [[nodiscard]] virtual const IDebugConfig* getDebugConfig() const = 0;
#endif
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_IGAMECONFIG_H

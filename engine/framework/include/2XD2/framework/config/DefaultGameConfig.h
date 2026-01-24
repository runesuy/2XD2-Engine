// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/20/25.
//

#ifndef INC_2XD2_ENGINE_DEFAULTGAMECONFIG_H
#define INC_2XD2_ENGINE_DEFAULTGAMECONFIG_H
#include <memory>

#include "IGameConfig.h"
#include "../collisions/DefaultCollisionHandler.h"
#include "../input/SFMLInputHandler.h"
#include "../resource_manager/SFMLAnimationManager.h"
#include "../resource_manager/SFMLTextureManager.h"
#include "2XD2/framework/resource_manager/DefaultConfigManager.h"
#include "2XD2/framework/resource_manager/DefaultFontManager.h"
#include "2XD2/renderer/DefaultRenderer.h"

#ifndef e2XD_REMOVE_DEBUG
#include "2XD2/framework/debug/DefaultDebugConfig.h"
#endif

namespace e2XD::framework
{
    /**
     * The default game configuration used by the framework's default game implementation.
     */
    class DefaultGameConfig : public IGameConfig
    {
        std::unique_ptr<IInputHandler> inputHandler = std::make_unique<internal::SFMLInputHandler>();
        std::unique_ptr<ITextureManager> textureManager = std::make_unique<SFMLTextureManager>();
        std::unique_ptr<IAnimationManager> animationManager = std::make_unique<SFMLAnimationManager>();
        std::unique_ptr<ICollisionHandler> collisionHandler = std::make_unique<DefaultCollisionHandler>();
        std::unique_ptr<renderer::IRenderer> renderer = std::make_unique<renderer::DefaultRenderer>();
        std::unique_ptr<IFontManager> fontManager = std::make_unique<DefaultFontManager>();
        std::unique_ptr<IConfigManager> configManager = std::make_unique<DefaultConfigManager>();

#ifndef e2XD_REMOVE_DEBUG
        std::unique_ptr<IDebugConfig> debugConfig = std::make_unique<DefaultDebugConfig>();
#endif

    public:
        [[nodiscard]] IInputHandler* getInputHandler() const override;

        [[nodiscard]] IAnimationManager* getAnimationManager() const override;

        [[nodiscard]] ITextureManager* getTextureManager() const override;

        [[nodiscard]] ICollisionHandler* getCollisionHandler() const override;

        [[nodiscard]] renderer::IRenderer* getRenderer() const override;

        [[nodiscard]] IFontManager* getFontManager() const override;

        [[nodiscard]] IConfigManager* getConfigManager() const override;

#ifndef e2XD_REMOVE_DEBUG
        [[nodiscard]] const IDebugConfig* getDebugConfig() const override;
#endif
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_DEFAULTGAMECONFIG_H

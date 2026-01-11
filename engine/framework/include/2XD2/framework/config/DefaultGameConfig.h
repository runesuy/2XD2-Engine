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
#include "2XD2/renderer/DefaultRenderer.h"


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

    public:
        [[nodiscard]] IInputHandler* getInputHandler() const override;

        [[nodiscard]] IAnimationManager* getAnimationManager() const override;

        [[nodiscard]] ITextureManager* getTextureManager() const override;

        [[nodiscard]] ICollisionHandler* getCollisionHandler() const override;

        [[nodiscard]] renderer::IRenderer* getRenderer() const override;
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_DEFAULTGAMECONFIG_H

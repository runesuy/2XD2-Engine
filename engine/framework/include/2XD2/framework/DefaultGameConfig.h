//
// Created by rune-suy on 12/20/25.
//

#ifndef INC_2XD2_ENGINE_DEFAULTGAMECONFIG_H
#define INC_2XD2_ENGINE_DEFAULTGAMECONFIG_H
#include <memory>

#include "IGameConfig.h"
#include "input/SFMLInputHandler.h"
#include "resource_manager/SFMLAnimationManager.h"
#include "resource_manager/SFMLTextureManager.h"


namespace e2XD::framework
    {
        /**
         * The default game configuration used by the framework's default game implementation.
         */
        class DefaultGameConfig :public IGameConfig
        {
            std::unique_ptr<IInputHandler> inputHandler = std::make_unique<internal::SFMLInputHandler>();
            std::unique_ptr<ITextureManager> textureManager = std::make_unique<SFMLTextureManager>();
            std::unique_ptr<IAnimationManager> animationManager = std::make_unique<SFMLAnimationManager>();
        public:
            [[nodiscard]] IInputHandler* getInputHandler() const override;

            [[nodiscard]] IAnimationManager* getAnimationManager() const override;

            [[nodiscard]] ITextureManager* getTextureManager() const override;
        };
    } // framework
// e2XD

#endif //INC_2XD2_ENGINE_DEFAULTGAMECONFIG_H
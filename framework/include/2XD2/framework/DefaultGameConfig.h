//
// Created by rune-suy on 12/20/25.
//

#ifndef INC_2XD2_ENGINE_DEFAULTGAMECONFIG_H
#define INC_2XD2_ENGINE_DEFAULTGAMECONFIG_H
#include <memory>

#include "IGameConfig.h"


namespace e2XD::framework
    {
        class DefaultGameConfig :public IGameConfig
        {
            std::unique_ptr<IInputHandler> inputHandler;
            std::unique_ptr<ITextureManager> textureManager;
            std::unique_ptr<IAnimationManager> animationManager;
        public:
            [[nodiscard]] IInputHandler* getInputHandler() const override;

            [[nodiscard]] IAnimationManager* getAnimationManager() const override;

            [[nodiscard]] ITextureManager* getTextureManager() const override;
        };
    } // framework
// e2XD

#endif //INC_2XD2_ENGINE_DEFAULTGAMECONFIG_H
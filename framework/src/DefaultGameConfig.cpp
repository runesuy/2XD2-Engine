//
// Created by rune-suy on 12/20/25.
//

#include "../include/2XD2/framework/DefaultGameConfig.h"


    namespace e2XD::framework
    {
        IInputHandler* DefaultGameConfig::getInputHandler() const
        {
            return inputHandler.get();
        }

        IAnimationManager* DefaultGameConfig::getAnimationManager() const
        {
            return animationManager.get();
        }

        ITextureManager* DefaultGameConfig::getTextureManager() const
        {
            return textureManager.get();
        }


    } // framework
// e2XD
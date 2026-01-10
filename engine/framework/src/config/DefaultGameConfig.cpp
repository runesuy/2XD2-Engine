//
// Created by rune-suy on 12/20/25.
//

#include "../../include/2XD2/framework/config/DefaultGameConfig.h"


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

    ICollisionHandler* DefaultGameConfig::getCollisionHandler() const
    {
        return collisionHandler.get();
    }
} // framework
// e2XD

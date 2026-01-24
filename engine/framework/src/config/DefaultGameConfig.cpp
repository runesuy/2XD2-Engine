// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/20/25.
//

#include "2XD2/framework/config/DefaultGameConfig.h"


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

    renderer::IRenderer* DefaultGameConfig::getRenderer() const
    {
        return renderer.get();
    }

    IFontManager* DefaultGameConfig::getFontManager() const
    {
        return fontManager.get();
    }

    IConfigManager* DefaultGameConfig::getConfigManager() const
    {
        return configManager.get();
    }

#ifndef e2XD_REMOVE_DEBUG
    const IDebugConfig* DefaultGameConfig::getDebugConfig() const
    {
        return debugConfig.get();
    }
#endif
} // framework
// e2XD

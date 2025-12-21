//
// Created by rune-suy on 12/21/25.
//

#include "2XD2/framework/resource_manager/Animations.h"


namespace e2XD::framework
{
    const AnimationMap& Resources::Animations::getAnimationMap(const std::string& name)
    {
        return _animationManager->getAnimationMap(name);
    }

    bool Resources::Animations::loadJsonAnimationConfigIfNotLoaded(const std::string& jsonFilePath)
    {
        return _animationManager->loadJsonAnimationConfigIfNotLoaded(jsonFilePath);
    }

    void Resources::Animations::loadJsonAnimationConfig(const std::string& jsonFilePath)
    {
        _animationManager->loadJsonAnimationConfig(jsonFilePath);
    }

    bool Resources::Animations::isJsonAnimationLoaded(const std::string& jsonFilePath)
    {
        return _animationManager->isJsonAnimationLoaded(jsonFilePath);
    }

    void Resources::Animations::initialize(IAnimationManager* animationManager)
    {
        _animationManager = animationManager;
    }
} // framework
// e2XD

//
// Created by rune-suy on 12/18/25.
//

#include "2XD2/framework/resource_manager/SFMLAnimationManager.h"

#include <fstream>
#include <stdexcept>

#include "json.hpp"
#include "../../../core/include/2XD2/core/exceptions/FileLoadingFailedException.h"
#include "2XD2/framework/resource_manager/SFMLTextureManager.h"


namespace e2XD::framework
{
    SFMLAnimationManager* SFMLAnimationManager::getInstance()
    {
        if (!_instance) _instance = new SFMLAnimationManager();
        return _instance;
    }

    const AnimationMap& SFMLAnimationManager::getAnimationMap(const std::string& name) const
    {
        if (loadedAnimationMaps.contains(name))  return loadedAnimationMaps.at(name);
        throw std::invalid_argument("SFMLAnimationManager::getAnimationMap: Animation map does not exist");
    }

    void SFMLAnimationManager::loadJsonAnimationConfig(const std::string& jsonFilePath)
    {
        std::ifstream file(jsonFilePath);
        if (!file.is_open()) throw FileLoadingFailedException(jsonFilePath, "void SFMLAnimationManager::loadJsonAnimationConfig(const std::string& jsonFilePath)");
        nlohmann::json json;
        file >> json;
        file.close();

        std::string mapName = json.at("animation-map-name");
        const auto& animationsList = json.at("animations");
        for (const auto& animation : animationsList)
        {
            // read json data
            const std::string& name = animation.at("name");
            const bool& repeat = animation.at("repeat");
            const float& frame_duration = animation.at("frame-duration");
            const auto& framesList = animation.at("frames");
            std::vector<const sf::Texture*> frameTextures;
            auto* textureManager = SFMLTextureManager::getInstance();
            for (const auto& frame : framesList)
            {
                const sf::Texture& texture = textureManager->getTexture(frame);
                frameTextures.push_back(&texture);
            }

            Animation newAnimation={frameTextures, frame_duration, repeat};
            loadedAnimationMaps[mapName][name] = newAnimation;

        }
    }


    bool SFMLAnimationManager::isJsonAnimationLoaded(const std::string& jsonFilePath) const
    {
        return loadedFiles.contains(jsonFilePath);
    }

    bool SFMLAnimationManager::loadJsonAnimationConfigIfNotLoaded(const std::string& jsonFilePath)
    {
        if (!isJsonAnimationLoaded(jsonFilePath))
        {
            loadJsonAnimationConfig(jsonFilePath);
            return true;
        }
        return false;
    }


} // framework
// e2XD

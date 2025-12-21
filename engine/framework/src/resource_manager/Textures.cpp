//
// Created by rune-suy on 12/21/25.
//

#include "../../include/2XD2/framework/resource_manager/Textures.h"


namespace e2XD::framework
{
    void Resources::Textures::initialize(ITextureManager* textureManager)
    {
        _textureManager = textureManager;
    }


    const sf::Texture& Resources::Textures::getTexture(const std::string& name)
    {
        return _textureManager->getTexture(name);
    }

    bool Resources::Textures::loadJsonTextureConfigIfNotLoaded(const std::string& jsonFilePath)
    {
        return _textureManager->loadJsonTextureConfigIfNotLoaded(jsonFilePath);
    }

    void Resources::Textures::loadJsonTextureConfig(const std::string& jsonFilePath)
    {
        _textureManager->loadJsonTextureConfig(jsonFilePath);
    }

    bool Resources::Textures::isJsonTextureLoaded(const std::string& jsonFilePath)
    {
        return _textureManager->isJsonTextureLoaded(jsonFilePath);
    }


} // framework
// e2XD

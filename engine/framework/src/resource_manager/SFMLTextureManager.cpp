//
// Created by rune-suy on 12/15/25.
//

#include "../include/2XD2/framework/resource_manager/SFMLTextureManager.h"
#include "json.hpp"
#include "fstream"

#include <stdexcept>

#include "../../../core/include/2XD2/core/exceptions/FileLoadingFailedException.h"

namespace e2XD::framework
{
    void SFMLTextureManager::loadJsonTextureConfig(const std::string& jsonFilePath)
    {
        nlohmann::json json;

        std::ifstream file(jsonFilePath);
        if (!file.is_open()) throw e2XD::framework::FileLoadingFailedException(
            jsonFilePath, "void SFMLTextureParser::loadJsonTextureConfig(const std::string& jsonFilePath)");
        file >> json;
        file.close();

        for (const auto fileList = json.at("files"); const auto& fileJ : fileList)
        {
            const auto& fileName = fileJ.at("filename");

            // open target texture file
            sf::Image image;

            if (bool successLoading = image.loadFromFile(fileName); !successLoading) throw FileLoadingFailedException(
                fileName, "void SFMLTextureParser::loadJsonTextureConfig(const std::string& jsonFilePath)");

            for (const auto& textureList = fileJ.at("textures"); auto textureJ : textureList)
            {
                const auto textureName = textureJ.at("texture-name");
                const auto textureSelect = textureJ.at("texture-select");
                int x = textureSelect.at("x");
                int y = textureSelect.at("y");
                int w = textureSelect.at("width");
                int h = textureSelect.at("height");

                auto intRect = sf::IntRect(x, y, w, h);
                loadedTextures[textureName].loadFromImage(image, intRect);
            }
        }

        loadedFiles.insert(jsonFilePath);
    }

    const sf::Texture& SFMLTextureManager::getTexture(const std::string& name) const
    {
        if (loadedTextures.contains(name)) return loadedTextures.at(name);
        throw std::invalid_argument("SFMLTextureParser::getTexture: Texture does not exist");
    }

    bool SFMLTextureManager::isJsonTextureLoaded(const std::string& jsonFilePath) const
    {
        return loadedFiles.contains(jsonFilePath);
    }

    bool SFMLTextureManager::loadJsonTextureConfigIfNotLoaded(const std::string& jsonFilePath)
    {
        if (!isJsonTextureLoaded(jsonFilePath))
        {
            loadJsonTextureConfig(jsonFilePath);
            return true;
        }
        return false;
    }
}

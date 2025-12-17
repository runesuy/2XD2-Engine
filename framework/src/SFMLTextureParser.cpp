//
// Created by rune-suy on 12/15/25.
//

#include "2XD2/framework/SFMLTextureParser.h"
#include "json.hpp"
#include "fstream"

#include <stdexcept>

#include "2XD2/framework/exceptions/FileLoadingFailedException.h"

namespace e2XD::framework
{
    void SFMLTextureParser::loadJsonTextureConfig(const std::string& jsonFilePath)
    {
        nlohmann::json json;

        std::ifstream file(jsonFilePath);
        if (!file.is_open()) throw e2XD::framework::FileLoadingFailedException(jsonFilePath, "void SFMLTextureParser::loadJsonTextureConfig(const std::string& jsonFilePath)");
        file >> json;
        file.close();

        for (const auto fileList = json.at("files"); const auto &fileJ : fileList)
        {
            const auto& fileName = fileJ.at("filename");

            // open target texture file
            sf::Image image;

            if (bool successLoading = image.loadFromFile(fileName); !successLoading) throw FileLoadingFailedException(fileName, "void SFMLTextureParser::loadJsonTextureConfig(const std::string& jsonFilePath)");

            for (const auto &textureList = fileJ.at("textures"); auto textureJ : textureList)
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
    }

    const sf::Texture& SFMLTextureParser::getTexture(const std::string& name) const
    {
        if (loadedTextures.contains(name))  return loadedTextures.at(name);
        throw std::invalid_argument("SFMLTextureParser::getTexture: Texture does not exist");
    }

    SFMLTextureParser* SFMLTextureParser::getInstance()
    {
        if (!_instance) _instance = new SFMLTextureParser();
        return _instance;
    }

}


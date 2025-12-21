//
// Created by rune-suy on 12/15/25.
//

#ifndef FLATLAND_ITEXTUREPARSER_H
#define FLATLAND_ITEXTUREPARSER_H
#include <set>
#include <unordered_map>
#include <string>
#include <SFML/Graphics/Texture.hpp>

#include "ITextureManager.h"


namespace e2XD::framework
{
    /**
     * Singleton
     */
    class SFMLTextureManager final : public ITextureManager
    {
        std::unordered_map<std::string, sf::Texture> loadedTextures;
        std::set<std::string> loadedFiles;

    public:
        friend class FRAMEWORK_SFMLTextureParser_TEST;
        SFMLTextureManager() = default;
        ~SFMLTextureManager() override = default;

        [[nodiscard]] const sf::Texture& getTexture(const std::string& name) const override;

        void loadJsonTextureConfig(const std::string& jsonFilePath) override;

        bool isJsonTextureLoaded(const std::string& jsonFilePath) const override;

        bool loadJsonTextureConfigIfNotLoaded(const std::string& jsonFilePath) override;
    };
}


#endif //FLATLAND_ITEXTUREPARSER_H
//
// Created by rune-suy on 12/15/25.
//

#ifndef FLATLAND_ITEXTUREPARSER_H
#define FLATLAND_ITEXTUREPARSER_H
#include <unordered_map>
#include <string>
#include <SFML/Graphics/Texture.hpp>


namespace e2XD::framework
{
    /**
     * Singleton
     */
    class SFMLTextureManager final
    {
        std::unordered_map<std::string, sf::Texture> loadedTextures;

        inline static SFMLTextureManager* _instance = nullptr;

        SFMLTextureManager() = default;

    public:
        friend class FRAMEWORK_SFMLTextureParser_TEST;
        SFMLTextureManager(const SFMLTextureManager&) = delete;
        SFMLTextureManager& operator=(const SFMLTextureManager&) = delete;
        SFMLTextureManager& operator=(SFMLTextureManager&&) = delete;
        SFMLTextureManager(SFMLTextureManager&&) = delete;

        ~SFMLTextureManager() = default;

        static SFMLTextureManager* getInstance();

        [[nodiscard]] const sf::Texture& getTexture(const std::string& name) const;

        void loadJsonTextureConfig(const std::string& jsonFilePath);
    };
}


#endif //FLATLAND_ITEXTUREPARSER_H
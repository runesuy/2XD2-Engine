//
// Created by rune-suy on 12/15/25.
//

#ifndef FLATLAND_ITEXTUREPARSER_H
#define FLATLAND_ITEXTUREPARSER_H
#include <map>
#include <string>
#include <SFML/Graphics/Texture.hpp>

#include "SFMLInputHandler.h"


namespace e2XD::framework
{
    /**
     * Singleton
     */
    class SFMLTextureParser final
    {
        std::map<std::string, sf::Texture> loadedTextures;

        inline static SFMLTextureParser* _instance = nullptr;

        SFMLTextureParser() = default;

    public:
        friend class FRAMEWORK_SFMLTextureParser_TEST;
        SFMLTextureParser(const SFMLTextureParser&) = delete;
        SFMLTextureParser& operator=(const SFMLTextureParser&) = delete;
        SFMLTextureParser& operator=(SFMLTextureParser&&) = delete;
        SFMLTextureParser(SFMLTextureParser&&) = delete;

        ~SFMLTextureParser() = default;

        static SFMLTextureParser* getInstance();

        [[nodiscard]] const sf::Texture& getTexture(const std::string& name) const;

        void loadJsonTextureConfig(const std::string& jsonFilePath);
    };
}


#endif //FLATLAND_ITEXTUREPARSER_H

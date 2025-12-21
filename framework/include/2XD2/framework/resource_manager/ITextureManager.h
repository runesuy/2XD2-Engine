//
// Created by rune-suy on 12/21/25.
//

#ifndef INC_2XD2_ENGINE_ITEXTUREMANAGER_H
#define INC_2XD2_ENGINE_ITEXTUREMANAGER_H
#include <string>
#include <SFML/Graphics/Texture.hpp>


namespace e2XD::framework
{
    class ITextureManager
    {
    public:
        virtual ~ITextureManager() = default;
        [[nodiscard]] virtual  const sf::Texture& getTexture(const std::string& name) const =0;

        virtual void loadJsonTextureConfig(const std::string& jsonFilePath)=0;

        [[nodiscard]] virtual bool isJsonTextureLoaded(const std::string& jsonFilePath) const=0;

        virtual bool loadJsonTextureConfigIfNotLoaded(const std::string& jsonFilePath)=0;
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_ITEXTUREMANAGER_H

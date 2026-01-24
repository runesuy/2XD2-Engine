// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/21/25.
//

#ifndef INC_2XD2_ENGINE_TEXTURES_H
#define INC_2XD2_ENGINE_TEXTURES_H
#include <string>
#include <SFML/Graphics/Texture.hpp>

#include "ITextureManager.h"
#include "Resources.h"


namespace e2XD::framework
{
    class Resources::Textures final
    {
        inline static ITextureManager* _textureManager = nullptr;

        /**
         * Checks if the Textures resource manager is initialized.
         * @throws NotInitializedException(Resources::Framework, caller) if not initialized
         * @param caller The name of the caller function
         */
        static void throwIfNotInitialized(const std::string& caller) ;

    public:
        ~Textures() = default;
        static void initialize(ITextureManager* textureManager);

        [[nodiscard]] static const sf::Texture& getTexture(const std::string& name);

        static void loadJsonTextureConfig(const std::string& jsonFilePath);

        [[nodiscard]] static bool isJsonTextureLoaded(const std::string& jsonFilePath);

        static bool loadJsonTextureConfigIfNotLoaded(const std::string& jsonFilePath);
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_TEXTURES_H

// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/11/26.
//

#ifndef INC_2XD2_ENGINE_IFONTMANAGER_H
#define INC_2XD2_ENGINE_IFONTMANAGER_H
#include <SFML/Graphics/Font.hpp>


namespace e2XD::framework
{
    class IFontManager
    {
    public:
        virtual ~IFontManager() = default;

        virtual void loadFont(const std::string& fontName, const std::string& filePath) =0;

        /**
         * Load font map from a file.
         *
         * After loading the file, fonts can be accessed by their names.
         *
         * Format (JSON):
         * @code
         * [
         *      {
         *          "name": "default",
         *          "path": "presets/assets/fonts/default.ttf"
         *      },
         *      {
         *          "name": "title",
         *          "path": "presets/assets/fonts/title.ttf"
         *      }
         * ]
         * @endcode
         * @param fontMapPath Path to the font map file.
         */
        virtual void loadFontMap(const std::string& fontMapPath) =0;

        /**
         * Load font map from a file if it is not already loaded.
         *
         * After loading the file, fonts can be accessed by their names.
         *
         * Format (JSON):
         * @code
         * [
         *      {
         *          "name": "default",
         *          "path": "presets/assets/fonts/default.ttf"
         *      },
         *      {
         *          "name": "title",
         *          "path": "presets/assets/fonts/title.ttf"
         *      }
         * ]
         * @endcode
         * @param fontMapPath Path to the font map file.
         * @return true if font map was loaded now, false if it was already loaded.
         */
        virtual bool loadFontMapIfNotLoaded(const std::string& fontMapPath) =0;

        virtual const sf::Font& getFont(const std::string& fontName) =0;
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_IFONTMANAGER_H

//
// Created by rune-suy on 1/11/26.
//

#ifndef INC_2XD2_ENGINE_FONTS_H
#define INC_2XD2_ENGINE_FONTS_H
#include "IFontManager.h"
#include "Resources.h"


namespace e2XD::framework
{
    class Resources::Fonts
    {
        inline static IFontManager* _fontManager = nullptr;
    public:
        static void initialize(IFontManager* fontManager);

        static const sf::Font& getFont(const std::string& fontName);

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
        static void loadFontMap(const std::string& fontMapPath);

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
        static bool loadFontMapIfNotLoaded(const std::string& fontMapPath);

        /**
         * Load a single font from a file.
         *
         * After loading the font, it can be accessed by its name.
         *
         * @param fontName Name to associate with the font.
         * @param fontPath Path to the font file.
         */
        static void loadFont(const std::string& fontName, const std::string& fontPath);
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_FONTS_H

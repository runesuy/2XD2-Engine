//
// Created by rune-suy on 1/11/26.
//

#ifndef INC_2XD2_ENGINE_DEFAULTFONTMANAGER_H
#define INC_2XD2_ENGINE_DEFAULTFONTMANAGER_H
#include <set>

#include "IFontManager.h"


namespace e2XD::framework
{
    class DefaultFontManager : public IFontManager
    {
        std::map<std::string, sf::Font> _loadedFonts;

        std::set<std::string> _loadedFiles;

    public:
        void loadFontMap(const std::string& fontMapPath) override;

        bool loadFontMapIfNotLoaded(const std::string& fontMapPath) override;

        void loadFont(const std::string& fontName, const std::string& filePath) override;

        const sf::Font& getFont(const std::string& fontName) override;
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_DEFAULTFONTMANAGER_H

//
// Created by rune-suy on 1/11/26.
//

#include "2XD2/framework/resource_manager/Fonts.h"

#include "2XD2/core/exceptions/NotInitializedException.h"


namespace e2XD::framework
{
    void Resources::Fonts::initialize(IFontManager* fontManager)
    {
        _fontManager = fontManager;
    }

    const sf::Font& Resources::Fonts::getFont(const std::string& fontName)
    {
        if (_fontManager == nullptr)
        {
            throw core::NotInitializedException("Fonts manager not initialized",
                                                "Resources::Fonts::getFont(const std::string& fontName)");
        }
        return _fontManager->getFont(fontName);
    }

    void Resources::Fonts::loadFontMap(const std::string& fontMapPath)
    {
        if (_fontManager == nullptr)
        {
            throw core::NotInitializedException("Fonts manager not initialized",
                                                "Resources::Fonts::loadFontMap(const std::string& fontMapPath)");
        }
        _fontManager->loadFontMap(fontMapPath);
    }

    bool Resources::Fonts::loadFontMapIfNotLoaded(const std::string& fontMapPath)
    {
        if (!_fontManager)
        {
            throw core::NotInitializedException("Fonts manager not initialized",
                                                "Resources::Fonts::loadFontMapIfNotLoaded(const std::string& fontMapPath)");
        }
        return _fontManager->loadFontMapIfNotLoaded(fontMapPath);
    }

    void Resources::Fonts::loadFont(const std::string& fontName, const std::string& fontPath)
    {
        if (!_fontManager)
        {
            throw core::NotInitializedException("Fonts manager not initialized",
                                                "Resources::Fonts::loadFont(const std::string& fontName, const std::string& fontPath)");
        }
        _fontManager->loadFont(fontName, fontPath);
    }
} // framework
// e2XD

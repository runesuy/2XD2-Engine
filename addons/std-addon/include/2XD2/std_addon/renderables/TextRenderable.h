//
// Created by rune-suy on 1/20/26.
//

#ifndef FLATLAND_TEXTRENDERABLE_H
#define FLATLAND_TEXTRENDERABLE_H
#include <SFML/Graphics/Text.hpp>

#include "2XD2/renderer/IRenderable.h"


namespace e2XD::std_addon
{
    /**
     * Renderable capable of displaying text.
     */
    class TextRenderable : public renderer::IRenderable
    {
        sf::Text _text;
        using FontType = sf::Font;
    public:
        TextRenderable();

        void draw(const renderer::IRenderTarget& renderTarget) const override;

        /**
         * Set the text string to display.
         * @param text
         */
        void setText(const std::string &text);

        /**
         * Set the font size of the text.
         * @param size
         */
        void setFontSize(unsigned int size);

        /**
         * Set the font of the text.
         * Font must exist as long as the text uses it.
         * @param font
         */
        void setFont(const FontType& font);
    };
} // std_addon
// e2XD

#endif //FLATLAND_TEXTRENDERABLE_H

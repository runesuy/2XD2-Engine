//
// Created by rune-suy on 1/20/26.
//

#ifndef FLATLAND_TEXTRENDERABLE_H
#define FLATLAND_TEXTRENDERABLE_H
#include <SFML/Graphics/Text.hpp>

#include "2XD2/core/Vec2f.h"
#include "2XD2/renderer/IRenderable.h"


namespace e2XD::std_addon
{
    /**
     * Renderable capable of displaying text.
     */
    class TextRenderable : public renderer::IRenderable
    {
        sf::Text _text;
    public:
        using FontType = sf::Font;
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

        /**
         * @return The width of the text renderable ignoring any transformations in coordinates
         */
        float getWidth() const;

        /**
         * @return The height of the text renderable ignoring any transformations in coordinates
         */
        float getHeight() const;

        /**
         * @return The size of the text renderable ignoring any transformations in coordinates
         */
        core::Vec2f getSize() const;

        /**
         * @return The origin of the text renderable ignoring any transformations in coordinates
         */
        core::Vec2f getOrigin() const;

        /**
         * Sets the origin of the text renderable ignoring any transformations in coordinates
         * @param origin
         */
        void setOrigin(const core::Vec2f& origin);
    };
} // std_addon
// e2XD

#endif //FLATLAND_TEXTRENDERABLE_H

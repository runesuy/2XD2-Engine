//
// Created by rune-suy on 1/20/26.
//

#ifndef FLATLAND_TEXTRENDERABLE_H
#define FLATLAND_TEXTRENDERABLE_H
#include <SFML/Graphics/Text.hpp>

#include "2XD2/renderer/IRenderable.h"


namespace e2XD::std_addon
{
    class TextRenderable : public renderer::IRenderable
    {
        sf::Text _text;

    public:
        TextRenderable();

        void draw(renderer::IRenderTarget& renderTarget) const override;

        void setText(const std::string &text);

        void setFontSize(unsigned int size);
    };
} // std_addon
// e2XD

#endif //FLATLAND_TEXTRENDERABLE_H

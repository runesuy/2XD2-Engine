//
// Created by rune-suy on 1/20/26.
//

#ifndef FLATLAND_SPRITERENDERABLE_H
#define FLATLAND_SPRITERENDERABLE_H
#include <string>
#include <SFML/Graphics/Sprite.hpp>

#include "2XD2/renderer/IRenderable.h"


namespace e2XD::std_addon
{
    class SpriteRenderable : public renderer::IRenderable
    {
        sf::Sprite _sprite;
    public:
        SpriteRenderable();

        void draw(renderer::IRenderTarget& renderTarget) const override;

        /**
         * Set the texture of the sprite by its name.
         * The texture must be loaded in the SFMLTextureParser.
         * @param textureName Name of the texture as loaded in the SFMLTextureParser.
         * @see framework::SFMLTextureParser
         */
        virtual void setTexture(const std::string& textureName);

        /**
         * Set the texture of the sprite directly.
         * @param texture sf::Texture that must exist as long as the sprite uses it.
         */
        virtual void setTexture(const sf::Texture& texture);
    };
} // std_addon
// e2XD

#endif //FLATLAND_SPRITERENDERABLE_H

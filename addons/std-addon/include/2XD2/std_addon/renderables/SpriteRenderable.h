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
    /**
     * A renderable capable of displaying a 2D sprite.
     */
    class SpriteRenderable : public renderer::IRenderable
    {
        sf::Sprite _sprite;
        using TextureType = sf::Texture;
    public:
        SpriteRenderable();

        void draw(renderer::IRenderTarget& renderTarget) const override;

        /**
         * Set the texture of the sprite directly.
         * @param texture sf::Texture that must exist as long as the sprite uses it.
         */
        virtual void setTexture(const TextureType& texture);
    };
} // std_addon
// e2XD

#endif //FLATLAND_SPRITERENDERABLE_H

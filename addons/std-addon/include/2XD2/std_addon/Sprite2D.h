// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/17/25.
//

#ifndef FLATLAND_SPRITE2D_H
#define FLATLAND_SPRITE2D_H
#include <SFML/Graphics/Sprite.hpp>
#include "2XD2/framework/nodes/Node2D.h"


namespace e2XD::std_addon
{
    /**
     * A 2D sprite node.
     */
    class Sprite2D : public framework::Node2D
    {
        sf::Sprite _sprite;

    public:
        Sprite2D() = default;
        ~Sprite2D() override = default;

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

    protected:
        void _internal_onDraw() override;
    };
} // framework
// e2XD

#endif //FLATLAND_SPRITE2D_H

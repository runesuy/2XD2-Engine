//
// Created by rune-suy on 1/20/26.
//

#ifndef FLATLAND_IRENDERTARGET_H
#define FLATLAND_IRENDERTARGET_H
#include <SFML/Graphics/Drawable.hpp>


namespace e2XD::renderer
{
    class IRenderTarget
    {
    public:
        virtual ~IRenderTarget() = default;
        virtual void draw(const sf::Drawable& drawable) const =0;
    };
} // renderer
// e2XD

#endif //FLATLAND_IRENDERTARGET_H

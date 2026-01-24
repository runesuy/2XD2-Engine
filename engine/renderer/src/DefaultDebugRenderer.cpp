//
// Created by rune-suy on 1/21/26.
//

#include "2XD2/renderer/DefaultDebugRenderer.h"

#include <SFML/Graphics/CircleShape.hpp>


namespace e2XD::renderer
{
    DefaultDebugRenderer::DefaultDebugRenderer() : DefaultRenderer()
    {
    }

    void DefaultDebugRenderer::initialize(sf::RenderWindow* window)
    {
        DefaultRenderer::initialize(window);

        // Override render target with debug render target
        renderTarget = std::make_unique<DebugRenderTarget>(*window);
        target = dynamic_cast<DebugRenderTarget*>(renderTarget.get());
    }

    void DefaultDebugRenderer::setShowOrigins(const bool show)
    {
        target->_showOrigins = show;
    }

    bool DefaultDebugRenderer::isShowingOrigins() const
    {
        return target->_showOrigins;
    }



    //------------------- DebugRenderTarget --------------------
    void DebugRenderTarget::draw(const sf::Drawable& drawable) const
    {
        RenderTarget::draw(drawable);
        if (_showOrigins)
        {
            sf::CircleShape originMarker(ORIGIN_MARKER_RADIUS);
            originMarker.setFillColor(sf::Color::Red);
            window.draw(originMarker, sf::RenderStates(*transform));
        }
    }
} // renderer
// e2XD

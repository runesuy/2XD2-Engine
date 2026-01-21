//
// Created by rune-suy on 1/21/26.
//

#ifndef FLATLAND_DEFAULTDEBUGRENDERER_H
#define FLATLAND_DEFAULTDEBUGRENDERER_H
#include "DefaultRenderer.h"


namespace e2XD::renderer
{
    class DebugRenderTarget : public DefaultRenderer::RenderTarget
    {
        friend class DefaultDebugRenderer;
        bool _showOrigins = true;

        static constexpr float ORIGIN_MARKER_RADIUS = 1.0f;

    public:
        explicit DebugRenderTarget(sf::RenderWindow& targetWindow) : RenderTarget(targetWindow)
        {
        }

        void draw(const sf::Drawable& drawable) const override;
    };

    class DefaultDebugRenderer : public DefaultRenderer
    {
        DebugRenderTarget* target = nullptr;

    public:
        DefaultDebugRenderer();

        void initialize(sf::RenderWindow* window) override;

        void setShowOrigins(bool show);
        bool isShowingOrigins() const;
    };
} // renderer
// e2XD

#endif //FLATLAND_DEFAULTDEBUGRENDERER_H

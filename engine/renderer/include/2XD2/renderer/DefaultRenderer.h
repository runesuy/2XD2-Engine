//
// Created by rune-suy on 1/11/26.
//

#ifndef INC_2XD2_ENGINE_DEFAULTRENDERER_H
#define INC_2XD2_ENGINE_DEFAULTRENDERER_H
#include <unordered_map>

#include "IRenderer.h"


namespace e2XD::renderer
{
    class DefaultRenderer : public IRenderer
    {
        sf::RenderWindow* window = nullptr;

        std::unordered_map<RenderLayer, std::vector<RenderCommand>> renderQueue;

        std::unordered_map<RenderLayer , sf::FloatRect> _viewSizes;

    public:
        DefaultRenderer() = default;

        void initialize(sf::RenderWindow* window) override;

        void clearWindow() const override;

        void submit(const RenderCommand& renderCommand) override;

        void flush(const core::Vec2f& cameraPosition, float cameraZoom) override;

        core::Vec2<unsigned int> getWindowSize() const override;

        void setWindowView(RenderLayer, const core::Vec2f&) override;
    };
} // renderer
// e2XD

#endif //INC_2XD2_ENGINE_DEFAULTRENDERER_H

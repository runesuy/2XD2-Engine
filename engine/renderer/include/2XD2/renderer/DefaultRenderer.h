//
// Created by rune-suy on 1/11/26.
//

#ifndef INC_2XD2_ENGINE_DEFAULTRENDERER_H
#define INC_2XD2_ENGINE_DEFAULTRENDERER_H
#include <unordered_map>

#include "IRenderer.h"
#include "ViewMode.h"


namespace e2XD::renderer
{
    class DefaultRenderer : public IRenderer
    {
        sf::RenderWindow* window = nullptr;

        std::unordered_map<RenderLayer, std::vector<RenderCommand>> renderQueue;

        std::unordered_map<RenderLayer, ViewMode> _viewModes = {
            {RenderLayer::BACKGROUND, ViewMode::Expand},
            {RenderLayer::WORLD, ViewMode::Expand},
            {RenderLayer::UI, ViewMode::Expand}
        };

        void _setViewSize(ViewMode viewMode) const;

        void _setViewSize(ViewMode viewMode, const core::Vec2f& center, const core::Vec2f& size, float cameraZoom) const;

    public:
        DefaultRenderer() = default;

        void initialize(sf::RenderWindow* window) override;

        void clearWindow() const override;

        void submit(const RenderCommand& renderCommand) override;

        void flush(const core::Vec2f& cameraPosition, const core::Vec2f& cameraSize, float cameraZoom) override;

        void setViewMode(RenderLayer, ViewMode viewMode) override;
    };
} // renderer
// e2XD

#endif //INC_2XD2_ENGINE_DEFAULTRENDERER_H

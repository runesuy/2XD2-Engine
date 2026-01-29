// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/11/26.
//

#include "2XD2/renderer/DefaultRenderer.h"

#include "2XD2/renderer/internal/SfmlConversions.h"


namespace e2XD::renderer
{
    DefaultRenderer::RenderTarget::RenderTarget(sf::RenderWindow& targetWindow) : window(targetWindow)
    {
    }

    void DefaultRenderer::RenderTarget::draw(const sf::Drawable& drawable) const
    {
        if (transform)
        {
            window.draw(drawable, sf::RenderStates(*transform));
            return;
        }
        window.draw(drawable);
    }

    void DefaultRenderer::initialize(sf::RenderWindow* window)
    {
        this->window = window;
        renderTarget = std::make_unique<RenderTarget>(*window);
    }

    void DefaultRenderer::clearWindow() const
    {
        window->clear();
    }


    void DefaultRenderer::submit(const RenderCommand& renderCommand)
    {
        renderQueue[renderCommand.renderLayer].push_back(renderCommand);
    }

    void DefaultRenderer::flush(const core::Vec2f& cameraPosition, const core::Vec2f& cameraSize, const float cameraZoom)
    {
        for (const auto& layer : RenderOrder)
        {
            if (window->getSize().x == 0 || window->getSize().y == 0) break;
            //Setup view
            if (layer == RenderLayer::WORLD)
            {
                if (cameraSize.x == 0 || cameraSize.y == 0) continue;
                _setViewSize(_viewModes[layer], cameraPosition, cameraSize, cameraZoom);
            }
            else
            {
                _setViewSize(_viewModes[layer]);
            }

            // sort by zIndex
            _sortRenderLayerRenderCommands(renderQueue[layer]);

            // draw commands
            for (const auto& render_command : renderQueue[layer])
            {
                _drawRenderCommand(render_command);
            }
        }

        renderQueue.clear();
    }

    void DefaultRenderer::_sortRenderLayerRenderCommands(std::vector<RenderCommand>& renderCommands) const
    {
        std::ranges::sort(renderCommands,
                              [](const RenderCommand& a, const RenderCommand& b)
                              {
                                  if (a.zIndex != b.zIndex) return a.zIndex < b.zIndex;
                                  return a.position.y < b.position.y;
                              });
    }

    void DefaultRenderer::_drawRenderCommand(const RenderCommand& command) const
    {
        sf::Transform transform;
        transform.translate(internal::toSfmlVector(command.position));
        renderTarget->transform = &transform;
        command.renderable->draw(*renderTarget);
    }

    void DefaultRenderer::_setViewSize(const ViewMode viewMode, const core::Vec2f& center,
                                       const core::Vec2f& size, const float cameraZoom) const
    {
        if (viewMode == ViewMode::StretchToFill)
        {
            window->setView(sf::View{
                sf::Vector2f{center.x, center.y}, sf::Vector2f{size.x * cameraZoom, size.y * cameraZoom}
            });
            return;
        }
        if (viewMode == ViewMode::Letterbox)
        {
            const float windowAspectRatio = static_cast<float>(window->getSize().x) / static_cast<float>(window->
                getSize().y);
            const float cameraAspectRatio = size.x / size.y;

            sf::View view;
            if (windowAspectRatio > cameraAspectRatio)
            {
                // Window is wider than camera view
                const float newWidth = size.y * windowAspectRatio;
                view = sf::View{
                    sf::Vector2f{center.x, center.y}, sf::Vector2f{newWidth * cameraZoom, size.y * cameraZoom}
                };
            }
            else
            {
                // Window is taller than camera view
                const float newHeight = size.x / windowAspectRatio;
                view = sf::View{
                    sf::Vector2f{center.x, center.y}, sf::Vector2f{size.x * cameraZoom, newHeight * cameraZoom}
                };
            }
            window->setView(view);
            return;
        }

        if (viewMode == ViewMode::Expand)
        {
            const float windowAspectRatio = static_cast<float>(window->getSize().x) / static_cast<float>(window->
                getSize().y);
            const float cameraAspectRatio = size.x / size.y;

            sf::View view;
            if (windowAspectRatio < cameraAspectRatio)
            {
                // Window is narrower than camera view
                const float newHeight = size.x / windowAspectRatio;
                view = sf::View{
                    sf::Vector2f{center.x, center.y}, sf::Vector2f{size.x * cameraZoom, newHeight * cameraZoom}
                };
            }
            else
            {
                // Window is shorter than camera view
                const float newWidth = size.y * windowAspectRatio;
                view = sf::View{
                    sf::Vector2f{center.x, center.y}, sf::Vector2f{newWidth * cameraZoom, size.y * cameraZoom}
                };
            }
            window->setView(view);
            return;
        }

        if (viewMode == ViewMode::Fill)
        {
            // Cut a part of the camera view to fill the window

            float windowRatio = static_cast<float>(window->getSize().x) / static_cast<float>(window->getSize().y);
            float cameraRatio = size.x / size.y;

            if (cameraRatio > windowRatio)
            {
                // Camera is wider than window
                const float newWidth = size.y * windowRatio;
                sf::View view{
                    sf::Vector2f{center.x, center.y}, sf::Vector2f{newWidth * cameraZoom, size.y * cameraZoom}
                };
                window->setView(view);
                return;
            }
            else
            {
                // Camera is taller than window
                const float newHeight = size.x / windowRatio;
                sf::View view{
                    sf::Vector2f{center.x, center.y}, sf::Vector2f{size.x * cameraZoom, newHeight * cameraZoom}
                };
                window->setView(view);
                return;
            }
        }
    }

    void DefaultRenderer::_setViewSize(const ViewMode viewMode) const
    {
        // TODO: Implement other view modes for UI layers
        if (viewMode == ViewMode::StretchToFill)
        {
            window->setView(window->getDefaultView());
            return;
        }
        if (viewMode == ViewMode::Expand)
        {
            const float windowAspectRatio = static_cast<float>(window->getSize().x) / static_cast<float>(window->
                getSize().y);
            const auto temp = window->getDefaultView().getSize();
            const float cameraAspectRatio = temp.x / temp.y;

            sf::View view;
            if (windowAspectRatio < cameraAspectRatio)
            {
                // Window is narrower than camera view
                const float newHeight = temp.x / windowAspectRatio;
                view = sf::View{sf::FloatRect{0,0, temp.x, newHeight}};
            }
            else
            {
                // Window is shorter than camera view
                const float newWidth = temp.y * windowAspectRatio;
                view = sf::View{
                    sf::Vector2f{0, 0}, sf::Vector2f{newWidth, temp.y}
                };
            }
            window->setView(view);
            return;
        }
        window->setView(window->getDefaultView());
    }

    void DefaultRenderer::setViewMode(const RenderLayer layer, const ViewMode viewMode)
    {
        _viewModes[layer] = viewMode;
    }
} // DefaultRenderer
// e2XD

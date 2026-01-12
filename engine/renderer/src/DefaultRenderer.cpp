//
// Created by rune-suy on 1/11/26.
//

#include "2XD2/renderer/DefaultRenderer.h"


namespace e2XD::renderer
{
    void DefaultRenderer::initialize(sf::RenderWindow* window)
    {
        this->window = window;
    }

    void DefaultRenderer::clearWindow() const
    {
        window->clear();
    }


    void DefaultRenderer::submit(const RenderCommand& renderCommand)
    {
        renderQueue[renderCommand.renderLayer].push_back(renderCommand);
    }

    void DefaultRenderer::flush(const core::Vec2f& cameraPosition, float cameraZoom)
    {
        for (const auto& layer : RenderOrder)
        {
            for (const auto& command : renderQueue[layer])
            {
                //Setup view
                if (layer == RenderLayer::WORLD)
                {
                    const auto& camPos = cameraPosition;
                    auto view = sf::View{
                        {camPos.x, camPos.y}, sf::Vector2f{window->getSize()}
                    };
                    view.zoom(cameraZoom);
                    window->setView(view);
                }
                else
                {
                    if (_viewSizes.contains(layer)) window->setView(sf::View{_viewSizes.at(layer)});
                    else window->setView(window->getDefaultView());
                }

                // sort by zIndex

                std::ranges::sort(renderQueue[layer],
                                  [](const RenderCommand& a, const RenderCommand& b)
                                  {
                                      if (a.zIndex != b.zIndex) return a.zIndex < b.zIndex;
                                      return a.position.y < b.position.y;
                                  });

                // draw commands
                for (const auto& render_command : renderQueue[layer])
                {
                    sf::Transform transform;
                    transform.translate(render_command.position);
                    window->draw(*render_command.drawable, transform);
                }
            }
        }
        renderQueue.clear();
    }

    core::Vec2<unsigned int> DefaultRenderer::getWindowSize() const
    {
        return {window->getSize().x, window->getSize().y};
    }

    void DefaultRenderer::setWindowView(const RenderLayer layer, const core::Vec2f &viewSize)
    {
        _viewSizes[layer] = sf::FloatRect{0,0, viewSize.x, viewSize.y};
    }
} // DefaultRenderer
// e2XD

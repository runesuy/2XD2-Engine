//
// Created by runes on 14/12/2025.
//

#include "2XD2/renderer/Renderer.h"

#include "2XD2/core/exceptions/NotInitializedException.h"
#include "2XD2/renderer/RenderCommand.h"

namespace e2XD::renderer
{
    void Renderer::initialize(sf::RenderWindow* window)
    {
        this->window = window;
    }

    Renderer* Renderer::getInstance()
    {
        if (!_instance)
        {
            _instance = new Renderer();
        }
        return _instance;
    }

    void Renderer::clearWindow() const
    {
        window->clear();
    }


    void Renderer::submit(const RenderCommand& renderCommand)
    {
        renderQueue[renderCommand.renderLayer].push_back(renderCommand);
    }

    void Renderer::flush(const core::Camera* worldCamera)
    {
        for (const auto& [layer, commands] : renderQueue)
        {
            for (const auto& command : commands)
            {
                //Setup view
                if (layer == RenderLayer::WORLD && worldCamera)
                {
                    const auto& camPos = worldCamera->getGlobalPosition();
                    auto view = sf::View{
                        {camPos.x, camPos.y}, sf::Vector2f{window->getSize()}};
                    view.zoom(worldCamera->getZoom());
                    window->setView(view);

                }
                else
                {
                    window->setView(window->getDefaultView());
                }

                // sort by zIndex

                std::ranges::sort(renderQueue[layer],
                                  [](const RenderCommand& a, const RenderCommand& b) {
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



} // e2XD

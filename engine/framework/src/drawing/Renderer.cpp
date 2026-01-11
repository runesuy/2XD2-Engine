//
// Created by runes on 14/12/2025.
//

#include "../../include/2XD2/framework/drawing/Renderer.h"

#include "2XD2/core/exceptions/NotInitializedException.h"
#include "2XD2/renderer/RenderCommand.h"
#include "2XD2/renderer/RenderLayer.h"

namespace e2XD::framework
{
    void Renderer::initialize(renderer::IRenderer* renderer)
    {
        _renderer = renderer;
    }


    void Renderer::clearWindow()
    {
        _renderer->clearWindow();
    }

    void Renderer::initialize(sf::RenderWindow* window)
    {
        _renderer->initialize(window);
    }


    void Renderer::submit(const renderer::RenderCommand& renderCommand)
    {
        _renderer->submit(renderCommand);
    }

    void Renderer::flush(const core::Vec2f& cameraPosition, float cameraZoom)
    {
        _renderer->flush(cameraPosition, cameraZoom);
    }

    core::Vec2<unsigned int> Renderer::getWindowSize()
    {
        return _renderer->getWindowSize();
    }

    void Renderer::setWindowView(RenderLayer renderLayer, const core::Vec2f& v)
    {
        _renderer->setWindowView(renderLayer, v);
    }
} // e2XD

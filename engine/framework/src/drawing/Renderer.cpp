// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by runes on 14/12/2025.
//

#include "2XD2/framework/drawing/Renderer.h"
#include "2XD2/renderer/RenderCommand.h"

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

    void Renderer::flush(const core::Vec2f& cameraPosition, const core::Vec2f& cameraSize, const float cameraZoom)
    {
        _renderer->flush(cameraPosition, cameraSize, cameraZoom);
    }

    void Renderer::registerDrawTarget(const DrawTarget* drawTarget)
    {
        _drawTargets.push_back(drawTarget);
    }

    void Renderer::registerDrawable(Drawable* drawable)
    {
        _drawables.push_back(drawable);
    }

    void Renderer::callDrawables()
    {
        for (const auto& drawTarget : _drawTargets)
        {
            for (const auto& drawable : _drawables)
            {
                drawable->draw();
            }
        }
    }

    void Renderer::reloadDrawableLayouts()
    {

    }

    void Renderer::clearDrawables()
    {
        _drawables.clear();
    }

    void Renderer::clearDrawTargets()
    {
        _drawTargets.clear();
    }
} // e2XD

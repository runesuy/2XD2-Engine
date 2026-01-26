// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_RENDERER_H
#define INC_2XD2_ENGINE_RENDERER_H
#include <SFML/Graphics/RenderWindow.hpp>

#include "Drawable.h"
#include "2XD2/renderer/RenderCommand.h"
#include "2XD2/core/Vec2f.h"
#include "2XD2/renderer/IRenderer.h"
#include "2XD2/renderer/RenderLayer.h"

namespace e2XD::framework
{
    /**
     * Interface that works as middle man between the framework and the IRenderer provided by IConfig.
     */
    class Renderer
    {
        inline static renderer::IRenderer* _renderer = nullptr;

        friend class Game;

        inline static std::list<const DrawTarget*> _drawTargets;
        inline static std::list<Drawable*> _drawables;

    public:
        /**
         * Initialize the renderer system with the provided renderer.
         * @param renderer
         */
        static void initialize(renderer::IRenderer* renderer);

        /**
         * Initialize the renderer system with the provided SFML RenderWindow.
         * Does not replace the need for renderer initialization.
         * @param window
         */
        static void initialize(sf::RenderWindow* window);

        /**
         * Clear the window before rendering a new frame.
         */
        static void clearWindow();

        /**
         * Submit a render command to the renderer.
         * Command will be rendered on next flush.
         * @param renderCommand
         */
        static void submit(const renderer::RenderCommand& renderCommand);

        /**
         * Flush all submitted render commands to the window.
         * @param cameraPosition
         * @param cameraSize
         * @param cameraZoom
         */
        static void flush(const core::Vec2f& cameraPosition, const core::Vec2f& cameraSize, float cameraZoom);

        static void registerDrawable(Drawable* drawable);

        static void registerDrawTarget(const DrawTarget* drawTarget);

        static void callDrawables();

        static void clearDrawables();

        static void clearDrawTargets();
    };
}


#endif //INC_2XD2_ENGINE_RENDERER_H

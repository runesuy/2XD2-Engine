//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_RENDERER_H
#define INC_2XD2_ENGINE_RENDERER_H
#include <SFML/Graphics/RenderWindow.hpp>
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
        static void setWindowView(RenderLayer renderLayer, const core::Vec2f&);

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
         * @param cameraZoom
         */
        static void flush(const core::Vec2f& cameraPosition, float cameraZoom);

        /**
         * Get the current window size.
         * @return
         */
        static core::Vec2<unsigned int> getWindowSize();
    };
}


#endif //INC_2XD2_ENGINE_RENDERER_H

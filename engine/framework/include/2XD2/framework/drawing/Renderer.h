//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_RENDERER_H
#define INC_2XD2_ENGINE_RENDERER_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include "../../../../../renderer/include/2XD2/renderer/RenderCommand.h"
#include "2XD2/core/Vec2f.h"
#include <unordered_map>

#include "../../../../../renderer/include/2XD2/renderer/IRenderer.h"
#include "../../../../../renderer/include/2XD2/renderer/RenderLayer.h"

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
        static void initialize(renderer::IRenderer* renderer);

        static void initialize(sf::RenderWindow* window);

        static void clearWindow();

        static void submit(const renderer::RenderCommand& renderCommand);

        static void flush(const core::Vec2f& cameraPosition, float cameraZoom);

        static core::Vec2<unsigned int> getWindowSize();
    };
}


#endif //INC_2XD2_ENGINE_RENDERER_H

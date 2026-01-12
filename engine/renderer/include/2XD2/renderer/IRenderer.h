//
// Created by rune-suy on 1/11/26.
//

#ifndef INC_2XD2_ENGINE_IRENDERER_H
#define INC_2XD2_ENGINE_IRENDERER_H
#include <SFML/Graphics/RenderWindow.hpp>

#include "RenderCommand.h"
#include "2XD2/core/Vec2f.h"


namespace e2XD::renderer
{
    class IRenderer
    {
    public:
        virtual ~IRenderer() = default;
        virtual void initialize(sf::RenderWindow* window) =0;

        virtual void clearWindow() const =0;

        virtual void submit(const RenderCommand& renderCommand) =0;

        virtual void flush(const core::Vec2f& cameraPosition, float cameraZoom) =0;

        [[nodiscard]] virtual core::Vec2<unsigned int> getWindowSize() const =0;

        virtual void setWindowView(RenderLayer, const core::Vec2f&) =0;
    };
} // renderer
// e2XD

#endif //INC_2XD2_ENGINE_IRENDERER_H

//
// Created by rune-suy on 1/29/26.
//

#ifndef FLATLAND_COLORRECT_H
#define FLATLAND_COLORRECT_H
#include "UiNode.h"
#include "2XD2/framework/types/Color.h"
#include "2XD2/std_addon/renderables/RectangleRenderable.h"


namespace e2XD::std_addon
{
    using namespace framework;

    class ColorRect : public UiNode
    {
        Color _color = Color::White;
        RectangleRenderable _rectangleRenderable;

    public:
        ColorRect();
        ~ColorRect() override = default;

        void setColor(const Color& color);

        [[nodiscard]] const Color& getColor() const;

    protected:
        void _internal_onDraw() override;
    };
} // std_addon
// e2XD

#endif //FLATLAND_COLORRECT_H

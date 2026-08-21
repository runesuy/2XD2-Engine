// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/10/26.
//

#ifndef INC_2XD2_ENGINE_LABEL_H
#define INC_2XD2_ENGINE_LABEL_H

#include "Align.h"
#include "2XD2/framework/nodes/Drawable2D.h"
#include "2XD2/std_addon/renderables/TextRenderable.h"
#include "UiNode.h"


namespace e2XD::framework
{
    class DrawTarget;
}

namespace e2XD::std_addon
{
    /**
     * A text label node.
     */
    class Label : public UiNode
    {
        TextRenderable _renderable;

        AlignVec _originAlign;

    public:
        Label()=default;

    protected:
        void _internal_onDraw() override;

        void recalculateOriginAlign();
    public:
        /**
         * Get the text renderable of the label.
         * This is the renderable that handles the text display.
         * Can be used to change text properties.
         * @return The text renderable of the label.
         */
        TextRenderable& getRenderable() { return _renderable; }

        /**
         *
         * @return The text renderable of the label.
         */
        const TextRenderable& getRenderable() const { return _renderable; }

        const AlignVec& getOriginAlign() const;

        void setOriginAlign(const AlignVec& originAlign);

        /**
         * Set the text string to display.
         * @param text
         */
        void setText(const std::string &text);

        /**
         * Set the font size of the text.
         * @param size
         */
        void setFontSize(unsigned int size);

        /**
         * Set the font of the text.
         * Font must exist as long as the text uses it.
         * @param font
         */
        void setFont(const TextRenderable::FontType& font);
    };
} // std_addon
// e2XD

#endif //INC_2XD2_ENGINE_LABEL_H

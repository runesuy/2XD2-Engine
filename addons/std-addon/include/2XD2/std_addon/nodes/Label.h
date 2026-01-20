// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/10/26.
//

#ifndef INC_2XD2_ENGINE_LABEL_H
#define INC_2XD2_ENGINE_LABEL_H


#include "2XD2/framework/nodes/Node2D.h"
#include "2XD2/std_addon/renderables/TextRenderable.h"


namespace e2XD::std_addon
{
    /**
     * A text label node.
     */
    class Label : public framework::Node2D
    {
        TextRenderable _renderable;
    public:
        Label()=default;

    protected:
        void _internal_onDraw() override;

        TextRenderable& getRenderable() { return _renderable; }

        const TextRenderable& getRenderable() const { return _renderable; }
    };
} // std_addon
// e2XD

#endif //INC_2XD2_ENGINE_LABEL_H

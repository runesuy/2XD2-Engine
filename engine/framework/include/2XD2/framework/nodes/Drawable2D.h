// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/26/26.
//

#ifndef INC_2XD2_ENGINE_DRAWABLE2D_H
#define INC_2XD2_ENGINE_DRAWABLE2D_H
#include "2XD2/framework/drawing/Drawable.h"
#include "2XD2/framework/nodes/Node2D.h"


namespace e2XD::framework
{
    class Drawable2D : public Node2D, public Drawable
    {
    public:
        Drawable2D() = default;
        ~Drawable2D() override = default;

        void setVisible(bool visible) override;

        void addSubNode(std::unique_ptr<Node> node) override;

    protected:
        void _internal_onCreate() override;

        void _notification(int what) override;
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_DRAWABLE2D_H

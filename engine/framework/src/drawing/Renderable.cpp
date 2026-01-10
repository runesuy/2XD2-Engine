//
// Created by rune-suy on 12/19/25.
//

#include "../../include/2XD2/framework/drawing/Renderable.h"


namespace e2XD::framework
{
    void Renderable::draw()
    {
        _internal_onDraw();
        onDraw();
    }
} // core
// e2XD
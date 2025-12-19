//
// Created by rune-suy on 12/19/25.
//

#include "2XD2/core/Renderable.h"


    namespace e2XD::core
    {
        void Renderable::draw() {
            _internal_onDraw();
            onDraw();
        }
    } // core
// e2XD
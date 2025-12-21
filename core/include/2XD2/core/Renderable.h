//
// Created by rune-suy on 12/19/25.
//

#ifndef FLATLAND_RENDERABLE_H
#define FLATLAND_RENDERABLE_H
#include "RenderLayer.h"


namespace e2XD::core
    {
        class Renderable
        {
        protected:
            RenderLayer renderLayer= RenderLayer::WORLD;

            int zIndex=0;

            virtual void onDraw(){};

            virtual void _internal_onDraw(){};

        public:
            virtual ~Renderable() = default;
            void draw();
        };
    } // core
// e2XD

#endif //FLATLAND_RENDERABLE_H
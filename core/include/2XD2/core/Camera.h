//
// Created by runes on 15/12/2025.
//

#ifndef INC_2XD2_ENGINE_CAMERA_H
#define INC_2XD2_ENGINE_CAMERA_H
#include "Node2D.h"

    namespace e2XD::core {
        class Camera : public Node2D {
            double zoom=1;
        public:
            Camera()=default;
            ~Camera() override=default;
        };
    } // core
// e2XD

#endif //INC_2XD2_ENGINE_CAMERA_H
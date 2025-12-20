//
// Created by rune-suy on 12/20/25.
//

#ifndef INC_2XD2_ENGINE_MAINSCENE_H
#define INC_2XD2_ENGINE_MAINSCENE_H
#include "2XD2/core/Scene.h"
#include "2XD2/core/Camera.h"

class MainScene : public e2XD::core::Scene
{
    public:
    e2XD::core::Camera camera;
    MainScene();
};


#endif //INC_2XD2_ENGINE_MAINSCENE_H
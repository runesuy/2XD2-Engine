//
// Created by runes on 21/12/2025.
//

#include "2XD2/core/Scene.h"
#include "2XD2/core/Camera.h"
#include <gtest/gtest.h>

using namespace e2XD::core;

TEST(CORE_Scene, SetAndGetActiveCamera) {
    Scene scene;
    Camera cam;
    EXPECT_EQ(scene.getActiveCamera(), nullptr);

    scene.setActiveCamera(&cam);
    EXPECT_EQ(scene.getActiveCamera(), &cam);
}

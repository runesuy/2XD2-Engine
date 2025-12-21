//
// Created by runes on 21/12/2025.
//

#include "2XD2/core/Camera.h"
#include <gtest/gtest.h>

using namespace e2XD::core;

TEST(CORE_Camera, DefaultZoomAndPosition) {
    Camera cam;
    EXPECT_FLOAT_EQ(cam.getZoom(), 1.0f);
    EXPECT_FLOAT_EQ(cam.getGlobalPosition().x, 0.0f);
    EXPECT_FLOAT_EQ(cam.getGlobalPosition().y, 0.0f);
}

TEST(CORE_Camera, SettersAffectState) {
    Camera cam;
    cam.setZoom(1.5f);
    cam.setGlobalPosition({3.0f, -2.0f});

    EXPECT_FLOAT_EQ(cam.getZoom(), 1.5f);
    EXPECT_FLOAT_EQ(cam.getGlobalPosition().x, 3.0f);
    EXPECT_FLOAT_EQ(cam.getGlobalPosition().y, -2.0f);
}

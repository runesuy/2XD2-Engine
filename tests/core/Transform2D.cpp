//
// Created by runes on 21/12/2025.
//

#include "2XD2/core/Transform2D.h"
#include <gtest/gtest.h>

using namespace e2XD::core;

TEST(CORE_Transform2D, DefaultValues) {
    Transform2D t;
    EXPECT_FLOAT_EQ(t.getPosition().x, 0.0f);
    EXPECT_FLOAT_EQ(t.getPosition().y, 0.0f);
    EXPECT_FLOAT_EQ(t.getScale().x, 1.0f);
    EXPECT_FLOAT_EQ(t.getScale().y, 1.0f);
    EXPECT_DOUBLE_EQ(t.getRotation(), 0.0);
}

TEST(CORE_Transform2D, SettersUpdateState) {
    Transform2D t;
    Vec2f pos{2.0f, -3.0f};
    Vec2f scale{0.5f, 2.0f};

    t.setPosition(pos);
    t.setScale(scale);
    t.setRotation(30.0);

    EXPECT_FLOAT_EQ(t.getPosition().x, pos.x);
    EXPECT_FLOAT_EQ(t.getPosition().y, pos.y);
    EXPECT_FLOAT_EQ(t.getScale().x, scale.x);
    EXPECT_FLOAT_EQ(t.getScale().y, scale.y);
    EXPECT_DOUBLE_EQ(t.getRotation(), 30.0);
}

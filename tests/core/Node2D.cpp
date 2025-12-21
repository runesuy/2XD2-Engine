//
// Created by runes on 21/12/2025.
//

#include "2XD2/core/Node2D.h"
#include <gtest/gtest.h>

using namespace e2XD::core;

class CORE_Node2D : public ::testing::Test {
protected:
    Node2D parent;
    Node2D* child = nullptr;

    void SetUp() override {
        child = parent.createSubNode<Node2D>();
    }
};

TEST_F(CORE_Node2D, SetGlobalPositionPropagatesToChild) {
    const Vec2f target{5.0f, -3.0f};
    child->setLocalPosition({1.0f, 2.0f});

    parent.setGlobalPosition(target);

    EXPECT_FLOAT_EQ(parent.getGlobalPosition().x, target.x);
    EXPECT_FLOAT_EQ(parent.getGlobalPosition().y, target.y);
    EXPECT_FLOAT_EQ(parent.getLocalPosition().x, target.x);
    EXPECT_FLOAT_EQ(parent.getLocalPosition().y, target.y);

    ASSERT_NE(child, nullptr);
    EXPECT_FLOAT_EQ(child->getGlobalPosition().x, 6.0f);
    EXPECT_FLOAT_EQ(child->getGlobalPosition().y, -1.0f);
    EXPECT_FLOAT_EQ(child->getLocalPosition().x, 6.0f);
    EXPECT_FLOAT_EQ(child->getLocalPosition().y, -1.0f);
}

TEST_F(CORE_Node2D, SetLocalScaleUpdatesGlobalAndChildren) {
    const Vec2f newScale{2.0f, 3.0f};
    child->setLocalScale({1.5f, 0.5f});

    parent.setLocalScale(newScale);

    EXPECT_FLOAT_EQ(parent.getLocalScale().x, newScale.x);
    EXPECT_FLOAT_EQ(parent.getLocalScale().y, newScale.y);
    EXPECT_FLOAT_EQ(parent.getGlobalScale().x, newScale.x);
    EXPECT_FLOAT_EQ(parent.getGlobalScale().y, newScale.y);

    ASSERT_NE(child, nullptr);
    EXPECT_FLOAT_EQ(child->getLocalScale().x, 3.0f);
    EXPECT_FLOAT_EQ(child->getLocalScale().y, 1.5f);
    EXPECT_FLOAT_EQ(child->getGlobalScale().x, 3.0f);
    EXPECT_FLOAT_EQ(child->getGlobalScale().y, 1.5f);
}

TEST_F(CORE_Node2D, SetGlobalRotationPropagatesToChild) {
    constexpr double rotation = 45.0;
    child->setLocalRotation(10.0);

    parent.setGlobalRotation(rotation);

    EXPECT_DOUBLE_EQ(parent.getGlobalRotation(), rotation);
    EXPECT_DOUBLE_EQ(parent.getLocalRotation(), rotation);

    ASSERT_NE(child, nullptr);
    EXPECT_DOUBLE_EQ(child->getGlobalRotation(), 55.0);
    EXPECT_DOUBLE_EQ(child->getLocalRotation(), 55.0);
}

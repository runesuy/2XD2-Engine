// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by runes on 14/12/2025.
//

#include "2XD2/core/Vec2f.h"

#include <gtest/gtest.h>

TEST(CORE_Vec2, Constructor_Default) {
    e2XD::core::Vec2f vec;
    ASSERT_EQ(vec.x, 0.0);
    ASSERT_EQ(vec.y, 0.0);
}

TEST(CORE_Vec2, Constructor_Parameterized) {
    const e2XD::core::Vec2f vec(3.5, -2.1);
    ASSERT_NEAR(vec.x, 3.5, 0.0001);
    ASSERT_NEAR(vec.y, -2.1, 0.0001);
}

TEST(CORE_Vec2, Addition) {
    const e2XD::core::Vec2f vec1(1.0, 2.0);
    const e2XD::core::Vec2f vec2(3.0, 4.0);
    const e2XD::core::Vec2f result = vec1 + vec2;
    ASSERT_NEAR(result.x, 4.0, 0.0001);
    ASSERT_NEAR(result.y, 6.0, 0.0001);
}

TEST(CORE_Vec2, Subtraction) {
    const e2XD::core::Vec2f vec1(5.0, 7.0);
    const e2XD::core::Vec2f vec2(2.0, 3.0);
    const e2XD::core::Vec2f result = vec1 - vec2;
    ASSERT_NEAR(result.x, 3.0, 0.0001);
    ASSERT_NEAR(result.y, 4.0, 0.0001);
}

TEST(CORE_Vec2, ScalarMultiplication) {
    const e2XD::core::Vec2f vec(2.0, 3.0);
    const double scalar = 4.0;
    const e2XD::core::Vec2f result = vec * scalar;
    ASSERT_NEAR(result.x, 8.0, 0.0001);
    ASSERT_NEAR(result.y, 12.0, 0.0001);
}

TEST(CORE_Vec2, DotProduct) {
    const e2XD::core::Vec2f vec1(1.0, 2.0);
    const e2XD::core::Vec2f vec2(3.0, 4.0);
    const double result = vec1.dot(vec2);
    ASSERT_NEAR(result, 11.0, 0.0001); // 1*3 + 2*4 = 3 + 8 = 11
}

TEST(CORE_Vec2, Length) {
    const e2XD::core::Vec2f vec(3.0, 4.0);
    const double length = vec.length();
    ASSERT_NEAR(length, 5.0, 0.0001); // sqrt(3^2 + 4^2) = sqrt(9 + 16) = sqrt(25) = 5
}

TEST(CORE_Vec2, CompoundAssignment) {
    e2XD::core::Vec2f vec(1.0, 1.0);
    vec += e2XD::core::Vec2f(2.0, 3.0);
    ASSERT_NEAR(vec.x, 3.0, 0.0001);
    ASSERT_NEAR(vec.y, 4.0, 0.0001);

    vec -= e2XD::core::Vec2f(1.0, 1.0);
    ASSERT_NEAR(vec.x, 2.0, 0.0001);
    ASSERT_NEAR(vec.y, 3.0, 0.0001);

    vec *= 2.0;
    ASSERT_NEAR(vec.x, 4.0, 0.0001);
    ASSERT_NEAR(vec.y, 6.0, 0.0001);

    vec /= 2.0;
    ASSERT_NEAR(vec.x, 2.0, 0.0001);
    ASSERT_NEAR(vec.y, 3.0, 0.0001);
}

TEST(CORE_Vec2, Equality) {
    const e2XD::core::Vec2f vec1(1.0, 2.0);
    const e2XD::core::Vec2f vec2(1.0, 2.0);
    const e2XD::core::Vec2f vec3(2.0, 3.0);
    ASSERT_TRUE(vec1 == vec2);
    ASSERT_FALSE(vec1 == vec3);
}


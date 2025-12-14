//
// Created by runes on 14/12/2025.
//

#include "core/Vec2.h"

#include <gtest/gtest.h>

TEST(CORE_Vec2, Constructor_Default) {
    e2XD::core::Vec2 vec;
    ASSERT_EQ(vec.x, 0.0);
    ASSERT_EQ(vec.y, 0.0);
}

TEST(CORE_Vec2, Constructor_Parameterized) {
    const e2XD::core::Vec2 vec(3.5, -2.1);
    ASSERT_EQ(vec.x, 3.5);
    ASSERT_EQ(vec.y, -2.1);
}

TEST(CORE_Vec2, Addition) {
    const e2XD::core::Vec2 vec1(1.0, 2.0);
    const e2XD::core::Vec2 vec2(3.0, 4.0);
    const e2XD::core::Vec2 result = vec1 + vec2;
    ASSERT_EQ(result.x, 4.0);
    ASSERT_EQ(result.y, 6.0);
}

TEST(CORE_Vec2, Subtraction) {
    const e2XD::core::Vec2 vec1(5.0, 7.0);
    const e2XD::core::Vec2 vec2(2.0, 3.0);
    const e2XD::core::Vec2 result = vec1 - vec2;
    ASSERT_EQ(result.x, 3.0);
    ASSERT_EQ(result.y, 4.0);
}

TEST(CORE_Vec2, ScalarMultiplication) {
    const e2XD::core::Vec2 vec(2.0, 3.0);
    const double scalar = 4.0;
    const e2XD::core::Vec2 result = vec * scalar;
    ASSERT_EQ(result.x, 8.0);
    ASSERT_EQ(result.y, 12.0);
}

TEST(CORE_Vec2, DotProduct) {
    const e2XD::core::Vec2 vec1(1.0, 2.0);
    const e2XD::core::Vec2 vec2(3.0, 4.0);
    const double result = vec1.dot(vec2);
    ASSERT_EQ(result, 11.0); // 1*3 + 2*4 = 3 + 8 = 11
}

TEST(CORE_Vec2, Length) {
    const e2XD::core::Vec2 vec(3.0, 4.0);
    const double length = vec.length();
    ASSERT_EQ(length, 5.0); // sqrt(3^2 + 4^2) = sqrt(9 + 16) = sqrt(25) = 5
}

TEST(CORE_Vec2, CompoundAssignment) {
    e2XD::core::Vec2 vec(1.0, 1.0);
    vec += e2XD::core::Vec2(2.0, 3.0);
    ASSERT_EQ(vec.x, 3.0);
    ASSERT_EQ(vec.y, 4.0);

    vec -= e2XD::core::Vec2(1.0, 1.0);
    ASSERT_EQ(vec.x, 2.0);
    ASSERT_EQ(vec.y, 3.0);

    vec *= 2.0;
    ASSERT_EQ(vec.x, 4.0);
    ASSERT_EQ(vec.y, 6.0);

    vec /= 2.0;
    ASSERT_EQ(vec.x, 2.0);
    ASSERT_EQ(vec.y, 3.0);
}

TEST(CORE_Vec2, Equality) {
    const e2XD::core::Vec2 vec1(1.0, 2.0);
    const e2XD::core::Vec2 vec2(1.0, 2.0);
    const e2XD::core::Vec2 vec3(2.0, 3.0);
    ASSERT_TRUE(vec1 == vec2);
    ASSERT_FALSE(vec1 == vec3);
}


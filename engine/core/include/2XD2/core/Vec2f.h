//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_VEC2_H
#define INC_2XD2_ENGINE_VEC2_H

namespace e2XD::framework
{
    /**
     * Defines a 2D vector with x and y float components.
     */
    struct Vec2f
    {
        float x = 0;
        float y = 0;

        /**
         * Defaults to (0,0)
         */
        Vec2f() = default;
        // TEST: Core_Vec2.Constructor_Default

        /**
         *
         * @param x
         * @param y
         */
        Vec2f(float x, float y);
        // TEST: Core_Vec2.Constructor_Parameterized


        Vec2f(const Vec2f&) = default;

        Vec2f& operator=(const Vec2f&) = default;

        Vec2f operator+(const Vec2f& vector) const;
        // TEST: Core_Vec2.Addition

        Vec2f operator-(const Vec2f& vector) const;
        // TEST: Core_Vec2.Subtraction

        Vec2f operator*(float scalar) const;
        // TEST: Core_Vec2.ScalarMultiplication

        Vec2f operator/(float scalar) const;
        // TEST: Core_Vec2.ScalarDivision

        Vec2f operator/(const Vec2f& vector) const;

        Vec2f operator*(const Vec2f& vector) const;

        bool operator==(const Vec2f&) const = default;

        Vec2f& operator+=(const Vec2f& vector);
        // TEST: Core_Vec2.CompoundAssignment

        Vec2f& operator-=(const Vec2f& vector);
        // TEST: Core_Vec2.CompoundAssignment

        Vec2f& operator*=(float scalar);
        // TEST: Core_Vec2.CompoundAssignment

        Vec2f& operator/=(float scalar);
        // TEST: Core_Vec2.CompoundAssignment

        [[nodiscard]] float dot(const Vec2f& vector) const;
        // TEST: Core_Vec2.DotProduct

        [[nodiscard]] float length() const;
        // TEST: Core_Vec2.Length

        void normalize();
    };
}


#endif //INC_2XD2_ENGINE_VEC2_H

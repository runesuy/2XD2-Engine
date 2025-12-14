//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_VEC2_H
#define INC_2XD2_ENGINE_VEC2_H

namespace e2XD::core {
    struct Vec2 {
        double x;
        double y;

        /**
         * Defaults to (0,0)
         */
        Vec2();
        // TEST: Core_Vec2.Constructor_Default

        /**
         *
         * @param x
         * @param y
         */
        Vec2(double x, double y);
        // TEST: Core_Vec2.Constructor_Parameterized


        Vec2(const Vec2 &) = default;

        Vec2 &operator=(const Vec2 &) = default;

        Vec2 operator+(const Vec2 &vector) const;
        // TEST: Core_Vec2.Addition

        Vec2 operator-(const Vec2 &vector) const;
        // TEST: Core_Vec2.Subtraction

        Vec2 operator*(double scalar) const;
        // TEST: Core_Vec2.ScalarMultiplication

        Vec2 operator/(double scalar) const;
        // TEST: Core_Vec2.ScalarDivision

        bool operator==(const Vec2 &) const = default;

        Vec2 &operator+=(const Vec2 &vector);
        // TEST: Core_Vec2.CompoundAssignment

        Vec2 &operator-=(const Vec2 &vector);
        // TEST: Core_Vec2.CompoundAssignment

        Vec2 &operator*=(double scalar);
        // TEST: Core_Vec2.CompoundAssignment

        Vec2 &operator/=(double scalar);
        // TEST: Core_Vec2.CompoundAssignment

        double dot(const Vec2 &vector) const;
        // TEST: Core_Vec2.DotProduct

        [[nodiscard]] double length() const;
        // TEST: Core_Vec2.Length
    };
}


#endif //INC_2XD2_ENGINE_VEC2_H

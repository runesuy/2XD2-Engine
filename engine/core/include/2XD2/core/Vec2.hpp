// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_VEC2_H
#define INC_2XD2_ENGINE_VEC2_H
#include "cmath"

namespace e2XD::core
{
    /**
     * Defines a 2D vector with x and y T components.
     */
    template<typename T>
    struct Vec2
    {
        T x = 0;
        T y = 0;

        /**
         * Defaults to (0,0)
         */
        Vec2() = default;
        // TEST: Core_Vec2.Constructor_Default

        /**
         *
         * @param x
         * @param y
         */
        Vec2(T x, T y);
        // TEST: Core_Vec2.Constructor_Parameterized


        Vec2(const Vec2&) = default;

        Vec2& operator=(const Vec2&) = default;

        Vec2 operator+(const Vec2& vector) const;
        // TEST: Core_Vec2.Addition

        Vec2 operator-(const Vec2& vector) const;
        // TEST: Core_Vec2.Subtraction

        Vec2 operator*(T scalar) const;
        // TEST: Core_Vec2.ScalarMultiplication

        Vec2 operator/(T scalar) const;
        // TEST: Core_Vec2.ScalarDivision

        Vec2 operator/(const Vec2& vector) const;

        Vec2 operator*(const Vec2& vector) const;

        bool operator==(const Vec2&) const = default;

        Vec2& operator+=(const Vec2& vector);
        // TEST: Core_Vec2.CompoundAssignment

        Vec2& operator-=(const Vec2& vector);
        // TEST: Core_Vec2.CompoundAssignment

        Vec2& operator*=(T scalar);
        // TEST: Core_Vec2.CompoundAssignment

        Vec2& operator/=(T scalar);
        // TEST: Core_Vec2.CompoundAssignment

        [[nodiscard]] T dot(const Vec2& vector) const;
        // TEST: Core_Vec2.DotProduct

        [[nodiscard]] T length() const;
        // TEST: Core_Vec2.Length

        void normalize();
    };

    template <typename T>
    Vec2<T>::Vec2(const T x, const T y) : x(x), y(y)
    {
    }

    template <typename T>
    T Vec2<T>::length() const
    {
        return std::sqrt(x * x + y * y);
    }

    template <typename T>
    Vec2<T> Vec2<T>::operator*(T scalar) const
    {
        return {x * scalar, y * scalar};
    }

    template <typename T>
    Vec2<T> Vec2<T>::operator+(const Vec2& vector) const
    {
        return {x + vector.x, y + vector.y};
    }

    template <typename T>
    Vec2<T> Vec2<T>::operator-(const Vec2& vector) const
    {
        return {x - vector.x, y - vector.y};
    }

    template <typename T>
    Vec2<T> Vec2<T>::operator/(const T scalar) const
    {
        return {x / scalar, y / scalar};
    }

    template <typename T>
    Vec2<T>& Vec2<T>::operator*=(const T scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    template <typename T>
    Vec2<T>& Vec2<T>::operator+=(const Vec2& vector)
    {
        x += vector.x;
        y += vector.y;
        return *this;
    }

    template <typename T>
    Vec2<T>& Vec2<T>::operator-=(const Vec2& vector)
    {
        x -= vector.x;
        y -= vector.y;
        return *this;
    }

    template <typename T>
    Vec2<T>& Vec2<T>::operator/=(const T scalar)
    {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    template <typename T>
    T Vec2<T>::dot(const Vec2& vector) const
    {
        return x * vector.x + y * vector.y;
    }

    template <typename T>
    Vec2<T> Vec2<T>::operator/(const Vec2& vector) const
    {
        return {x / vector.x, y / vector.y};
    }

    template <typename T>
    Vec2<T> Vec2<T>::operator*(const Vec2& vector) const
    {
        return {x * vector.x, y * vector.y};
    }

    template <typename T>
    void Vec2<T>::normalize()
    {
        T l = length();
        if (l == 0) return;
        *this /= l;
    }
}


#endif //INC_2XD2_ENGINE_VEC2_H

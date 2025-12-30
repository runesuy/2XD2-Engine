//
// Created by runes on 14/12/2025.
//

#include "2XD2/core/Vec2f.h"
#include <cmath>

namespace e2XD::framework
{
    Vec2f::Vec2f(const float x, const float y) : x(x), y(y)
    {
    }

    float Vec2f::length() const
    {
        return std::sqrt(x * x + y * y);
    }

    Vec2f Vec2f::operator*(float scalar) const
    {
        return {x * scalar, y * scalar};
    }

    Vec2f Vec2f::operator+(const Vec2f& vector) const
    {
        return {x + vector.x, y + vector.y};
    }

    Vec2f Vec2f::operator-(const Vec2f& vector) const
    {
        return {x - vector.x, y - vector.y};
    }

    Vec2f Vec2f::operator/(const float scalar) const
    {
        return {x / scalar, y / scalar};
    }

    Vec2f& Vec2f::operator*=(const float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vec2f& Vec2f::operator+=(const Vec2f& vector)
    {
        x += vector.x;
        y += vector.y;
        return *this;
    }

    Vec2f& Vec2f::operator-=(const Vec2f& vector)
    {
        x -= vector.x;
        y -= vector.y;
        return *this;
    }

    Vec2f& Vec2f::operator/=(const float scalar)
    {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    float Vec2f::dot(const Vec2f& vector) const
    {
        return x * vector.x + y * vector.y;
    }

    Vec2f Vec2f::operator/(const Vec2f& vector) const
    {
        return {x / vector.x, y / vector.y};
    }

    Vec2f Vec2f::operator*(const Vec2f& vector) const
    {
        return {x * vector.x, y * vector.y};
    }

    void Vec2f::normalize()
    {
        float l = length();
        if (l == 0) return;
        *this /= l;
    }
} // e2XD
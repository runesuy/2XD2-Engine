//
// Created by runes on 14/12/2025.
//

#include "2XD2/core/Vec2.h"
#include <cmath>

namespace e2XD::core {
    Vec2::Vec2(const float x, const float y) : x(x), y(y) {}

    float Vec2::length() const {
        return std::sqrt(x * x + y * y);
    }

    Vec2 Vec2::operator*(float scalar) const {
        return {x*scalar, y*scalar};
    }

    Vec2 Vec2::operator+(const Vec2 &vector) const {
        return {x + vector.x, y + vector.y};
    }

    Vec2 Vec2::operator-(const Vec2 &vector) const {
        return {x - vector.x, y - vector.y};
    }

    Vec2 Vec2::operator/(const float scalar) const {
        return {x / scalar, y / scalar};
    }

    Vec2 &Vec2::operator*=(const float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vec2 &Vec2::operator+=(const Vec2 &vector) {
        x += vector.x;
        y += vector.y;
        return *this;
    }

    Vec2 &Vec2::operator-=(const Vec2 &vector) {
        x -= vector.x;
        y -= vector.y;
        return *this;
    }

    Vec2 &Vec2::operator/=(const float scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    float Vec2::dot(const Vec2 &vector) const {
        return x * vector.x + y * vector.y;
    }

    Vec2 Vec2::operator/(const Vec2 &vector) const {
        return {x / vector.x, y / vector.y};
    }

    Vec2 Vec2::operator*(const Vec2 &vector) const {
        return {x * vector.x, y * vector.y};
    }

    void Vec2::normalize()
    {
        float l = length();
        if (l== 0) return;
        *this/=l;
    }

} // e2XD
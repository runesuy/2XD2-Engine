//
// Created by runes on 14/12/2025.
//

#include "core/Vec2.h"
#include <cmath>

namespace e2XD::core {
    Vec2::Vec2() : x(0.0), y(0.0) {}
    Vec2::Vec2(const double x, const double y) : x(x), y(y) {}

    double Vec2::length() const {
        return std::sqrt(x * x + y * y);
    }

    Vec2 Vec2::operator*(double scalar) const {
        return {x*scalar, y*scalar};
    }

    Vec2 Vec2::operator+(const Vec2 &vector) const {
        return {x + vector.x, y + vector.y};
    }

    Vec2 Vec2::operator-(const Vec2 &vector) const {
        return {x - vector.x, y - vector.y};
    }

    Vec2 Vec2::operator/(double scalar) const {
        return {x / scalar, y / scalar};
    }

    Vec2 &Vec2::operator*=(double scalar) {
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

    Vec2 &Vec2::operator/=(double scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    double Vec2::dot(const Vec2 &vector) const {
        return x * vector.x + y * vector.y;
    }
} // e2XD
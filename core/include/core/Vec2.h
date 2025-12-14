//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_VEC2_H
#define INC_2XD2_ENGINE_VEC2_H

namespace e2XD::core {
    struct Vec2 {
        double x;
        double y;

        Vec2() = default;

        Vec2(double x, double y);

        Vec2(const Vec2 &) = default;

        Vec2 &operator=(const Vec2 &) = default;

        Vec2 operator+(const Vec2 &vector) const;

        Vec2 operator-(const Vec2 &vector) const;

        Vec2 operator*(double scalar) const;

        Vec2 operator/(double scalar) const;

        bool operator==(const Vec2 &) const = default;

        Vec2 &operator+=(const Vec2 &vector);

        Vec2 &operator-=(const Vec2 &vector);

        Vec2 &operator*=(double scalar);

        Vec2 &operator/=(double scalar);

        [[nodiscard]] double length() const;
    };
}


#endif //INC_2XD2_ENGINE_VEC2_H

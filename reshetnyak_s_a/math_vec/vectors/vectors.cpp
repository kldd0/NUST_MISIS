#include "vectors.hpp"
#include <iostream>
#include <cmath>

Rdec2D operator+(const Rdec2D &lhs, const Rdec2D &rhs) {
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}

Rdec2D operator-(const Rdec2D &lhs, const Rdec2D &rhs) {
    return {lhs.x - rhs.x, lhs.y - rhs.y};
}

Rdec2D operator*(const Rdec2D &vec, int s) {
    return {vec.x * s, vec.y * s};
}

double dot(const Rdec2D &lhs, const Rdec2D &rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

double norm(const Rdec2D &vec) {
    return std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2));
}

// transform

Rdec2D transform_to_Rdec2D(const Rpol2D &vec) {
    return {
        vec.r * std::cos(vec.phi),
        vec.r * std::sin(vec.phi)
    };
}

Rpol2D transform_to_Rpol2D(const Rdec2D &vec) {
    return {
        norm(vec),
        std::atan2(vec.y, vec.x)
    };
}

// Pol

Rpol2D operator+(const Rpol2D &lhs, const Rpol2D &rhs) {
    Rdec2D temp_lhs = transform_to_Rdec2D(lhs);
    Rdec2D temp_rhs = transform_to_Rdec2D(rhs);
    Rdec2D res = temp_lhs + temp_rhs;
    return transform_to_Rpol2D(res);
}

Rpol2D operator-(const Rpol2D &lhs, const Rpol2D &rhs) {
    Rdec2D temp_lhs = transform_to_Rdec2D(lhs);
    Rdec2D temp_rhs = transform_to_Rdec2D(rhs);
    Rdec2D res = temp_lhs - temp_rhs;
    return transform_to_Rpol2D(res);
}

Rpol2D operator*(const Rpol2D &vec, int s) {
    Rdec2D temp_vec = transform_to_Rdec2D(vec);
    Rdec2D res = temp_vec * s;
    return transform_to_Rpol2D(res);
}

double dot(Rpol2D &lhs, Rpol2D &rhs) {
    Rdec2D temp_lhs = transform_to_Rdec2D(lhs);
    Rdec2D temp_rhs = transform_to_Rdec2D(rhs);
    return dot(temp_lhs, temp_rhs);
}

// Output


// Dec

std::ostream& operator<<(std::ostream& ostrm, const Rdec2D& vec) {
    return ostrm << "(" << vec.x << ", " << vec.y << ")";
}

// Pol

std::ostream& operator<<(std::ostream& ostrm, const Rpol2D& vec) {
    return ostrm << "(" << vec.r << ", " << vec.phi << ")";
}
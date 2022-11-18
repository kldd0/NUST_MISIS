#include <iostream>
#include <cmath>
// #include <numbers>

struct Rdec2D {
    double x = 0.0;
    double y = 0.0;
};

struct Rpol2D {
    double r = 0.0;
    double phi = 0.0;
};

Rdec2D operator+(const Rdec2D &lhs, const Rdec2D &rhs) {
    return Rdec2D({lhs.x + rhs.x, lhs.y + rhs.y});
}

Rdec2D operator-(const Rdec2D &lhs, const Rdec2D &rhs) {
    return Rdec2D({lhs.x - rhs.x, lhs.y - rhs.y});
}

Rdec2D operator*(const Rdec2D &vec, int s) {
    return Rdec2D({vec.x * s, vec.y * s});
}

double dot(const Rdec2D &lhs, const Rdec2D &rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

double norm(const Rdec2D &vec) {
    return std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2));
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

// transform

Rdec2D transform_to_Rdec2D(const Rpol2D &vec) {
    return Rdec2D({
        vec.r * std::cos(vec.phi),
        vec.r * std::sin(vec.phi)
    });
}

Rpol2D transform_to_Rpol2D(const Rdec2D &vec) {
    return Rpol2D({
        norm(vec),
        std::atan2(vec.y, vec.x)
    });
}


int main() {
    Rdec2D a = {3.0, 5.0};
    Rdec2D b = {4.2, 7.1};

    Rdec2D res_plus = a + b;
    std::cout << res_plus.x << " " << res_plus.y << "\n";

    Rdec2D res_minus = a - b;
    std::cout << res_minus.x << " " << res_minus.y << "\n";

    Rdec2D res_sc = b * 2;
    std::cout << res_sc.x << " " << res_sc.y << "\n";
    
    double res_dot = dot(a, b);
    std::cout << res_dot << "\n";

    Rpol2D res_pol = transform_to_Rpol2D(b);
    std::cout << res_pol.r << " " << res_pol.phi << "\n";

    // Rpol2D apol = {12.0, std::pi};
    // std::cout << res.x << " " << res.y << "\n";
    return 0;
}
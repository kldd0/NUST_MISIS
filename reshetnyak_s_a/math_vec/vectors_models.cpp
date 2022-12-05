#include <iostream>
#include <vectors/vectors.hpp>
#include "vectors_models.hpp"
#include <limits>

const double rA = 0.5;

bool coordEq(Rdec2D &r_c, Rdec2D &r_m) {
    return std::abs(r_c.x - r_m.x) < 2 * rA && std::abs(r_c.y - r_m.y) < 2 * rA;
}

bool coordEqTo0(Rdec2D &vec) {
    return std::abs(vec.x) < 2 * rA && std::abs(vec.y) < 2 * rA;
}

Rdec2D speed(Rdec2D &r_c, Rdec2D &r_m, double v0) {
    Rdec2D dv = r_m - r_c;
    return (dv * (1 / Norm(dv))) * v0;
}

Rdec2D attend(Rdec2D r_c, Rdec2D r_m, Rdec2D v_m, double v_c0, double dt, double limit) {
    while (r_m.y < limit) {
        // counting vec speed of cat
        Rdec2D v_c = speed(r_c, r_m, v_c0);
        std::cout << "new spd cat (v_c): " << v_c << "\n";
        
        r_c = r_c + v_c * dt; // new pos cat
        r_m = r_m + v_m * dt; // new pos mouse

        std::cout << "new pos cat (r_c): " << r_c << "\n";
        std::cout << "new pos mse (r_m): " << r_m << "\n";
        std::cout << "-------" << "\n";

        if (coordEq(r_c, r_m)) {
            return r_c;
        }
    }
    return {0.0, limit};
}


void CatchUpModel() {
    std::cout << "qwer" << "\n";
    // initial coordinates of cat and mouse (radius vectors)
    Rdec2D r_c = {10.0, 0.0};
    Rdec2D r_m = {0.0, -7.0};

    // speed of mouse
    Rdec2D v_m = {0, 1.0};

    bool f = true;

    double limit = 100;

    double v_c0 = v_m.y;
    double v_c1 = v_c0 + 5;
    int i = 0;
    while (f) {
        // speed of cat
        double v = (v_c0 + v_c1) / 2;

        std::cout << "attemp for v = " << v << "\n";
        // time
        double dt = 1;

        Rdec2D res = attend(r_c, r_m, v_m, v, dt, limit);

        if (coordEqTo0(res)) {
            f = false;
            std::cout << "v = " << v << "\n";
        }

        if (res.y < 0) {
            v_c0 -= 0.025;
            v_c1 = v;
        } else {
            v_c0 = v;
            v_c1 += 0.025;
        }
        i += 1;
        if (i == 3) break;
    }
}


// void GravitationalModel() {

// }
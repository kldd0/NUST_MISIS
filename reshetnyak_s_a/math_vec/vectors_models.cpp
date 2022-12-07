#include <iostream>
#include <vectors/vectors.hpp>
#include "vectors_models.hpp"
#include <limits>
#include <fstream>

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

void TableInit(std::ofstream& outstrm) {
    outstrm << "n" << "," << "t" << "," << "x" << "," << "y" << "," 
        << "vx" << "," << "vy" << "," << "rx" << "," << "ry" << "\n";
}

void WriteInTable(std::ofstream& outstrm, int n, double t, Rdec2D& pos, Rdec2D& velocity, Rdec2D& r) {
    outstrm << n << "," << t << "," << pos.x << "," << pos.y << "," << velocity.x << "," \
        << "," << velocity.y << "," << r.x << "," << r.y << "\n";
};

void GravitationalModel() {
    std::ofstream outstrm;
    outstrm.open("data_out.csv", std::ios::out);
    TableInit(outstrm);
    // F = G * (m * M) / r^2

    // const double K = 2 ;//* 1e10; // m * M
    const double G = 6.67 ;//* 1e-11; // G

    Rdec2D r_pos_dec =  {2.3, 3.0};
    Rdec2D r_velocity = {4.2, -1.2}; // circle
    // Rdec2D r_velocity = {12.2, 0.2}; // circle


    // counting vec[r] F
    double r_norm = Norm(r_pos_dec);
    Rdec2D r_f = r_pos_dec * (1 / (r_norm * r_norm * r_norm)) * G * (-1); // vec[r] of F

    double dt = 0.1;

    Rdec2D new_pos = r_pos_dec;

    std::cout << r_pos_dec << "," << r_velocity << "," << r_f << "\n";

    int i = 1;
    while (i <= 1000) {
        // vector of speed
        r_velocity = r_velocity + r_f * dt;

        // update new positions in Rdec2D
        new_pos = new_pos + r_velocity * dt;

        // update F
        double r_nw_pos_norm = Norm(new_pos);
        r_f = new_pos * (1 / (r_nw_pos_norm * r_nw_pos_norm * r_nw_pos_norm)) * G * (-1);

        // out in table
        WriteInTable(outstrm, i, dt, new_pos, r_velocity, r_f);

        // out in stream
        std::cout << new_pos << ",";

        // // gain delta angles
        // Rpol2D r_velocity_pol = transform_to_Rpol2D(r_velocity);
        // Rpol2D r_new_pos_pol = transform_to_Rpol2D(new_pos);
        
        // // update new angles
        // r_norm = Norm(new_pos);
        // r_f = r_pos_dec * (1 / (r_norm * r_norm * r_norm)) * G * (-1);
        // r_velocity_pol.phi += dq_phi;

        // // update pos
        // nr_vec = r_f + r_velocity;
        // new_pos = new_pos + nr_vec;

        // // return to Rdec2D
        // r_velocity = transform_to_Rdec2D(r_velocity_pol);

        // // update phi
        // dq_phi =  std::abs(new_pos_phi - s_pos_phi);

        // update time
        // dt += 0.01;
        i += 1;
    }
    outstrm.close();
}
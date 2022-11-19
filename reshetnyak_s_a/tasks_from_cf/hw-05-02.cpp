#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

// #define M_PI       3.14159265358979323846

double s(double x, int i) {
    return pow(x, i) * sin(i * M_PI);
}

double y(double x, int i) {
    return (x * sin(M_PI / 4)) / (1 - 2 * x * cos(M_PI / 4));
}

int main() {
    int a = 0, b = 1;
    double delta = 0.05, eps = 10e-3;
    double y_x, s_x, sm;
    // std::vector<double> a;
    std::cout << std::setprecision(5);
    std::cout << "x" << " | " << "s(x)" << " | " << "f(x)" << "\n";
    for (double x = a; x <= b; x += delta) {
        int i = 1;
        y_x = y(x, i);
        s_x = s(x, i);
        std::cout << s_x << " " << y_x << "\n";
        while (std::abs(s_x) >= eps) {
            sm += s_x;
            std::cout << x << " " << s_x << " " << y_x << "\n";
            ++i;
            s_x = s(x, i);
            y_x = y(x, i);
        }
    }
    return 0;
}
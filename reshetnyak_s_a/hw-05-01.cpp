#include <iostream>
#include <cmath>
#include <iomanip>

long long fact(long long a) {
    long long r = 1;
    for (long long i = 2; i <= a; ++i) {
        r *= i;
    }
    return r;
}

int main() {
    int a = -1, b = 1;
    double delta = 0.1, eps = 10e-3;
    double y_x, s_x, s;
    std::cout << std::setprecision(5);
    std::cout << "x" << " | " << "s(x)" << " | " << "f(x)" << "\n";
    for (double x = a; x <= b; x += delta) {
        y_x = cos(x);
        int i = 0;
        s_x = pow(-1, i) *  pow(x, 2 * i) / fact(2 * i);
        while (std::abs(s_x) >= eps) {
            s += s_x;
            std::cout << x << " " << s_x << " " << y_x << "\n";
            i += 1;
            s_x = pow(-1, i) *  pow(x, 2 * i) / fact(2 * i);
            y_x = cos(x);
        }
    }
    return 0;
}
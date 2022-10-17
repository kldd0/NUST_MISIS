#include <iostream>
#include <cmath>
#include <iomanip>

#define M_PI       3.14159265358979323846

int main() {
    int n, r;
    std::cin >> n >> r;
    double _alpha = M_PI / n;
    double R = (sin(_alpha) * r) / (1 - sin(_alpha));
    std::cout << std::setprecision(10);
    std::cout << R << "\n";
    return 0;
}
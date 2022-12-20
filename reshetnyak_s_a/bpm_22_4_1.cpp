#include <iostream>
#include <cmath>

const double eps = 0.001;

long long factorial(int k) {
    long long res = 1;
    if (k > 0) {
        for (int i = 2; i <= k; ++i) {
            res *= i;
        }
    }
    return res;
}

double sum(double x) {
    double prev = 0;
    int i = 0;
    double sm = 0;
    double ch = std::pow(x, 2 * i);
    long long del = factorial(2 * i);
    double dr = ch / del;
    while (std::abs(dr - prev) > eps) {
        sm += dr;
        prev = dr;
        i += 1;
        double ch = std::pow(x, 2 * i);
        long long del = factorial(2 * i);
        dr = ch / del;
    }
    return sm;
}

int main() {
    double x = 0.1;
    double dx = 0.05;
    while (x <= 1) {
        std::cout << x << " " << sum(x) << "\n";
        x += dx;
    }
    return 0;
}
#include <iostream>
#include <utility>
#include <vector>
#include <iomanip>

bool check(double x, double y) {
    return ((x * x) + (y * y) <= 1) && ((y >= x + 1) || (y <= x - 1));
}

int main() {
    double x, y;
    std::vector<std::pair<double, double>> points;
    while (std::cin >> x >> y) {
        points.push_back({x, y});
    }
    long long n = points.size();
    long cnt = 0;
    for (auto e : points) {
        if (check(e.first, e.second)) ++cnt; 
    }
    std::cout << cnt << " " << n << "\n";
    std::cout << (double)(cnt / n) << "\n";
    return 0;
}
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t) {
        --t;
        int n, m, sx, sy, d;
        std::cin >> n >> m >> sx >> sy >> d;
        if ((std::abs(0 - (sx - 1)) > d) && (std::abs(m - sy) > d)) std::cout << n + m - 2 << "\n";
        else if ((std::abs(0 - (sy - 1)) > d) && (std::abs(n - sx) > d)) std::cout << n + m - 2 << "\n";
        else std::cout << -1 << "\n";
    }
    return 0;
}
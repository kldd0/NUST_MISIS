#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    int x = 0, y = 0;
    int r = 0;
    std::string p;
    std::cin >> p;
    int px = 0, py = 0;
    for (auto e : p) {
        int xo = x, yo = y;
        if (e == 'U') y += 1;
        if (e == 'R') x += 1;
        if (y - x == 0) px = xo, py = yo;
        if (yo - xo == 0 && ((py - px > 0 && y - x < 0) || (py - px < 0 && y - x > 0))) r += 1;
    }
    std::cout << r << "\n";
    return 0;
}
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
        // if ((yo - xo > 0 && y - x < 0) || (yo - xo < 0 && y - x > 0)) r += 1;
        // std::cout << x << " " << y << " " << yo - xo << " " << y - x << " " << r << "\n";
        if (yo - xo == 0 && ) r += 1;
        std::cout << x << " " << y << "\n";
    }
    std::cout << r << "\n";
    return 0;
}
#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) std::cout << 1 << " ";
                else std::cout << 0 << " ";
            }
            std::cout << "\n";
        }
    }
    return 0;
}
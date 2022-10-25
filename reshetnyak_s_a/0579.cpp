#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int c = 0;
    while (n > 0) {
        c += (n & 1);
        n >>= 1;
    }
    std::cout << c << "\n";
    return 0;
}
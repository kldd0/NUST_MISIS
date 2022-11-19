#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    std::vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        int ind;
        std::cin >> ind;
        r[ind - 1] = i + 1;
    }
    for (int e : r) std::cout << e << " ";
    return 0;
}
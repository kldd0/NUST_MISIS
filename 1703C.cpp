// https://codeforces.com/problemset/problem/1703/C
#include <iostream>
#include <vector>

int main() {
    int t, n, k;
    std::cin >> t;
    while (t) {
        --t;
        std::cin >> n;
        std::vector<int> a(n);  
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < n; ++i) {
            std::cin >> k;
            for (int j = 0; j < k; ++j) {
                char el;
                std::cin >> el;
                if (el == 'D') a[i] = (a[i] + 1) % 10;
                else {
                    if (a[i] - 1 < 0) a[i] = (10 + a[i] - 1) % 10;
                    else a[i] = (a[i] - 1) % 10;
                }
            }
        }
        for (auto el : a) std::cout << el << " ";
        std::cout << "\n";
    }
    return 0;
}
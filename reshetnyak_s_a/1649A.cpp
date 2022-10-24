#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        int r = 0;
        int ind = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i]) {
                r += i - ind;
                ind = i;
            }
        }
        std::cout << r << "\n";
    }
    return 0;
}
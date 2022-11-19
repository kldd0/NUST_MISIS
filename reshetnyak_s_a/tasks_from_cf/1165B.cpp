#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::sort(a.begin(), a.end());
    int c = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] <= a[i + 1] && a[i + 1] > c) ++c;
    }
    std::cout << c << "\n";
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::string s;
        std::cin >> n >> k;
        std::cin >> s;
        std::vector<int> ps(n + 1);
        ps[0] = 0;
        for (int i = 1; i <= n; ++i) {
            ps[i] = ps[i - 1];
            if (s[i - 1] == 'W') ps[i] += 1;
        }
        int mn = 10000000;
        for (int i = k; i <= n; ++i) {
            if (ps[i] - ps[i - k] < mn) mn = ps[i] - ps[i - k];
        }
        std::cout << mn << "\n";
    }
    return 0;
}
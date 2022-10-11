#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        int d = 1;
        std::cin >> n;
        std::vector<int> a(n);
        bool f = true;
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        if (n > 1) {
            for (int i = 0; i < n; ++i) {
                if (i && a[i]) {
                    if (a[i - 1]) {
                        d += 5;
                    } else ++d;
                } else if (i && !a[i]) {
                    if (!a[i - 1]) {
                        f = false;
                        break;
                    }
                } else {
                    if (a[i]) ++d;
                }
            }
            if (f) std::cout << d << "\n";
            else std::cout << -1 << "\n";
        } else {
            if (a[0]) std::cout << d + 1 << "\n";
            else std::cout << d << "\n";
        }
    }
    return 0;
}
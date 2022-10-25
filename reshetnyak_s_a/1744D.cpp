#include <iostream>
#include <vector>

int c_2(int n) {
    int c = 0;
    while (n % 2 == 0) {
        ++c;
        n /= 2;
    }
    return c;
}

const int MAXINT = 200001;
std::vector<int> cache(MAXINT, 1);

int s_2(int n) {
    // int s = 0;
    int ci = 0;
    while (cache[ci] * 2 < n) {
        ++ci;
        cache[ci] = cache[ci - 1] * 2;
    }
    return ci;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int c = 0;
        for (int i = 0; i < n; ++i) {
            int ai;
            std::cin >> ai;
            c += c_2(ai);
        }
        if (n - c == 0) {
            std::cout << 0 << "\n";
            continue;
        }
        if (n - c < s_2(n)) {
            std::cout << 1 << "\n";
        } else {
            int k = s_2(n);
            int i = cache[k];
            int nn = n;
            int c = 0;
            while (i > 0 && nn > 0) {
                int m = 3;
                while (m * i < n && nn > 0) {
                    nn -= i;
                    m += 2;
                    ++c;
                }
                --i;
            }
            if (nn > 0) std::cout << -1 << "\n";
            else std::cout << c << "\n";
        }
        
    }
    return 0;
}
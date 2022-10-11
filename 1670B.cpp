#include <iostream>
#include <string>
#include <vector>

int main() {
    int t, n, kn;
    std::cin >> t;
    while (t) {
        --t;
        std::string s;
        std::vector<int> k(290, 0);
        std::cin >> n >> s;
        std::cin >> kn;
        for (int i = 0; i < kn; ++i) {
            unsigned char el = 0;
            std::cin >> el;
            k[el] = 1;
        }
        int c = 0;
        for (unsigned char e : s) {
            if (k[e]) ++c;
        }
        if (c > 1) {
            int cnt = 0;
            int mx = 0;
            for (unsigned char e : s) {
                if (!k[e]) ++cnt;
                else cnt = 0;
                if (cnt > mx) mx = cnt;
            }
            std::cout << mx + 1 << "\n";
        } else if (c == 1) {
            int cnt = 0;
            int i = 0;
            while (!k[s[i]]) {
                ++cnt;
                ++i;
            }
            std::cout << cnt << "\n";
        } else {
            std::cout << 0 << "\n";
        }
    }
    return 0;
}
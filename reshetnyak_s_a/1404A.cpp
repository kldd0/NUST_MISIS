#include <iostream>
#include <string>
#include <vector>

int main() {
    int t, n, k;
    std::cin >> t;
    while (t) {
        --t;
        std::string s;
        std::cin >> n >> k;
        std::cin >> s;
        std::vector<char> res_s(n, '?');
        int a = 0, b = 0;
        for (int i = 0; i < k; ++i) {
            if (s[i] == '1') {
                ++a;
                res_s[i] = s[i];
            } else if (s[i] == '0') {
                ++b;
                res_s[i] = s[i];
            } else if (b >= a) {
                ++a;
                res_s[i] = '1';
            } else {
                ++b;
                res_s[i] = '0';
            }
        }
        for (auto e : res_s) std::cout << e << " ";
        std::cout << "\n";
        if (a != b) {
            std::cout << "NO" << "\n";
            continue;
        }
        bool f = true;
        for (int i = k; i < n; ++i) {
            std::cout << i << "\n";
            if (s[i] == '0' || res_s[i] == '0') {
                if (s[i - k] == '1' || res_s[i - k] == '1') {
                    ++b;
                    --a;
                }
            } else if (s[i] == '1' || res_s[i] == '1') {
                if (s[i - k] == '0' || res_s[i - k] == '0') {
                    --b;
                    ++a;
                }
            } else {
                if (s[i - k] != '?') res_s[i] = s[i - k];
                else res_s[i] = res_s[i - k];
            }
            if (a != b) {
                f = false;
                break;
            }
            for (auto e : res_s) std::cout << e << " ";
            std::cout << "\n";
        }
        if (f) std::cout << "YES" << "\n";
        else std::cout << "NO" << "\n";
    }
    return 0;
}
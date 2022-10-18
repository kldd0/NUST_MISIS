#include <iostream>

bool allq(std::string s) {
    for (auto e : s) if (e != '?') return false;
    return true;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        if (allq(s)) {
            std::cout << s.length() << "\n";
            continue;
        }
        if (s[0] == '0') {
            std::cout << 1 << "\n";
            continue;
        }
        int i1 = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '1') {
                i1 = i;
                break;
            }
        }
        int i0 = s.length() - 1;
        for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] == '0') {
                i0 = i;
                break;
            }
        }
        std::cout << std::abs(i1 - i0) + 1 << "\n";
    }
    return 0;
}
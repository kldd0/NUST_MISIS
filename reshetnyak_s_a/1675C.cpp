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
        
    }
    return 0;
}
#include <iostream>
#include <string>
#include <vector>

bool ex(std::string s) {
    for (auto e : s) if (e == '?') return true;
    return false;
}

bool ispal(std::string s) {
    int n = s.length() - 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] != s[n - i]) return false;
    }
    return true;
}

int main() {
    int t, a, b;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> a >> b;
        std::cin >> s;
        std::vector<char> vs(s.length(), '0');
        bool f = true;
        uint n = s.length() - 1;
        for (int i = 0; i < n; ++i) {
            if (s[i] != '?' && s[n - i + 1] == '?') {
                vs[i] = s[i];
                vs[n - i + 1] = s[i];
            } else if (s[i] == '?' && s[n - i + 1] != '?') {
                vs[i] = s[n - i + 1];
                vs[n - i + 1] = s[n - i + 1];
            } else if (s[n - i + 1] != '?' && s[i] != '?' && s[n - i + 1] != s[i]) {
                std::cout << s[n - i + 1] << " " << n - i + 1 << " " << i << " " << s[i] << "\n";
                f = false;
                break;
            }
        }
        if (!f) {
            std::cout << -1 << "\n";
            break;
        } else {
            for (auto e : vs) std::cout << e << " ";
            std::cout << "\n";
        }


    }
    return 0;
}

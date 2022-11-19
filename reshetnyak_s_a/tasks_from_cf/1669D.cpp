#include <iostream>
#include <vector>
#include <string>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::string s;
        std::cin >> n;
        std::cin >> s;
        std::vector<std::string> vs;
        std::string as = "";
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'W') {
                if (!as.empty()) {
                    vs.push_back(as);
                    as = "";
                }
            } else {
                as += s[i];
            }
        }
        if (!as.empty()) {
            vs.push_back(as);
            as = "";
        }
        bool f = true;
        for (auto e : vs) {
            if (e.length() == 1) {
                f = false;
                break;
            }
            if (e.length() > 1) {
                int s = 0;
                for (auto el : e) {
                    if (el == 'R') s += 1;
                    else s += 2;
                }
                if (2 * e.length() == s || e.length() == s) {
                    f = false;
                    break;
                }
            }
            // std::cout << e << " ";
        }
        if (f) std::cout << "YES" << "\n";
        else std::cout << "NO" << "\n";
    }
    return 0;
}
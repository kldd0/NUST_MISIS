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
        std::vector<std::string> vs;
        std::string as = "";
        for (int i = 0; i < n; ++i) {
            if (!as.empty() && as[as.length() - 1] != s[i]) {
                vs.push_back(as);
                as = "";
            }
            as += s[i];
        }
        vs.push_back(as);
        int mn = 100000000;
        for (int i = 0; i < vs.size() - 2; ++i) {
            // if (vs[i].length() + vs[i + 2].length() >= k) {
            //     mn = std::min(vs[i + 1].length(), mn);
            // }
            if (vs[i].length() + vs[i + 1].length() + vs[i + 2].length() >= k) {
                if (vs[i].length() + vs[i + 1].length() + vs[i + 2].length() < mn) {
                    mn = vs[i + 1].length();
                }
            }
        }
        std::cout << mn << "\n";
    }
    return 0;
}
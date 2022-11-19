#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

std::string i_t_t(int n) {
    std::string r = "";
    while (n > 0) {
        r += std::to_string(n % 3);
        n /= 3;
    }
    std::reverse(r.begin(), r.end());
    return r;
}

void solve(int a, int c) {
    std::string as = i_t_t(a);
    std::string cs = i_t_t(c);
    int r = 0;
    if (c > a) {
        int n = cs.length() - as.length();
        while (n--) as = '0' + as;
        for (int i = 0; i < cs.length(); ++i) {
            int e1 = cs[i] - '0';
            int e2 = as[i] - '0';
            r += ((e1 + 3 - e2) % 3) * std::pow(3, cs.length() - i - 1);
        }
    } else {
        int n = as.length() - cs.length();
        while (n--) cs = '0' + cs;
        for (int i = 0; i < as.length(); ++i) {
            int e1 = cs[i] - '0';
            int e2 = as[i] - '0';
            r += ((e1 + 3 - e2) % 3) * std::pow(3, cs.length() - i - 1);
        }
    }
    std::cout << r << "\n";
}

int main() {
    int a, c;
    std::cin >> a >> c;
    solve(a, c);
    return 0;
}
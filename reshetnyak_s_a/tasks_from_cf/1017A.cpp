#include <iostream>
#include <vector>
#include <algorithm>

struct P {
    int id = 0;
    int s = 0;
};

bool cmp(const P &f, const P &s) {
    return f.id < s.id ? f.s == s.s : f.s > s.s;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<P> v(n);
    for (int i = 1; i <= n; ++i) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        v[i] = P({i, a + b + c + d});
    }
    std::sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; ++i) {
        if (v[i].id == 1) std::cout << i + 1 << "\n";
    }
    return 0;
}
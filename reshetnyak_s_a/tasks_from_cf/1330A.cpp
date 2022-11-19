#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    int t, n, x;
    std::cin >> t;
    while (t) {
        --t;
        std::cin >> n >> x;
        std::vector<int> r(10000, 0);
        for (int i = 0; i < n; ++i) {
            int ind = 0;
            std::cin >> ind;
            r[ind] = 1;
        }
        int cnt = 0;
        for (int i = 1; i < 10000; ++i) {
            if (r[i]) ++cnt;
            else {
                if (x > 0) {
                    r[i] = 1;
                    ++cnt;
                    --x;
                } else break;
            }
        }
        std::cout << cnt << "\n";
    }
    return 0;
}
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::vector<int> cn(8);
        std::vector<std::vector<int>> d(8, std::vector<int> (8, 0));
        for (int i = 0; i < 8; ++i) {
            int cnt = 0;
            for (int j = 0; j < 8; ++j) {
                char s;
                std::cin >> s;
                if (s == '#') {
                    d[i][j] = 1;
                    ++cnt;
                }
            }
            cn[i] = cnt;
        }
        int r = 0;
        for (int i = 1; i < 7; ++i) {
            if (cn[i] == 1) {
                if (cn[i - 1] == 2 && cn[i + 1] == 2) {
                    r = i;
                    break;
                }
            }
        }
        for (int i = 0; i < 7; ++i) {
            if (d[r][i]) {
                std::cout << r + 1 << " " << i + 1 << "\n";
                break;
            }
        }
    }
    return 0;
}
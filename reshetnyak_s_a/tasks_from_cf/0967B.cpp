#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    int n, a, b;
    std::cin >> n >> a >> b;
    std::vector<int> v(n - 1);
    int f;
    std::cin >> f;
    int s = 0;
    s += f;
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> v[i];
        s += v[i];
    }
    std::sort(v.begin(), v.end(), [](int f, int s) {return f > s;});
    if ((f * a) > b * s) {
        std::cout << 0 << "\n";
    } else {
        int c = 0;
        for (int i = 0; i < n - 1; ++i) {
            ++c;
            s -= v[i];
            double val = f * a;
            if (val > (s * b)) break;
        }
        std::cout << c << "\n";
    } 
    return 0;
}
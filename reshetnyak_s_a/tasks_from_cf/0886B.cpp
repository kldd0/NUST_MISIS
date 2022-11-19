#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> w;
    std::set<int> s;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        s.insert(a[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        w.push_back(a[i]);
        std::vector<int> v_intersection;
        std::set_intersection(w.begin(), w.end(),
                            s.begin(), s.end(),
                            std::back_inserter(v_intersection));
        for (auto e : w) std::cout << e << " ";
        std::cout << "\n";
        if (v_intersection.size() == a.size()) {
            std::cout << a[i] << "\n";
            break;
        }
    }
    return 0;
}
#include <iostream>
#include <deque>
#include <algorithm>

typedef long long ll;

int main() {
    int n;
    ll k;
    std::cin >> n >> k;
    if (n > 2) {
        if (k > n) {
            std::deque<int> a;
            for (int i = 0; i < n; ++i) {
                int el;
                std::cin >> el;
                a.push_back(el);
            }
            std::cout << *std::max_element(a.begin(), a.end()) << "\n";
        } else {
            std::deque<int> a;
            for (int i = 0; i < n; ++i) {
                int el;
                std::cin >> el;
                a.push_back(el);
            }
            int c = 0;
            int prev = 0;
            while (c != k) {
                int a1 = a.front();
                a.pop_front();
                int a2 = a.front();
                a.pop_front();
                if (a1 > a2) {
                    if (0 == prev) {
                        ++c;
                        prev = a1;
                    } else if (a1 == prev) ++c;
                    else {
                        c = 1;
                        prev = a1;
                    }
                    a.push_front(a1);
                    a.push_back(a2);
                } else {
                    if (0 == prev) {
                        ++c;
                        prev = a2;
                    } else if (a2 == prev) ++c;
                    else {
                        c = 1;
                        prev = a2;
                    }
                    a.push_front(a2);
                    a.push_back(a1);
                }
            }
            std::cout << prev << "\n";
        }
    } else {
        int f, s;
        std::cin >> f >> s;
        if (f > s) std::cout << f << "\n";
        else std::cout << s << "\n";
    }
    return 0;
}
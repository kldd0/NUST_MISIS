#include <iostream>
#include <set>

int MAXINT = 100002;

int main() {
    int a, m;
    std::cin >> a >> m;
    std::set<int> s;
    s.insert(a);
    bool f = false;
    std::set<int>::iterator prev = s.begin();
    for (int i = 0; i < MAXINT; ++i) {
        for (auto e : s) std::cout << e << " ";
        std::cout << "\n";
        int pl = s.size();
        int ne = (*prev + (*prev % m)) % m;
        if (ne == 0) {
            f = false;
            break;
        }
        s.insert(ne);
        ++prev;
        if (pl == s.size()) {
            f = true;
            break;
        }
    }
    if (f) std::cout << "No" << "\n";
    else std::cout << "Yes" << "\n";
    return 0;
}
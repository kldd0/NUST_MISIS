#include <iostream>
#include <string>

int main() {
    std::string f, s;
    std::cin >> f >> s;
    int fn = f.length();
    int sn = s.length();
    int i = fn - 1;
    int j = sn - 1;
    while (f[i] == s[j]) {
        --i;
        --j;
    }
    int sm = i + j + 2;
    std::cout << sm << "\n";
    return 0;
}
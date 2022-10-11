#include <iostream>
#include <string>
#include <vector>

bool ex(std::string s) {
    for (auto e : s) if (e == '?') return true;
    return false;
}

bool ispal(std::string s) {
    int n = s.length() - 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] != s[n - i]) return false;
    }
    return true;
}

int main() {
    int t, a, b;
    std::string s;
    std::cin >> t;
    while (t) {
        --t;
        std::cin >> a >> b;
        std::cin >> s;
        if (!ex(s)) {
            for (auto e : s) {
                if (e == '1') --b;
                else if (e == '0') --a;
            }
            if (ispal(s) && a == 0 && b == 0) {
                std::cout << s << "\n";
                continue;
            } else {
                std::cout << -1 << "\n";
                continue;
            }
        }
        if (s.length() == 1) {
            if (a) {
                std::cout << 0 << "\n";
                continue;
            } else if (b) {
                std::cout << 1 << "\n";
                continue;
            } else {
                std::cout << -1 << "\n";
                continue;
            }
        }
        for (auto e : s) {
            if (e == '1') --b;
            else if (e == '0') --a;
        }
        std::vector<char> res(s.length());
        for (int i = 0; i < s.length(); ++i) res[i] = s[i];
        bool f = true;
        int i = 0, n = s.length() - 1;
        while (((i <= ((n - i) - 1) && !(s.length() % 2))) || ((i <= (n - i)) && (s.length() % 2))) {
            // std::cout << "a= " << a << " b= " << b << " i: " << i << " n - i: "  << n - i << "\n";
            if (res[i] == res[n - i] && res[i] != '?') {
                ++i;
                continue;
            }
            if (s[i] != '?' && s[n - i] == '?') {
                res[i] = s[i];  
                res[n - i] = s[i];
                if (s[i] == '1') --b;
                else if (s[i] == '0') --a;
            } else if (s[n - i] != '?' && s[i] == '?') {
                res[i] = s[n - i];
                res[n - i] = s[n - i];
                if (s[n - i] == '1') --b;
                else if (s[n - i] == '0') --a;
            } else {
                if (i == (n - i)) {
                    if (s[i] == '?') {
                        if (a > 0) {
                            res[i] = '0';
                            --a;
                        } else if (b > 0) {
                            res[i] = '1';
                            --b;
                        } else {
                            f = false;
                            break;
                        }
                    } else res[i] = s[i];
                } else if (b > 1 && b >= a) {
                    res[i] = '1';
                    res[n - i] = '1';
                    b -= 2;
                } else if (a > 1) {
                    res[i] = '0';
                    res[n - i] = '0';
                    a -= 2;
                } else {
                    f = false;
                    break;
                }
            }
            ++i;
            continue;
        }
        // for (auto e : res) std::cout << e << " ";
        // std::cout << "\n";
        if (f && a == 0 && b == 0) {
            for (unsigned char e : res) std::cout << e;
            std::cout << "\n";
            // std::cout << "a= " << a << " b= " << b << " ia= " << ia << " ib= " << ib;
            continue;
        } else {
            std::cout << -1 << "\n";
            continue;
        }
        // } else {
        //     std::cout << -1 << "\n";
        //     continue;
        // }
    }
    return 0;
}

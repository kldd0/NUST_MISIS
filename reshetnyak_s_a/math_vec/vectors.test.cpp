#include <iostream>
#include <vectors/vectors.hpp>


int main() {
    Rdec2D a = {3.0, 5.0};
    Rdec2D b = {4.2, 7.1};

    std::cout << "a = " << a << " b = " << b << "\n";

    Rdec2D res_plus = a + b;
    std::cout << res_plus << "\n";

    Rdec2D res_minus = a - b;
    std::cout << res_minus << "\n";

    Rdec2D res_sc = b * 2;
    std::cout << res_sc << "\n";
    
    double res_dot = dot(a, b);
    std::cout << res_dot << "\n";

    Rpol2D res_pol = transform_to_Rpol2D(b);
    std::cout << res_pol << "\n";

    // Rpol2D apol = {12.0, std::numbers::pi / 2};
    // std::cout << res.x << " " << res.y << "\n";
    return 0;
}
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <lib-vectors/vectors.hpp>
#include <numbers>

TEST_CASE("Dec functions") {
    CHECK(Rdec2D{2.0, 1.5} + Rdec2D{4.0, 3.0} == Rdec2D{6.0, 4.5});
    CHECK(Rdec2D{2.0, 1.5} - Rdec2D{4.0, 3.0} == Rdec2D{-2.0, -1.5});
}

TEST_CASE("Transform funcs") {
    // to Pol
    CHECK(transform_to_Rpol2D(Rdec2D{3.0, 4.0}).r == 5.0);
    CHECK(transform_to_Rpol2D(Rdec2D{2.0, 2.0}) == Rpol2D{std::sqrt(8), std::numbers::pi / 4});
    
    // to Dec
    CHECK(transform_to_Rdec2D(Rpol2D{6, std::numbers::pi / 3}) == Rdec2D{3.0 , std::sqrt(27)});
}

TEST_CASE("") {
    ;
}

// Rdec2D a = {3.0, 5.0};
// Rdec2D b = {4.2, 7.1};

// std::cout << "a = " << a << " b = " << b << "\n";

// Rdec2D res_plus = a + b;
// std::cout << res_plus << "\n";

// Rdec2D res_minus = a - b;
// std::cout << res_minus << "\n";

// Rdec2D res_sc = b * 2;
// std::cout << res_sc << "\n";

// double res_dot = dot(a, b);
// std::cout << res_dot << "\n";

// Rpol2D res_pol = transform_to_Rpol2D(b);
// std::cout << res_pol << "\n";

// Rpol2D apol = {12.0, std::numbers::pi / 2};
// std::cout << res.x << " " << res.y << "\n";
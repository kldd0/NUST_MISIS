#include <iosfwd>

struct Rdec2D {
    double x = 0.0;
    double y = 0.0;
};

struct Rpol2D {
    double r = 0.0;
    double phi = 0.0;
};


// Dec

Rdec2D operator+(const Rdec2D &lhs, const Rdec2D &rhs);

Rdec2D operator-(const Rdec2D &lhs, const Rdec2D &rhs);

Rdec2D operator*(const Rdec2D &vec, int s);

double dot(const Rdec2D &lhs, const Rdec2D &rhs);

double norm(const Rdec2D &vec);


// transform

Rdec2D transform_to_Rdec2D(const Rpol2D &vec);

Rpol2D transform_to_Rpol2D(const Rdec2D &vec);


// Pol

Rpol2D operator+(const Rpol2D &lhs, const Rpol2D &rhs);

Rpol2D operator-(const Rpol2D &lhs, const Rpol2D &rhs);

Rpol2D operator*(const Rpol2D &vec, int s);

double dot(Rpol2D &lhs, Rpol2D &rhs);


// Output

// Dec

std::ostream& operator<<(std::ostream& ostrm, const Rdec2D& vec);

// Pol

std::ostream& operator<<(std::ostream& ostrm, const Rpol2D& vec);
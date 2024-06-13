#include <iostream>
#include <stdexcept>

class GaloisField {
private:
    static const int size = 1234567891;
    int value;

    int modular_multiplication(int a, int b);
    int modular_multiplicative_inverse(int v);
public:

    // constructors
    GaloisField();
    GaloisField(int v);

    // comparison operators
    bool operator==(const GaloisField& obj);
    bool operator!=(const GaloisField& obj);
    bool operator<=(const GaloisField& obj);
    bool operator>=(const GaloisField& obj);
    bool operator<(const GaloisField& obj);
    bool operator>(const GaloisField& obj);

    // arithmetic operators
    GaloisField operator+(const GaloisField& obj);
    GaloisField operator-(const GaloisField& obj);
    GaloisField operator*(const GaloisField& obj);
    GaloisField operator/(const GaloisField& obj);

    // assingment operators
    void operator=(const GaloisField& obj);
    void operator+=(const GaloisField& obj);
    void operator-=(const GaloisField& obj);
    void operator*=(const GaloisField& obj);
    void operator/=(const GaloisField& obj);

    // conversion operators
    operator int() const;

    // stream operators
    friend std::ostream & operator << (std::ostream &out, const GaloisField &c);
    friend std::istream & operator >> (std::istream &in,  GaloisField &c);

    // characteristic
    std::string describe();
};

// global stream operators
std::ostream & operator << (std::ostream &out, const GaloisField &obj);
std::istream & operator >> (std::istream &in,  GaloisField &obj);
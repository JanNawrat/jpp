#include "GaloisField.hpp"

// private methods

int GaloisField::modular_multiplication(int a, int b) {
    unsigned long res = 0;
    while(b > 0) {
        unsigned long partialSum = a;
        unsigned long i;
        for(i = 2; i <= b; i*=2) {
            partialSum = (2 * partialSum) % size;
        }
        res = (res + partialSum) % size;
        b -= i/2;
    }
    return res;
}

int GaloisField::modular_multiplicative_inverse(int v) {
    int r0 = size;
    int r1 = v;
    if(r1 == 0) {
        throw std::invalid_argument(std::to_string(v) + " does not have a modular multiplicative inverse in Galois field of size " + std::to_string(size));
    }

    int q, tmp, s0 = 1, s1 = 0, t0 = 0, t1 = 1;

    while (r1 != 0) {
        q = r0/r1;
        tmp = r1;
        r1 = r0 - r1*q;
        r0 = tmp;  

        tmp = s1;
        s1 = s0 - s1*q;
        s0 = tmp;

        tmp = t1;
        t1 = t0 - t1*q;
        t0 = tmp;
    }

    if (r0 != 1) {
        throw std::invalid_argument(std::to_string(v) + " does not have a modular multiplicative inverse in Galois field of size " + std::to_string(size));
    }

    while(t0 < 0) {
        t0 += size;
    }

    return t0 % size;
}

// constructors

GaloisField::GaloisField() {
    value = 0;
}

GaloisField::GaloisField(int v) {
    while(v < 0) {
        v += size;
    }
    value = v % size;
}

// comparison operators

bool GaloisField::operator==(const GaloisField& obj) {
    return value == obj.value;
}

bool GaloisField::operator!=(const GaloisField& obj) {
    return value != obj.value;
}

bool GaloisField::operator<=(const GaloisField& obj) {
    return value <= obj.value;
}

bool GaloisField::operator>=(const GaloisField& obj) {
    return value >= obj.value;
}

bool GaloisField::operator<(const GaloisField& obj) {
    return value < obj.value;
}

bool GaloisField::operator>(const GaloisField& obj) {
    return value > obj.value;
}

// arithmetic operators

GaloisField GaloisField::operator+(const GaloisField& obj) {
    return GaloisField(value + obj.value);
}

GaloisField GaloisField::operator-(const GaloisField& obj) {
    return GaloisField(value - obj.value);
}

GaloisField GaloisField::operator*(const GaloisField& obj) {
    return GaloisField(modular_multiplication(value, obj.value));
}

GaloisField GaloisField::operator/(const GaloisField& obj) {
    try
    {
        int inverse = modular_multiplicative_inverse(obj.value);
        return GaloisField(modular_multiplication(value, inverse));
    }
    catch(const std::exception& e)
    {
        throw e;
    }
}

// assingment operators

void GaloisField::operator=(const GaloisField& obj) {
    value = obj.value;
}

void GaloisField::operator+=(const GaloisField& obj) {
    value = (value + obj.value) % size;
}

void GaloisField::operator-=(const GaloisField& obj) {
    value = (value - obj.value + size) % size;
}

void GaloisField::operator*=(const GaloisField& obj) {
    value = modular_multiplication(value, obj.value);
}

void GaloisField::operator/=(const GaloisField& obj) {
    try
    {
        int inverse = modular_multiplicative_inverse(obj.value);
        value = modular_multiplication(value, inverse);
    }
    catch(const std::exception& e)
    {
        throw e;
    }
    
}

// conversion operators

GaloisField::operator int() const {
    return value;
}

// characteristic

std::string GaloisField::describe() {
    return "Value " + std::to_string(value) + " in Galois field of size " + std::to_string(size);
}
 
std::ostream & operator << (std::ostream &out, const GaloisField &obj)
{
    out << obj.value;
    return out;
}
 
std::istream & operator >> (std::istream &in,  GaloisField &obj)
{
    in >> obj.value;
    return in;
}
#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

void Fraction::display()
{
    std::cout << numerator << "/" << denominator;
}

Fraction add(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.denominator + f2.numerator * f1.denominator,
                     f1.denominator * f2.denominator});
}

// Fraction add(Fraction const& f1, Fraction const& f2) {
//     Fraction result {
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator
//         f1.denominator * f2.denominator
//     };

//     return simplify(result);
// }

Fraction sub(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.denominator - f2.numerator * f1.denominator,
                     f1.denominator * f2.denominator});
}

Fraction mul(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.numerator,
                     f1.denominator * f2.denominator});
}

Fraction div(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.denominator,
                     f1.denominator * f2.numerator});
}


// Exercice 1

/*
Fraction operator+(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.denominator + f2.numerator * f1.denominator,
                     f1.denominator * f2.denominator});
}

Fraction operator-(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.denominator - f2.numerator * f1.denominator,
                     f1.denominator * f2.denominator});
}

Fraction operator*(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.numerator,
                     f1.denominator * f2.denominator});
}

Fraction operator/(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.denominator,
                     f1.denominator * f2.numerator});
}
/**/


// Exercice 2

std::ostream &operator<<(std::ostream &os, Fraction const &f)
{
    return os << f.numerator << "/" << f.denominator;
}


// Exercice 3

bool operator==(Fraction const &f1, Fraction const &f2)
{
    return f1.numerator * f2.denominator == f1.denominator * f2.numerator;
}

bool operator!=(Fraction const &f1, Fraction const &f2)
{
    return !(f1 == f2);
}


// Exercice 4

bool operator<(Fraction const &f1, Fraction const &f2)
{
    return f1.numerator * f2.denominator < f1.denominator * f2.numerator;
}

bool operator<=(Fraction const &f1, Fraction const &f2)
{
    return f1 < f2 || f1 == f2;
}

bool operator>(Fraction const &f1, Fraction const &f2)
{
    return f2 < f1;
}

bool operator>=(Fraction const &f1, Fraction const &f2)
{
    return f1 > f2 || f1 == f2;
}


// Exercice 5

void Fraction::operator+=(Fraction const& f) {
    numerator = numerator * f.denominator + f.numerator * denominator;
    denominator *= f.denominator;

    *this = simplify(*this);
}

void Fraction::operator-=(Fraction const& f) {
    numerator = numerator * f.denominator - f.numerator * denominator;
    denominator *= f.denominator;

    *this = simplify(*this);
}

void Fraction::operator*=(Fraction const& f) {
    numerator *= f.numerator;
    denominator *= f.denominator;

    *this = simplify(*this);
}

void Fraction::operator/=(Fraction const& f) {
    numerator *= f.denominator;
    denominator *= f.numerator;

    *this = simplify(*this);
}


Fraction operator+(Fraction f1, Fraction const &f2)
{
    f1 += f2;
    return f1;
}

Fraction operator-(Fraction f1, Fraction const &f2)
{
    f1 -= f2;
    return f1;
}

Fraction operator*(Fraction f1, Fraction const &f2)
{
    f1 *= f2;
    return f1;
}

Fraction operator/(Fraction f1, Fraction const &f2)
{
    f1 /= f2;
    return f1;
}
/**/


// Exercice 6

float Fraction::to_float() const {
    return static_cast<float>(numerator) / static_cast<float>(denominator);
}

Fraction::operator float() const {
    return to_float();
}
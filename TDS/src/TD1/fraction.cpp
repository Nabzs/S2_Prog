#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>
#include <cmath> // Pour std::abs, std::ceil, std::floor, std::round


void Fraction::display()
{
    std::cout << numerator << "/" << denominator;
}


// Exercice 1

Fraction add(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.denominator + f2.numerator * f1.denominator,
                     f1.denominator * f2.denominator});
}


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

// Aller plus loin
Fraction Fraction::abs() const {
    return Fraction{std::abs(numerator), std::abs(denominator)};
}

Fraction Fraction::ceil() const {
    int result = static_cast<int>(std::ceil(to_float()));
    return Fraction{result, 1};
}

Fraction Fraction::floor() const {
    int result = static_cast<int>(std::floor(to_float()));
    return Fraction{result, 1};
}

Fraction Fraction::round() const {
    int result = static_cast<int>(std::round(to_float()));
    return Fraction{result, 1};
}

// 
Fraction operator+(Fraction const& f, int const i) {
    return f + Fraction{i, 1};
}

Fraction operator+(int const i, Fraction const& f) {
    return Fraction{i, 1} + f;
}

Fraction operator-(Fraction const& f, int const i) {
    return f - Fraction{i, 1};
}

Fraction operator-(int const i, Fraction const& f) {
    return Fraction{i, 1} - f;
}

Fraction operator*(Fraction const& f, int const i) {
    return f * Fraction{i, 1};
}

Fraction operator*(int const i, Fraction const& f) {
    return Fraction{i, 1} * f;
}

Fraction operator/(Fraction const& f, int const i) {
    return f / Fraction{i, 1};
}

Fraction operator/(int const i, Fraction const& f) {
    return Fraction{i, 1} / f;
}
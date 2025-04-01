#pragma once

#include <iostream>
#include <cmath>

struct Fraction
{
    int numerator{0};
    int denominator{1};

    void display();

    // Exercice 5

    void operator+=(Fraction const& f);
    void operator-=(Fraction const& f);
    void operator*=(Fraction const& f);
    void operator/=(Fraction const& f);

    // Exercice 6

    float to_float() const;
    operator float() const;


    // Aller plus loin
    Fraction abs() const;
    Fraction ceil() const;
    Fraction floor() const;
    Fraction round() const;
};

Fraction add(Fraction const &f1, Fraction const &f2);
Fraction sub(Fraction const &f1, Fraction const &f2);
Fraction mul(Fraction const &f1, Fraction const &f2);
Fraction div(Fraction const &f1, Fraction const &f2);



// Ex 2

std::ostream &operator<<(std::ostream &os, Fraction const &f);

// Ex 3

bool operator==(Fraction const &f1, Fraction const &f2);
bool operator!=(Fraction const &f1, Fraction const &f2);

// Ex 4

bool operator<(Fraction const &f1, Fraction const &f2);
bool operator<=(Fraction const &f1, Fraction const &f2);
bool operator>(Fraction const &f1, Fraction const &f2);
bool operator>=(Fraction const &f1, Fraction const &f2);

// Ex 5

Fraction operator+(Fraction f1, Fraction const &f2);
Fraction operator-(Fraction f1, Fraction const &f2);
Fraction operator*(Fraction f1, Fraction const &f2);
Fraction operator/(Fraction f1, Fraction const &f2);
/**/




// Fonctions libres pour les opérateurs avec des entiers
Fraction operator+(Fraction const& f, int const i);
Fraction operator+(int const i, Fraction const& f);
Fraction operator-(Fraction const& f, int const i);
Fraction operator-(int const i, Fraction const& f);
Fraction operator*(Fraction const& f, int const i);
Fraction operator*(int const i, Fraction const& f);
Fraction operator/(Fraction const& f, int const i);
Fraction operator/(int const i, Fraction const& f);

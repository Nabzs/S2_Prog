#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1{3, 4};
    Fraction f2{1, 2};

    std::cout << "f1 = " << f1 << " f2 = " << f2 << std::endl;

    std::cout << "add(f1, f2) = " << add(f1, f2) << std::endl;
    std::cout << "sub(f1, f2) = " << sub(f1, f2) << std::endl;
    std::cout << "mul(f1, f2) = " << mul(f1, f2) << std::endl;
    std::cout << "div(f1, f2) = " << div(f1, f2) << std::endl;


    std::cout << std::endl << "Exercice 1" << std::endl;

    std::cout << "f1 + f2 = " << f1 + f2 << std::endl;
    std::cout << "f1 - f2 = " << f1 - f2 << std::endl;
    std::cout << "f1 * f2 = " << f1 * f2 << std::endl;
    std::cout << "f1 / f2 = " << f1 / f2 << std::endl;


    std::cout << std::endl << "Exercice 3" << std::endl;

    std::cout << "f1 == 6/8 = " << (f1 == Fraction{6, 8}) << std::endl;
    std::cout << "f1 == f2 = " << (f1 == f2) << std::endl;
    std::cout << "10/20 != f2 = " << (Fraction{10, 20} != f2) << std::endl;
    std::cout << "f1 != f2 = " << (f1 != f2) << std::endl;


    std::cout << std::endl << "Exercice 4" << std::endl;

    std::cout << "1/3 < 1/2 = " << (Fraction{1, 3} < Fraction{1, 2}) << std::endl;
    std::cout << "2/4 < 1/2 = " << (Fraction{2, 4} < Fraction{1, 2}) << std::endl;
    std::cout << "5/3 < 1/2 = " << (Fraction{5, 3} < Fraction{1, 2}) << std::endl;

    std::cout << "1/3 <= 1/2 = " << (Fraction{1, 3} <= Fraction{1, 2}) << std::endl;
    std::cout << "2/4 <= 1/2 = " << (Fraction{2, 4} <= Fraction{1, 2}) << std::endl;
    std::cout << "5/3 <= 1/2 = " << (Fraction{5, 3} <= Fraction{1, 2}) << std::endl;

    std::cout << "1/3 > 1/2 = " << (Fraction{1, 3} > Fraction{1, 2}) << std::endl;
    std::cout << "2/4 > 1/2 = " << (Fraction{2, 4} > Fraction{1, 2}) << std::endl;
    std::cout << "5/3 > 1/2 = " << (Fraction{5, 3} > Fraction{1, 2}) << std::endl;

    std::cout << "1/3 >= 1/2 = " << (Fraction{1, 3} >= Fraction{1, 2}) << std::endl;
    std::cout << "2/4 >= 1/2 = " << (Fraction{2, 4} >= Fraction{1, 2}) << std::endl;
    std::cout << "5/3 >= 1/2 = " << (Fraction{5, 3} >= Fraction{1, 2}) << std::endl;


    std::cout << std::endl << "Exercice 5" << std::endl;

    Fraction f_ex5{1, 2};
    std::cout << f_ex5 << std::endl;
    f_ex5 += Fraction{1, 3};
    std::cout << "+ 1/3 = " << f_ex5 << std::endl;
    f_ex5 -= Fraction{2, 4};
    std::cout << "- 2/4 = " << f_ex5 << std::endl;
    f_ex5 *= Fraction{5, 3};
    std::cout << "* 5/3 = " << f_ex5 << std::endl;
    f_ex5 /= Fraction{5, 9};
    std::cout << "/ 5/9 = " << f_ex5 << std::endl;
    

    std::cout << std::endl << "Exercice 6" << std::endl;

    std::cout << "1/2 = " << Fraction{1, 2}.to_float() << std::endl;
    std::cout << "1/3 = " << Fraction{1, 3}.to_float() << std::endl;
    std::cout << "2/4 = " << static_cast<float>(Fraction{2, 4}) << std::endl;
    std::cout << "5/3 = " << static_cast<float>(Fraction{5, 3}) << std::endl;


    return 0;
}
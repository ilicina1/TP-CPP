//TP 2017/2018: Tutorijal 2, Zadatak 4
#include <iostream>
#include <complex>

int main ()
{
    int n;
    typedef std::complex<double> Kompleksni;

    std::cout << "Unesite broj elemenata: " << std::endl;
    std::cin >> n;

    double re, im;
    Kompleksni a, b, suma;

    for(int i = 1; i <= n; i++) {

        std::cout << "R" << i << " = ";
        std::cin >> re;

        std::cout << "X" << i << " = ";
        std::cin >> im;
        std::cout << std::endl;

        a = Kompleksni(re, im);
        b = 1. / a;
        suma += b;

    }

    Kompleksni impedansa;

    impedansa = 1. / suma;

    std::cout << "Paralelna veza ovih elemenata ima R = " << impedansa.real() << " i " << "X = " << impedansa.imag() << "." << std::endl;

    return 0;
}

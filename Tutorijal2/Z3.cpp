//TP 2017/2018: Tutorijal 2, Zadatak 3
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
        Kompleksni a(0,0);
        std::cout << "Z_" << i << " = ";
        std::cin >> a;

        b = 1. / a;
        suma += b;

    }

    std::cout << "\n";

    Kompleksni impedansa;

    impedansa = 1. / suma;

    std::cout << "Paralelna veza ovih elemenata ima impedansu Z_ = " << impedansa << "." << std::endl;

    return 0;
}

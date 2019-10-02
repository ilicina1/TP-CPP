//TP 2017/2018: Tutorijal 2, Zadatak 5
#include <iostream>
#include <complex>

int main ()
{
    int n;
    typedef std::complex<double> Kompleksni;

    std::cout << "Unesi broj elemenata:" << std::endl;
    std::cin >> n;

    double re, im;
    Kompleksni a, b, suma;

    for(int i = 1; i <= n; i++) {

        std::cout << "Z" << i << " = ";
        std::cin >> re;

        std::cout << "fi" << i << " = ";
        std::cin >> im;
        std::cout << std::endl;

        im = im * (4 * atan(1) / 180);
        a = std::polar(re,im);
        b = 1. / a;
        suma += b;

    }

    Kompleksni impedansa;

    impedansa = 1. / suma;

    std::cout << "Paralelna veza ovih elemenata ima Z = " << std::abs(impedansa) << " i " << "fi = " << std::arg(impedansa) * (180 / (4 * atan(1))) << "." << std::endl;

    return 0;
}

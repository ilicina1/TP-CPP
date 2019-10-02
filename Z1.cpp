//TP 2016/2017: Tutorijal 1, Zadatak 1
#include <iostream>
#include <cmath>

int main ()
{

    int a, b, c, d, broj_plocica;

    std::cout << "Unesite duzinu, sirinu i dubinu bazena u metrima: ";
    std::cin >> a >> b >> c;

    std::cout << "Unesite sirinu plocice u centimetrima: \n";
    std::cin >> d;

    broj_plocica = (10000 * (2 * (a * c + b * c) + a * b) / (d * d));

    if ((a*100) % d == 0 && (b*100) % d == 0 && (c*100) % d == 0) {
        std::cout << "Za poplocavanje bazena dimenzija " << a << "x" << b << "x" << c;
        std::cout <<"m sa plocicama dimenzija " << d << "x" << d << "cm \npotrebno je " << broj_plocica << " plocica.";
    } else {
        std::cout << "Poplocavanje bazena dimenzija " << a << "x" << b << "x" << c << "m sa plocicama dimenzija " << d << "x" << d << "cm \nnije izvodljivo bez lomljenja plocica!\n";
    }

    return 0;
}

//TP 2016/2017: Tutorijal 1, Zadatak 4
#include <iostream>
#include <cmath>

int main ()
{
    double n;

    for(;;) {
        std::cout << "Unesite prirodan broj ili 0 za kraj: ";

        if(!(std::cin >> n) || n < 0 || int(n) != n) {
            std::cout << "Niste unijeli prirodan broj!" << "\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (n==0) {
            std::cout << "Dovidjenja!";
            break;
        }

        int suma = 0;

        for(int i = 1; i < n; i++) {
            if(int(n) % i == 0)
                suma += i;
        }

        if(suma < n) {
            std::cout << "Broj " << n << " je manjkav!" << "\n";
        } else if (suma == n) {
            std::cout << "Broj " << n << " je savrsen!" << "\n";
        } else if (suma > n) {
            std::cout << "Broj " << n << " je obilan!" << "\n";
        }

    }

    return 0;

}

//TP 2018/2019: Tutorijal 4, Zadatak 1
#include <iostream>
#include <cmath>

int Cifre(long long int n, int &c_max, int &c_min)
{
    int brCifara = 0;
    int b = abs(n);
    c_max = n % 10;
    c_min = n % 10;

    if(n == 0) {
        c_max = 0;
        c_min = 0;
        brCifara = 1;
    }
    else {
        while(b != 0) {
            brCifara++;
            b /= 10;
        }
    }

    int modul = 0;
    int c = abs(n);
    while(c != 0) {
        int modul = c % 10;
        if(modul > c_max) c_max = modul;
        if(modul < c_min) c_min = modul;
        c /= 10;
    }

    return brCifara;
}

int main ()
{
    long long int n;

    std::cout << "Unesite broj: ";
    std::cin >> n;

    int a, c;

    std::cout << "Broj " << n << " ima " << Cifre(n, a, c) << " cifara, najveca je " << a << " a najmanja " << c << ".";

    return 0;
}

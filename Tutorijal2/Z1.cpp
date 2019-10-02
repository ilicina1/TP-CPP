//TP 2017/2018: Tutorijal 2, Zadatak 1
#include <iostream>
#include <vector>
#include <cmath>

bool DaLiJeProst(int n)
{
    if(n == 2 || n ==3) return true;

    if(n % 2 == 0) return false;

    if(n <= 1) return false;

    for(int i = 3; i <= sqrt(n); i += 2) {
        if(n % i == 0) return false;
    }

    return true;
}

std::vector<int> ProstiBrojeviUOpsegu(int a, int b)
{
    std::vector<int> c;

    for(int i = a; i <= b; i++) {
        if(DaLiJeProst(i) == true) c.push_back(i);
        if(i == b) break;
    }

    return c;
}

int main ()
{
    int x, y;

    std::cout << "Unesite pocetnu i krajnju vrijednost: ";
    std::cin >> x >> y;

    std::vector<int> brojevi = ProstiBrojeviUOpsegu(x,y);

    if(brojevi.size() == 0) {
        std::cout << "Nema prostih brojeva u rasponu od " << x << " do " << y << "!" << std::endl;
    } else {
        std::cout << "Prosti brojevi u rasponu od " << x << " do " << y << " su: ";

        for(int i : brojevi)
            std::cout << i << (i != brojevi[brojevi.size() - 1] ? ", " : "\n");
    }

    return 0;
}

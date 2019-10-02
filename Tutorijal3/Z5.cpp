//TP 2018/2019: Tutorijal 3, Zadatak 5
#include <iostream>
#include <deque>

std::deque<int> IzdvojiElemente(std::deque<int> a, bool y)
{
    std::deque<int> vektor;

    for(int i : a) {

        int xx = abs(i), suma = 0;

        while(xx > 0) {
            suma += xx % 10;
            xx /= 10;
        }

        if(suma < 0) suma *= -1;

        if((y == true) && (suma % 2 == 0)) vektor.push_front(i);
        else if ((y == false) && (suma % 2 != 0) ) vektor.push_front(i);

    }

    return vektor;
}

int main ()
{
    int n;

    std::cout << "Koliko zelite unijeti elemenata: ";

    if(std::cin >> n, n == 0) {
        std::cout << "Broj elemenata mora biti veci od 0!\n";
        return 0;
    }

    std::cout << "Unesite elemente: ";

    std::deque <int> a;

    for(int i = 0; i < n; i++) {

        int input;
        std::cin >> input;
        a.push_back(input);

    }

    std::deque<int> b = IzdvojiElemente(a, true);

    for(int i = b.size() - 1; i >= 0; i--) {
        std::cout << b.at(i) << (i != 0 ? "," : "\n");
    }

    if(b.size() < 1) std::cout << std::endl;

    std::deque<int> c = IzdvojiElemente(a, false);

    for(int i = c.size() - 1; i >= 0; i--) {
        std::cout << c.at(i) << (i != 0 ? "," : "");
    }

    return 0;
}

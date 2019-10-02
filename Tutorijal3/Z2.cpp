//TP 2018/2019: Tutorijal 3, Zadatak 2
#include <iostream>
#include <vector>

std::vector<int> IzdvojiElemente(std::vector<int> a, bool y)
{
    std::vector<int> vektor;

    for(int i : a) {

        int xx = abs(i), suma = 0;

        while(xx > 0) {
            suma += xx % 10;
            xx /= 10;
        }

        if(suma < 0) suma *= -1;

        if((y == true) && (suma % 2 == 0)) vektor.push_back(i);
        else if ((y == false) && (suma % 2 != 0) ) vektor.push_back(i);

    }

    return vektor;
}

int main ()
{
    int n;

    std::cout << "Koliko zelite unijeti elemenata: ";

    if(std::cin >> n, n == 0){
        std::cout << "Broj elemenata mora biti veci od 0!\n";
        return 0;
    }

    std::cout << "Unesite elemente: ";

    std::vector<int> a;

    for(int i = 0; i < n; i++) {

        int input;
        std::cin >> input;
        a.push_back(input);

    }

    std::vector<int> b = IzdvojiElemente(a, true);
    std::vector<int> c = IzdvojiElemente(a, false);

    for(int i = 0; i < b.size(); i++){
        std::cout << b.at(i) << (i != b.size() - 1 ? "," : "\n");
    }

    if(b.size() < 1) std::cout << std::endl;

    for(int i = 0; i < c.size(); i++){
        std::cout << c.at(i) << (i != c.size() - 1 ? "," : "");
    }

    return 0;
}

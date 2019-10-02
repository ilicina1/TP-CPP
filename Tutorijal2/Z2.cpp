//TP 2017/2018: Tutorijal 2, Zadatak 2
#include <iostream>
#include <vector>

bool TestPerioda(std::vector<double> vektor, int p)
{
    for(int i = 0; i<vektor.size(); i++) {

        if(vektor[i] != vektor[i+p]) return false;

    }

    return true;
}

int OdrediOsnovniPeriod(std::vector<double> a)
{
    for(int i = 0; i < a.size(); i++) {

        if(TestPerioda(a,i) == true) a.push_back(i);

    }

    int min = a[0];

    for(int i = 0; i < a.size(); i++) {

        if(a[i] < min) min = a[i];

    }

    return min;
}

int main ()
{
    std::vector<double> slijed;
    int a;

    std::cout << "Unesite slijed brojeva (0 za kraj): ";

    for(;;) {
        std::cin >> a;

        if(a == 0) break;

        slijed.push_back(a);

    }

    int rezultat = OdrediOsnovniPeriod(slijed);

    if(rezultat)
        std::cout << "Slijed je periodican sa osnovnim periodom " << rezultat << ".";
    else
        std::cout << "Slijed nije periodican!";

    return 0;
}

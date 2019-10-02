//TP 2017/2018: Tutorijal 3, Zadatak 6
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

typedef std::vector<std::vector<int>> Matrica;
typedef std::vector<int> Vektor;

Matrica KreirajMatricu(int broj_redova, int broj_kolona)
{
    return Matrica(broj_redova, Vektor (broj_kolona) );
}

Matrica KroneckerovProizvod(Vektor a, Vektor b)
{
    auto m = KreirajMatricu(a.size(), b.size());

    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            m.at(i).at(j) = a.at(i) * b.at(j);
        }
    }

    return m;
}

int Sirina(int x)
{
    int length = 0;

    if(x < 0) {
        length = log10(abs(x)) + 2;
    } else {
        length = log10(abs(x)) + 1;
    }

    return length;
}

int BrojRedova(Matrica m)
{
    return m.size();
}

int BrojKolona(Matrica m)
{
    return m.at(0).size();
}

int NajvecaSirina(Matrica m)
{
    int maxSirina = 0;

    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m.size(); j++) {
            int sirina = Sirina(m.at(i).at(j));

            if(sirina > maxSirina) maxSirina = sirina;
        }
    }

    return maxSirina;
}

int main ()
{
    int n;

    std::cout << "Unesite broj elemenata prvog vektora: ";
    std::cin >> n;

    Vektor z;

    std::cout << "Unesite elemente prvog vektora: ";

    for(int i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        z.push_back(input);
    }

    int m;

    std::cout << "Unesite broj elemenata drugog vektora: ";
    std::cin >> m;

    Vektor y;

    std::cout << "Unesite elemente drugog vektora: " << std::endl;

    for(int i = 0; i < m; i++) {
        int input;
        std::cin >> input;
        y.push_back(input);
    }

    Matrica Kroneckerov = KroneckerovProizvod(z, y);

    for(auto i : Kroneckerov) {
        for(auto j : i) std::cout << std::right << std::setw(NajvecaSirina(Kroneckerov) + 1) << j;
        std::cout << std::endl;
    }

    return 0;
}

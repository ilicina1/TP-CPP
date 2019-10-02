#include <iostream>
#include <vector>
#include <deque>

template <typename tipPrvi, typename tipDrugi, typename tipTreci>
int PopuniPoKriteriju(tipPrvi p1, tipPrvi p2, tipDrugi p3, tipDrugi p4, tipTreci f)
{
    int suma = 0;
    for(auto i = p1; i != p2; i++) suma += *i;
    for(auto i = p1; i != p2; i++) {
        *p3 = f(*i);
        p3++;
    }
    
    return suma;
}

int main()
{
    std::cout << "Unesite velicinu vektora: ";
    int n;
    std::cin >> n;
    std::cout << "Unesite elemente vektora: " << std::endl;
    std::vector<int> vektor(n);
    for(int i = 0; i < n; i++) {
        std::cout << i + 1 << ". element: ";
        std::cin >> vektor.at(i);
    }
    std::deque<int> dek(n);
    int suma(0);
    suma = PopuniPoKriteriju(vektor.begin(), vektor.end(), dek.begin(), dek.end(), [](int &a) {
        a = a*a;
        return a;
    });
    std::cout << suma << std::endl;
    for(int i = 0; i < dek.size(); i++) std::cout << dek.at(i) << " ";
    return 0;
}

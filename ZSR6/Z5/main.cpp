//TP 2018/2019: ZSR 6, Zadatak 5
#include <iostream>
#include <vector>

double *funkcija(std::vector<double> vektor)
{
    double *niz = new double[vektor.size()];
    for(int i = 0; i < vektor.size(); i++) niz[i] = vektor.at(i);
    return niz;
}

int main ()
{
    std::vector<double> vektor{1,2,3,4,5,6,7,8,9,0};
    double *niz = funkcija(vektor);
    for(int i = 0; i < vektor.size(); i++) std::cout << niz[i] << "  ";
    return 0;
}

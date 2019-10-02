//TP 2018/2019: ZSR 5, Zadatak 36
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main ()
{
    std::vector<double> vektor;
    for(int i = 0; i < 100; i++) vektor.push_back(i * i);
    std::transform(vektor.begin(), vektor.end(), vektor.begin(), [](double a){
        return fmod(a, 42);
    });
    std::sort(vektor.begin(), vektor.end());
    std::cout << "Unesite broj koji se pretrazuje: ";
    int broj;
    std::cin >> broj;
    if(std::binary_search(vektor.begin(), vektor.end(), broj)) std::cout << "Broj se nalazi u vektoru!";
    else std::cout << "Broje se ne nalazi u vektoru!";
	return 0;
}
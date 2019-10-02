#include <iostream>
#include <vector>
#include <functional>
#include <cmath>

std::function<double(double)> Polinom(std::vector<double> vektor)
{
    return [&vektor](int  a) {
        double b = 0;
        for(int i = 0; i < vektor.size(); i++) {
            if(i == 0) b += vektor.at(i);
            else {
                b += vektor.at(i) * pow(a, i);
            }
        }
        return b;
    };
}

int main()
{
    std::vector<double> vektor(5);
    for(int i = 0; i < vektor.size(); i++) {
        std::cin >> vektor.at(i);
    }
    auto polinom = Polinom(vektor);
    std::cout << polinom(5);
}

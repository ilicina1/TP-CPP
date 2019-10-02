#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
    std::cout << "Unesite broj listi: ";
    int n;
    std::cin >> n;
    std::cout << "Unesite broj elemenata listi: ";
    int nElemenata;
    std::cin >> nElemenata;
    std::vector<std::list<int>> vektor(n, std::list<int>(nElemenata));
    for(int i = 0; i < n; i++) {
        for(auto j = vektor.at(i).begin(); j != vektor.at(i).end(); j++) {
            int a = 0;
            std::cin >> a;
            std::swap(*j, a);
        }
    }

    std::sort(vektor.begin(), vektor.end(), [](std::list<int> a, std::list<int> b) {
        int sum1 = 0;
        int sum2 = 0;
        for (auto elem : a) sum1 += elem;
        for (auto elem : b) sum2 += elem;
        return sum1 < sum2;
    });
    std::cout << std::endl;
    for(int i = 0; i < vektor.size(); i++) {
        for(auto j = vektor.at(i).begin(); j != vektor.at(i).end(); j++) {
            std::cout << *j << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

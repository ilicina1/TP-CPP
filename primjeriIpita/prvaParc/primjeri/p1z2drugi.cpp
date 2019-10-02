#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
    int brListi, brElem;
    std::cout << "Unesite broj listi: " << std::endl;
    std::cin >> brListi;
    std::cout << "Unesite broj elemenata: " << std::endl;
    std::cin >> brElem;
    std::vector<std::list<int>> vektor(brListi, std::list<int>(brElem));
    for(int i = 0;  i < brListi; i++) {
        for(auto j = vektor.at(i).begin(); j != vektor.at(i).end(); j++){
            int x = 0;
            std::cin >> x;
            std::swap(*j, x);
        }
    }
    
    std::sort(vektor.begin(), vektor.end(), [](std::list<int> a, std::list<int> b){
        int suma1 = 0, suma2 = 0;
        for(auto elem : a) suma1 += elem;
        for(auto elem : b) suma2 += elem;
        return suma1 < suma2;
    });
    
    for(int i = 0;  i < brListi; i++) {
        for(auto j = vektor.at(i).begin(); j != vektor.at(i).end(); j++){
            std::cout << *j << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}

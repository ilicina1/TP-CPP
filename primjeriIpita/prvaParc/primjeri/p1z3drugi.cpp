#include <iostream>
#include <vector>
#include <cmath>

std::vector<bool> funkcija(std::vector<int> vektor)
{
    std::vector<bool> rezultat;
    for(int i = 0; i < vektor.size(); i++) {
        if(vektor.at(i) < 0) throw std::domain_error("Negativan broj!");
        int kjub = 0;
        kjub = std::cbrt(vektor.at(i));
        if(vektor.at(i) == kjub * kjub * kjub) {
            rezultat.push_back(true);
            continue;
        } else{
            rezultat.push_back(false);
        }
    }
    return rezultat;
}

int main()
{
    std::vector<int> vektor{216, 27, 8, 21, 11, 242};
    std::vector<bool> boolovi = funkcija(vektor);
    for(int i = 0; i < boolovi.size(); i++) std::cout << boolovi.at(i) << " ";
}

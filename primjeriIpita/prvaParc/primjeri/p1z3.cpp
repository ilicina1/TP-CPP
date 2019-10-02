#include <iostream>
#include <vector>
#include <cmath>

std::vector<bool> nekaFunkcija(std::vector<int> vektor){
    std::vector<bool> boolovi;
    for(int i = 0; i < vektor.size(); i++){
        int kjub(round(cbrt(vektor.at(i))));
        if(vektor.at(i) == kjub * kjub * kjub) boolovi.push_back(true);
        else boolovi.push_back(false);
    }
    return boolovi;
}

int main()
{
    std::vector<int> vektor{216, 27, 8, 21, 11, 242};
    std::vector<bool> boolovi = nekaFunkcija(vektor);
    for(int i = 0; i < boolovi.size(); i++) std::cout << boolovi.at(i) << " ";
}

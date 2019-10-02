#include <iostream>
#include <vector>

bool funkcija(std::vector<std::vector<double>> matrica)
{
    std::vector<std::vector<double>> drugaMat(matrica.size(), std::vector<double>(matrica.at(0).size()));
    for(int i = 0; i < matrica.size(); i++) {
        for(int j = 0; j < matrica.at(i).size(); j++) {
            for(int k = 0; k < matrica.size(); k++) {
                drugaMat[i][j] += matrica.at(i).at(k) * matrica.at(k).at(j);
            }
        }
    }

    for(int i = 0; i < drugaMat.size(); i++) {
        for(int j = 0; j < drugaMat.at(i).size(); j++) {
            if(matrica.at(i).at(j) != drugaMat.at(i).at(j)) return false;
        }
    }
    return true;
}

int main()
{
    std::cout << "Unesite br redova: ";
    int brRedova = 0;
    std::cin >> brRedova;
    std::cout << "Unesite br kolona: ";
    int brKolona = 0;
    std::cin >> brKolona;
    std::vector<std::vector<double>> matrica(brRedova, std::vector<double>(brKolona));
    for(int i = 0; i < brRedova; i++) {
        for(int j = 0; j < brKolona; j++) {
            std::cin >> matrica.at(i).at(j);
        }
    }
    bool f = funkcija(matrica);
    std::cout << f;
    return 0;
}

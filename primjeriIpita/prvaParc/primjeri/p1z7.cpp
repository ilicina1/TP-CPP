#include <iostream>
#include <vector>
#include <deque>

std::deque<double> funkcija(std::vector<std::vector<double>> &matrica)
{
    std::deque<double> dek;
    for(int i = 0; i < matrica.size(); i++){
        double suma = 0;
        for(int j = 0; j < matrica.at(i).size(); j++){
            suma += matrica.at(i).at(j);
        }
        dek.push_back(suma);
    }
    for(int i = 0; i < matrica.size(); i++){
        for(int j = 0; j < matrica.at(i).size() / 2 ; j++){
            double a = 0;
            a = matrica.at(i).at(j);
            matrica.at(i).at(j) = matrica.at(i).at(matrica.at(i).size() - (j + 1));
            matrica.at(i).at(matrica.at(i).size() - (j + 1)) = a;
        }
    }
    return dek;
}

int main()
{
    std::vector<std::vector<double>> matriconi(5, std::vector<double>(5));
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            std::cin >> matriconi.at(i).at(j);
        }
    }
    std::deque<double> dek;
    dek = funkcija(matriconi);
    for(int i = 0; i < dek.size(); i++){
        std::cout << dek.at(i) << " " << std::endl;
    }
    for(int i = 0; i < matriconi.size(); i++){
        for(int j = 0; j < matriconi.at(i).size(); j++){
            std::cout << matriconi.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

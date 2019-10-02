//TP 2018/2019: ZSR 6, Zadatak 13
#include <iostream>
#include <vector>

template <typename nekiTip>
nekiTip **KreirajMatricu(std::vector<std::vector<nekiTip>> matrica)
{
    nekiTip **b;
    try {
        b = new nekiTip*[matrica.size()];
        b[0] = new nekiTip[matrica.size() * matrica.at(0).size()];
        for(int i = 1; i < matrica.size(); i++) b[i] = b[i - 1] + matrica.at(i).size();
        for(int i = 0; i < matrica.size(); i++) {
            for(int j = 0; j < matrica.at(i).size(); j++) {
                b[i][j] = matrica.at(i).at(j);
            }
        }
        
    } catch (std::bad_alloc) {
        std::cout << "Allocation failed: " << '\n';
    }
    return b;
}

int main ()
{
    std::cout << "Broj redova: ";
    long long int redovi;
    std::cin >> redovi;
    std::cout << "Broj kolona: ";
    long long int kolona;
    std::cin >> kolona;
    std::vector<std::vector<long long int>> matrica(redovi, std::vector<long long int> (kolona));
    for(int i = 0; i < redovi; i++) {
        for(int j = 0; j < kolona; j++) {
            std::cin >> matrica.at(i).at(j);
        }
    }
    long long int **a = KreirajMatricu(matrica);
    for(int i = 0; i < redovi; i++) {
        for(int j = 0; j < kolona; j++) {
            std::cout << a[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    return 0;
}

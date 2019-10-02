//TP 2018/2019: ZSR 6, Zadatak 15
#include <iostream>
#include <vector>

template <typename nekiTip>
nekiTip **nekaFunkcija(std::vector<std::vector<nekiTip>> grbavaMatrica)
{
    nekiTip **a;
    try{
        a = new nekiTip*[grbavaMatrica.size()];
        for(int i = 0; i < grbavaMatrica.size(); i++) a[i] = new nekiTip[grbavaMatrica.at(i).size()];
    } catch(std::bad_alloc){
        std::cout << "Allocation failed!" << std::endl;
    }
    for(int i = 0; i < grbavaMatrica.size(); i++){
        for(int j = 0; j < grbavaMatrica.at(i).size(); j++) a[i][j] = grbavaMatrica.at(i).at(j);
    }
    return a;
}

int main ()
{
    std::cout << "Broj redova: ";
    int redovi;
    std::cin >> redovi;
    std::vector<std::vector<int>> matrica(redovi);
    for(int i = 0; i < redovi; i++) {
        int x = 0;
        std::cout << "Koliko zelite kolona u " << i + 1 << ". redu: ";
        std::cin >> x;
        matrica.at(i).resize(x);
    }
    for(int i = 0; i < redovi; i++) {
        for(int j = 0; j < matrica.at(i).size(); j++) {
            std::cin >> matrica.at(i).at(j);
        }
    }
    int **a = nekaFunkcija(matrica);
    for(int i = 0; i < redovi; i++) {
        for(int j = 0; j < matrica.at(i).size(); j++) {
            std::cout << a[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    return 0;
}

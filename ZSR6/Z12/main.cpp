//TP 2018/2019: ZSR 6, Zadatak 12
#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> Matrica;

template <typename nekiTip>
nekiTip **funkcija(std::vector<std::vector<nekiTip>> a){
    nekiTip **b = new nekiTip *[a.size()];
    for(int i = 0; i < a.size(); i++) b[i] = new nekiTip[a.at(i).size()];
    for(int i = 0; i < a.size(); i++){
         for(int j = 0; j < a.at(i).size(); j++){
           b[i][j] = a.at(i).at(j);
         }
    }
    return b;
}

int main ()
{
    Matrica a(5, std::vector<int> (10));
    for(auto &i : a){
        for(auto &j : i){
            j = 1;
        }
    }
    int **b = funkcija(a);
    
    for(int i = 0; i < a.size(); i++){
         for(int j = 0; j < a.at(i).size(); j++){
           std::cout << b[i][j] << " ";
         }
         std::cout << std::endl;
    }
    
	return 0;
}
//TP 2018/2019: ZSR 4, Zadatak 15
#include <iostream>
#include <vector>
bool funkcija(double niz[], int br, int &br_negativnih, int &br_pozitivnih)
{
    for(int i = 0; i < br; i++){
        if(niz[i] >= 0) br_pozitivnih++;
        if(niz[i] < 0) br_negativnih++;
    }
    std::vector<double> vektor;
    for(int i = 0; i < br; i++){
        if(niz[i] == 0){
            vektor.push_back(niz[i]);
        }
    }
    if(vektor.size() > 1) return false;
    return true;
}

int main ()
{
    double niz[20] = {-1, 0, 3, 4, 5, 6, 7, 8, 9, -1, -22, -221, -42, 21, 12, -21, -1, -2, -2, -2};
    int br_pozitivnih = 0;
    int br_negativnih = 0;
    bool ra = funkcija(niz, 20, br_negativnih, br_pozitivnih);
    std::cout << "Niz ima " << br_pozitivnih << " pozitivnih brojeva i " << br_negativnih << " negativnih brojeva." << std::endl;
    if(ra) std::cout << "Niz u sebi cuva jednu ili niti jednu jedinicu";
    if(!ra) std::cout << "Niz u sebi cuva vise od jedne jedinice";
    return 0;
}

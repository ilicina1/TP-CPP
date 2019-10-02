//TP 2018/2019: ZSR 5, Zadatak 10
#include <iostream>

template <typename nekiTip>
void funkcija(nekiTip *niz, int broj_elemenata, nekiTip &najmanji, nekiTip &prviKojiSlijedi)
{
    bool da = false;
    for(int i = 0; i < broj_elemenata; i++){
        for(int j = 0; j < broj_elemenata; j++) if(niz[i] != niz[j]) da = true;
        if(!da) throw std::logic_error("Elementi su isti!");
    }
    if(niz[0] < niz[1]){
        najmanji = niz[0];
        prviKojiSlijedi = niz[1];
    } else {
        najmanji = niz[1];
        prviKojiSlijedi = niz[0];
    }
    for(int i = 0; i < broj_elemenata; i++){
        if(najmanji > niz[i]) {
            prviKojiSlijedi = najmanji;
            najmanji = niz[i];
        } else if(niz[i] < prviKojiSlijedi && niz[i] != najmanji){
            prviKojiSlijedi = niz[i];
        }
    }
 
}

int main ()
{
    int najmanji = 0;
    int prviKojiSlijedi = 0;
    std::cout << "Unesite broj elemenata niza: ";
    int broj_elemenata;
    std::cin >> broj_elemenata;
    int *niz = new int[broj_elemenata];
    std::cout << "Unesite elemente niza: ";
    for(int i = 0; i < broj_elemenata; i++) std::cin >> niz[i];
    funkcija(niz, broj_elemenata, najmanji, prviKojiSlijedi);
    std::cout << najmanji << "  " << prviKojiSlijedi;
    return 0;
}

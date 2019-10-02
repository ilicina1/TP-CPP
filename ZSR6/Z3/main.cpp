//TP 2018/2019: ZSR 6, Zadatak 3
#include <iostream>

template <typename nekiTip>
nekiTip *KreirajNiz(int broj_elemenata, nekiTip vrijednosti)
{
    try {
        nekiTip *niz = new nekiTip[broj_elemenata];

        for(int i = 0; i < broj_elemenata; i++) {
            niz[i] = vrijednosti;
        }

        return niz;
    } catch(...) {
        throw std::logic_error("Kreiranje nije uspjelo");
    }
}

int main ()
{
    const char **niz = KreirajNiz(12, "c");
    for(int i = 0; i < 10; i++) std::cout << niz[i] << "  ";
    return 0;
}

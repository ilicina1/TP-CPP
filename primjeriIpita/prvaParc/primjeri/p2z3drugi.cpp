#include <iostream>

template <typename prviTip, typename drugiTip>
    prviTip funkcija(prviTip p1, prviTip p2, drugiTip p3, drugiTip p4){
        prviTip pom1 = p1;
        // prviTip pocetak = p1;
        drugiTip pom2 = p3;
        while(*p1 != *p2){
            pom1 = p1;
            while(*p1 == *p3){
                p1++;
                p3++;
            }
            if(*p3 == *p4){
                return pom1;
            }else{
                pom1++;
                p1 = pom1;
                p3 = pom2;
            }
        }
    return p1;
    }

int main()
{
    int niz[5] = {1, 2, 2, 4, 5};
    int niz2[2] = {3, 4};
    auto p = funkcija(niz, niz + 5, niz2, niz2 + 2);
    std::cout << *p;
}

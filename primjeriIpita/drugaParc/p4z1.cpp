#include <iostream>
#include <complex>
#include <list>

struct Kompleksni {
    double re, im;
    Kompleksni *sljedeci;
};

Kompleksni *KreirajListu(std::list<std::complex<double>> listaKompleksnih)
{
    Kompleksni *pocetak = nullptr;
    Kompleksni *prethodni;
    for(auto elem : listaKompleksnih) {
        Kompleksni *novi = new Kompleksni {real(elem), imag(elem), nullptr};
        if(!pocetak) pocetak = novi;
        else prethodni->sljedeci = novi;
        prethodni = novi;
       // std::cout <<realni<< " ";
    }

    return pocetak;
}

int main()
{
    std::list<std::complex<double>> listaKompleksnih{{1,2},{2,4},{3,6},{4,8},{5,10}};
    auto kompic = (KreirajListu(listaKompleksnih));
    std::cout << kompic->im;
   
    return 0;
}

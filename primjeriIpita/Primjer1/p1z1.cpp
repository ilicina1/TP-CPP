#include <iostream>
#include <list>
#include <complex>

struct Kompleksni {
    double re, im;
    Kompleksni *sljedeci;
};

Kompleksni *KreirajListu(std::list<std::complex<double>> kompleksni)
{
    Kompleksni *pocetak = nullptr, *prethodni;
    auto it = kompleksni.begin();
    for(int i = 0; i < kompleksni.size(); i++) {
        Kompleksni *novi = new Kompleksni{std::real(*it), std::imag(*it), nullptr};

        if(!pocetak) pocetak = novi;
        else prethodni->sljedeci = novi;
        prethodni = novi;
        it++;
    }
    return pocetak;
}

int main()
{
    std::list<std::complex<double>> a = {{1,2}, {2,2}, {3,1}};
    //auto it = a.begin();
    Kompleksni *lista = KreirajListu(a);
    for(int i = 0; i < a.size(); i++) {
        std::cout << lista->re << "," << lista->im << std::endl;
        lista = lista->sljedeci;
    }
}

//TP 2018/2019: ZSR 5, Zadatak 38
#include <iostream>
#include <complex>
#include <algorithm>

bool funkcija(std::complex<int> a, std::complex<int> b){
    if(a.imag() == b.imag()) return (a.real() < b.real());
    return (a.imag() < b.imag());
}

int main ()
{
    std::cout << "Unesite broj elemenata niza: ";
    int n;
    std::cin >> n;
    std::complex<int> *niz = new std::complex<int>[n];
    std::cout << "Unesite kompleksne brojeve: ";
    for(int i = 0; i < n; i++){
        int imaginaran, realan;
        std::cout << "Imag_" << i + 1 << ": ";
        std::cin >> imaginaran;
        niz[i].imag(imaginaran);
        std::cout << "Real_" << i + 1 << ": ";
        std::cin >> realan;
        niz[i].real(realan);
    }
    std::sort(niz, niz + n, funkcija);
    for(int i = 0; i < n; i++) std::cout << "(" << niz[i].imag() << "," << niz[i].real() << ") ";
	return 0;
}
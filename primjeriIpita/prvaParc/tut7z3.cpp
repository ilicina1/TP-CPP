#include <iostream>
#include <cstring>
#include <algorithm>

int main()
{
    int broj_recenica;
    std::cout << "Unesite broj recenica: ";
    std::cin >> broj_recenica;
    std::cin.ignore(10000, '\n');

    std::string **niz;
    std::cout << "Unesite recenice: " << std::endl;
    try {
        niz = new std::string*[broj_recenica];
        for(int i = 0; i < broj_recenica; i++) {
            niz[i] = new std::string;
            std::getline(std::cin, *niz[i]);
        }
    } catch(std::bad_alloc) {
        std::cout << "Allocation failed" << std::endl;
    }

    std::sort(niz, niz + broj_recenica,  [] (const std::string *a, const std::string *b) {
        return *a < *b;
    });

    std::cout << "Sortirane recenice:" << std::endl;
    for(int i = 0; i < broj_recenica; i++) {
        std::cout << *niz[i] << std::endl;
    }
}

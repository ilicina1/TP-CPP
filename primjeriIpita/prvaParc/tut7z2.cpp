#include <iostream>
#include <cstring>
#include <algorithm>

int main()
{
    int broj_recenica;
    for(;;) {
        std::cout << "Unesite broj recenica: ";
        std::cin >> broj_recenica;
        std::cin.ignore(10000, '\n');
        if(broj_recenica <= 1000 && broj_recenica > 0) break;
    }
    char **niz;
    std::cout << "Unesite recenice: " << std::endl; 
    try {
        niz = new char*[broj_recenica];
        for(int i = 0; i < broj_recenica; i++) {
            char radniProstor[1000];
            std::cin.getline(radniProstor, sizeof radniProstor);
            niz[i] = new char[std::strlen(radniProstor) + 1];
            std::strcpy(niz[i], radniProstor);
        }
    } catch(std::bad_alloc) {
        std::cout << "Allocation failed" << std::endl;
    }
    
    std::sort(niz, niz + broj_recenica, [](const char *a, const char *b){
        return std::strcmp(a,b) < 0;
    });
    
    std::cout << "Sortirane recenice:" << std::endl;
    for(int i = 0; i < broj_recenica; i++){
        for(int j = 0; j < std::strlen(niz[i]); j++) std::cout << niz[i][j];
        std::cout << std::endl;
    }
}

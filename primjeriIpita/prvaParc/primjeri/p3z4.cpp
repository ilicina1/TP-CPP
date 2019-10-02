#include <iostream>
#include <string.h>
#include <algorithm>

int main()
{
    int brRecenica = 0;
    std::cout << "Unesite broj recenica: ";
    std::cin >> brRecenica;
    char **niz;
    try {
        niz = new char*[brRecenica];
        for(int i = 0; i < brRecenica; i++) niz[i] = new char[100];
    } catch(...) {
        throw std::logic_error("nema mista");
    }

    for(int i = 0; i < brRecenica; i++) {
        std::cout << "Unesite " << i+1 << ". recenicu: ";
        char str[100];
        std::cin.getline(str, 100, '\n');
        strcpy(niz[i], str);
    }
    std::sort(niz, niz+brRecenica, [](char *a, char *b){
        return a[0]<b[0];
    });
    for(int i = 0; i < brRecenica; i++) {
        std::cout << niz[i] << "\n";
    }
    return 0;
}
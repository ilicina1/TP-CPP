#include <iostream>
#include <algorithm>
#include <memory>

typedef std::shared_ptr<std::string> pametni;

int main()
{
    int broj_recenica;
    std::cout << "Unesite broj recenica: ";
    std::cin >> broj_recenica;
    std::cin.ignore(10000, '\n');
    try {
        auto niz = std::shared_ptr<pametni[]>(new pametni[broj_recenica]);
        std::cout << "Unesite recenice: " << std::endl;

        for(int i = 0; i < broj_recenica; i++) {
            niz[i] = pametni(new std::string);
            std::getline(std::cin, *niz[i]);
        }
        
        std::cout << "Sortirane recenice:" << std::endl;
        for(int i = 0; i < broj_recenica; i++) {
            std::cout << *niz[i] << std::endl;
        }
    } catch(std::bad_alloc) {
        std::cout << "Allocation failed" << std::endl;
    }
}

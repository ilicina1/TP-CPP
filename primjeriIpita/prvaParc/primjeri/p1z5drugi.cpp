#include <iostream>
#include <string>

std::string **funkcija(std::string **niz, int &n, std::string str)
{
    std::string *s = new std::string;
    *s = str;
    for(int i = 0; i < n; i++) {
        if(niz[i] == nullptr) {
            niz[i] = s;
            n++;
            return niz;
        }
    }

    std::string **niz2;

    try {
        niz2 = new std::string*[n + 10];
        for(int i = 0; i < n + 10; i++) niz2[i] = new std::string;
        for(int i = 0; i < n; i++) niz2[i] = niz[i];
        for(int i = n; i < n + 10; i++) niz2[i] = nullptr;
        for(int i = 0; i < n + 10; i++) {
            if(niz2[i] == nullptr) {
                niz2[i] = s;
                for(int i = 0; i < n; i++) delete[] niz[i];
                delete[] niz;
                niz = niz2;
            }
        }
    } catch(...) {
        for(int i = 0; i < n; i++) delete[] niz[i];
        delete[] niz;
    }
    n++;
    return niz;
}

int main()
{
    std::cout << "Unesite broj stringova: ";
    int n;
    std::cin >> n;
    std::string **str;
    try {
        str = new std::string*[n];
        for(int i = 0; i < n; i++) str[i] = new std::string;
        //for(int i = 0; i < n; i++) str[i] = nullptr;
    } catch(std::logic_error) {
        std::cout << "Allocation failed!" << std::endl;
    }
    for(int i = 0; i < n; i++){
        std::string pomocni = "";
        std::getline(std::cin, pomocni);
        *str[i] = pomocni;
    }
    
    str = funkcija(str, n, "ilhan licina");
    
    for(int i = 0; i < n; i++){
        std::cout << *str[i] << std::endl;
    }
 
}

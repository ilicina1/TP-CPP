#include <iostream>
#include <string>

std::string **DinString(int n)
{
    std::string **a;
    try {
        a = new std::string*[n];
        for(int i = 0; i < n; i++) a[i] = new std::string;
    } catch(std::bad_alloc) {
        std::cout << "Allocation failed!" << std::endl;
    }

    return a;
}

std::string **drugaFunkcija(std::string **niz, int n, std::string a)
{
    bool ima = false;
    std::string *s = new std::string;
    *s = a;
    for(int i = 0; i < n; i++) {
        if(niz[i] == nullptr) {
            niz[i] = s;
            ima = true;
            return niz;
        }
    }
    std::string **niz2;
    if(!ima) {
        try {
            niz2 = new std::string*[n + 10];
            for(int i = 0; i < n+10; i++) niz2[i] = new std::string;
            for(int i = 0; i < n; i++) niz2[i] = niz[i];
            for(int i = n; i < n + 10; i++) niz2[i] = nullptr;
        } catch(...) {
            throw std::logic_error("Nevaljana alokacija!");
            for(int i = 0; i < n; i++) delete[] niz[i];
            delete[] niz;
        }
        for(int i = 0; i < n + 10; i++) {
            if(niz2[i] == nullptr) {
                niz2[i] = s;
            }
        }
        for(int i = 0; i < n; i++) delete[] niz[i];
        delete[] niz;
    }
    return niz2;
}

int main()
{
    std::cout << "Unesite broj stringova: ";
    int n;
    std::cin >> n;
    std::string **a = DinString(n);
    for(int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        *a[i] = s;
    }
    std::string str = "ilhan je najjaci";
    std::string **b = drugaFunkcija(a, n, str);
    for(int i = 0; i < n+1; i++) std::cout << *b[i] << std::endl;
}

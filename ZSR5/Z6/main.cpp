//TP 2018/2019: ZSR 5, Zadatak 6
#include <iostream>
#include <cstring> 

bool DaLiJePalindrom(char niz[])
{
    int length = strlen(niz);
    char *pok = niz + (length - 1);
    char *poka = niz;
    for(int i = 0; i < length; i++){
        if(*poka != *pok) return false;
        
    }
    return true;
}

int main ()
{
    char niz[5];
    std::cout << "Enter a string: ";
    std::cin >> niz;
    bool dane = DaLiJePalindrom(niz);
    if(dane) std::cout << "String je palindrom!";
    else std::cout << "String nije palindrom!";
    return 0;
}

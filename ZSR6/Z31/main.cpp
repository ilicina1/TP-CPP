//TP 2018/2019: ZSR 6, Zadatak 31
#include <iostream>

char **nekaFunkcija(int n, char **&p2)
{
    if(n <= 0) throw std::domain_error("Pogresan parametar");
    
    char **p1;
    
    try {
        p1 = new char*[n];
        p1[0] = new char[n * n];
        for(int i = 1; i < n; i++) p1[i] = p1[i - 1] + i;
    } catch(std::bad_alloc) {
        delete[] p1[0];
        delete[] p1;
        std::cout << "Allocation failed" << std::endl;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < (i + 1); j++) p1[i][j] = '*';
    }

    try {
        p2 = new char*[n];
        for(int i = 0; i < n; i++) p2[i] = new char[n - i];
    } catch(std::bad_alloc) {
        for(int i = 0; i < n; i++) delete[] p2[i];
        delete[] p2;
        std::cout << "Allocation failed" << std::endl;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < (n - i); j++) p1[i][j] = '*';
    }
    
    return p1;
}

int main ()
{   
    char **p2;
    char **p1 = nekaFunkcija(10, p2);
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < (i + 1); j++) std::cout << p1[i][j];
        std::cout << std::endl;
    }
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < (10 - i); j++) std::cout << p1[i][j];
        std::cout << std::endl;
    }
    
    return 0;
}

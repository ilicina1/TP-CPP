//TP 2018/2019: ZSR 6, Zadatak 19
#include <iostream>
#include <iomanip>

int **KreirajMatricuKontinualno(int n)
{
    if(n <= 0) throw std::domain_error("Brate ovo ne valja");
    int **a;
    try {
        a = new int*[n];
        a[0] = new int[n * n];
        for(int i = 1; i < n; i++) {
            if(i == 1) a[i] = a[i - 1] + 1;
            else a[i] = a[i - 1] + (i-1) + ((i-1) + 1);
        }
    } catch(const std::bad_alloc &e) {
        std::cout << e.what();
    }

    for(int i = 0; i < n; i++) {
        int k = 2;
        for(int j = 0; j <= i + (i + 1); j++) {
            if(j <= i) a[i][j] = (i + 1) - j;
            if(j > i) {
                a[i][j] = k;
                ++k;
            }
        }
    }
    return a;
}

int **KreirajMatricuFragmentirano(int n)
{
    if(n <= 0) throw std::domain_error("Brate ovo ne valja");
    int **a;
    try {
        a = new int*[n];
        for(int i = 0; i < n; i++) {
            a[i] = new int[i + (i + 1)];
        }
    } catch(const std::bad_alloc &e) {
        std::cout << e.what();
    }

    for(int i = 0; i < n; i++) {
        int k = 2;
        for(int j = 0; j <= i + (i + 1); j++) {
            if(j <= i) a[i][j] = (i + 1) - j;
            if(j > i) {
                a[i][j] = k;
                ++k;
            }
        }

    }
    return a;
}

int main ()
{
    int **a = KreirajMatricuKontinualno(6);
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < i + (i + 1); j++) {
            std::cout << std::setw(3) << a[i][j];
        }
        std::cout << std::endl;
    }

    delete[] a[0];
    delete[] a;
    
    std::cout << std::endl;
    
    int **b = KreirajMatricuFragmentirano(9);
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < i + (i + 1); j++) {
            std::cout << std::setw(3) << b[i][j];
        }
        std::cout << std::endl;
    }

    for(int i = 0; i <  9; i++) delete[] b[i];
    delete[] b;
    return 0;
}

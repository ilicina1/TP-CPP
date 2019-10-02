//TP 2018/2019: ZSR 6, Zadatak 16
#include <iostream>
#include <iomanip>

int **nekaFunkcija(int n)
{
    int **a;
    try {
        a = new int*[n];
        a[0] = new int[n * n];
        for(int i = 1; i < n; i++) a[i] = a[i - 1] + n;
    } catch(std::bad_alloc) {
        std::cout << "Allocation failed!" << std::endl;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = (i + 1) * (j + 1);
        }
    }
    
    return a;
}

int main ()
{
    int **a = nekaFunkcija(10);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            std::cout << std::setw(5) << a[i][j];
        }
        std::cout << std::endl;
    }
    delete[] a[0];
    delete[] a;
    return 0;
}

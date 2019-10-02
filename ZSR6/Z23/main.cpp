//TP 2018/2019: ZSR 6, Zadatak 23
#include <iostream>
#include <iomanip>

int **nekaFunkcija(int n)
{
    if(n <= 0) throw std::domain_error("Pogresan parametar");
    int **a;
    try {
        a = new int*[n];
        a[0] = new int[n * n];
        for(int i = 1; i < n; i++) a[i] = a[i - 1] + i;
    } catch(std::bad_alloc) {
        delete[] a[0];
        delete[] a;
        std::cout << "Allocation failed";
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i + 1; j++) {
            if(j == 0 || j == i) a[i][j] = 1;
            else if(i > 1) {
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            }
        }
    }
    return a;
}

int main ()
{
    int **a = nekaFunkcija(10);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < i + 1; j++) std::cout << std::setw(4) << a[i][j];
        std::cout << std::endl;
    }
    return 0;
}


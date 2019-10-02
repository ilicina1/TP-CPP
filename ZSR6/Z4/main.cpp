//TP 2018/2019: ZSR 6, Zadatak 4
#include <iostream>

int *nekaFunkcija(int n)
{
    int *a;
    try {
        a = new int[n];
    } catch(std::bad_alloc) {
        std::cout << "Allocation failed" << std::endl;
    }
    for(int i = 0; i < n; i++){
        a[i] = i + 1;
    }
    
    return a;
}

int main ()
{
    int *a = nekaFunkcija(10);
    for(int i = 0; i < 10; i++) std::cout << a[i] << " ";
    return 0;
}

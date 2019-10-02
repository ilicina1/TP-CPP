//TP 2018/2019: ZSR 6, Zadatak 10
#include <iostream>

template <typename nekiTip>
void KreirajMatricu(int n, nekiTip**& a)
{
    nekiTip **b = new nekiTip*[n];
    for(int i = 0; i < n; i++) b[i] = new nekiTip[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) b[i][j] = 1;
    }
    a = b;
}

int main ()
{
    int **a;
    KreirajMatricu(10, a);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) std::cout << a[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
}

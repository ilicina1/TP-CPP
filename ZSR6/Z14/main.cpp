//TP 2018/2019: ZSR 6, Zadatak 14
#include <iostream>

template <typename nekiTip>
void nekaFunkcija(nekiTip **&a, int m, int n, nekiTip v, bool mod)
{
    if(mod) {
        try{
        a = new nekiTip*[m];
        a[0] = new nekiTip[m * n];
        for(int i = 1; i < m; i++) a[i] = a[i - 1] + m;
        } catch(std::bad_alloc){
            std::cout << "Allocation failed!" << "\n";
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) a[i][j] = v;
        }
    }
    if(!mod) {
        try{
        a = new nekiTip*[m];
        for(int i = 0; i < m; i++) a[i] = new nekiTip[n];
        } catch(std::bad_alloc){
            std::cout << "Allocation failed!" << "\n";
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) a[i][j] = v;
        }
    }
    
}

int main ()
{
    int **a;
    nekaFunkcija(a, 3, 3, 0, true);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << a[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    delete[] a[0]; delete[] a;
    
    int **b;
    nekaFunkcija(b, 3, 3, 0, false);
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << b[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    
    for(int i = 0; i < 3; i++) delete[] b[i];
    delete[] b;
    
    return 0;
}

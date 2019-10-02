//TP 2018/2019: ZSR 6, Zadatak 17
#include <iostream>
#include <iomanip>

int **nekaFunkcija(int n)
{
    if(n <= 0) throw std::domain_error("Brate ovo ne valja");
    int **a;
    try {
        a = new int*[n];
        for(int i = 0; i < n; i++) {
            a[i] = new int[i + (i + 1)];
        }
    } catch(std::bad_alloc) {
        std::cout << "Allocation failed" << std::endl;
    }

    for(int i = 0; i < n; i++) {
        int k = i;
        for(int j = 0; j <= i + (i + 1); j++) {
            if(j <= i) a[i][j] = j + 1;
            if(j > i) {
                a[i][j] = k;
                --k;
            }
        }
        // for(int j = 0; j < j; j++) {
        //     if(i == 0) break;
        //     if(j > i + 2) break;
        //     a[i][j] = j;
        // }
    }
    return a;
}

int main ()
{
    int **a = nekaFunkcija(6);
    std::cout << std::setw(3) << a[0][0] << std::endl;
    int brojac = 0;
    for(int i = 1; i < 6; i++) {
        for(int j = 0; j < i + 2 + brojac; j++) {
            std::cout << std::setw(3) << a[i][j];
        }
        brojac++;
        std::cout << std::endl;
    }

    for(int i = 0; i < 3; i++) delete[] a[i];
    delete[] a;
    return 0;
}

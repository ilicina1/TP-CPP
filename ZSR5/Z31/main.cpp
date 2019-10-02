//TP 2018/2019: ZSR 5, Zadatak 31
#include <iostream>

template <typename nekiTip, typename Comp>
nekiTip max_element(nekiTip p1, nekiTip p2, Comp comp){
    nekiTip najveci = p1;
    ++p1;
    for(; p1 != p2; ++p1){
        if(comp(*p1, *najveci)) najveci = p1;
    }
    return najveci;
}

int main ()
{
    int niz[10] {1, 2, 3, 4, 5, 65, 7, 8, 0, 5};
    int *p = max_element(niz, niz + 10, [](int a, int b){
        return (a>b);
    });
    std::cout << *p;
	return 0;
}
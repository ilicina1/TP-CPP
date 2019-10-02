#include <iostream>
#include <list>
#include <queue>
#include <algorithm>

template <typename nekiTip, typename drugiTip>
bool funkcija(nekiTip p1, nekiTip p2, drugiTip p3, drugiTip p4)
{
    bool a = false;
    int brojac = 0;
    auto it = p3;
    while(it != p4){
        brojac++;
        it++;
    }
    int brojac2 = 0;
    for(auto i = p3; i != p4; i++){
        while(p1 !=p2){
            if(*i == *p1){
                a = true;
                brojac2++;
                p1++;
                break;
            } else {
                a = false;
                i = p3;
                brojac2 = 0;
                p1++;
            }
        }
        if(brojac == brojac2) break;
    }
    //nekiTip *pp = p1;
    return a;
}

int main()
{
    std::vector<int> a{1, 2, 3, 4, 5, 3, 2, 3, 1};
    std::vector<int> b{2, 3, 1};
    bool d = funkcija(a.begin(), a.end(), b.begin(), b.end());
    std::cout << d;
    return 0;
}

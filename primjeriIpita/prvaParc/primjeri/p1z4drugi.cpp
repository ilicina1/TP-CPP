#include <iostream>
#include <vector>
#include <deque>

template <typename prviTip, typename drugiTip, typename treciTip>
    int PopuniPoKriteriju(prviTip p1, prviTip p2, drugiTip p3, drugiTip p4, treciTip f){
        int suma = 0;
        for(auto i = p1; i != p2; i++) suma += *i;
        for(auto i = p1; i != p2; i++){
            *p3 = f(*i);
            p3++;
        }
        return suma;
    }

int main()
{
    std::cout << "Unesite broj elemenata vektora: ";
    int n;
    std::cin >> n;
    std::vector<int> vektor;
    std::cout << "Unesite elemente vektora: ";
    for(int i = 0; i < n; i++){
        int x = 0;
        std::cin >> x;
        vektor.push_back(x);
    }
    std::deque<int> dek(n); 
    int suma = PopuniPoKriteriju(vektor.begin(), vektor.end(), dek.begin(), dek.end(), [](int &a){
        a = a * a;
        return a;
    });
    
   // std::cout << suma << std::endl;
   //  std::cout << dek.at(0);
    for(int i = dek.size()-1; i >= 0; i--){
        std::cout << dek.at(i) << " ";
    }
    return 0;
}

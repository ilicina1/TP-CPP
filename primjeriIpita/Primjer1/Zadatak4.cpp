#include <iostream>
#include <vector>
#include <initializer_list>
#include <algorithm>

template <typename nekiTip>
class Skup{
    std::vector<nekiTip> elementi;
public:
    Skup(){}
    Skup(std::initializer_list<nekiTip> lista) {
       // auto it = lista.begin();
        bool dupli = false;
        for(auto it = lista.begin(); it != lista.end(); it++) {
            for(auto it2 = lista.begin(); it2 != it; it2++){
                if(*it2 == *it) dupli = true;
            }
            if(!dupli) elementi.push_back(*it);
            else dupli = false;
        }
        std::sort(elementi.begin(), elementi.end(), [](nekiTip a, nekiTip b){
            return a < b;
        });
    }
    void Ispisi() const {
        for(int i = 0; i < elementi.size(); i++) std::cout << elementi.at(i) << " ";
        std::cout << std::endl;
    }
    int Velicina() const { return elementi.size(); }
    void Dodaj(nekiTip elem) {
        bool dupli = false;
        for(int i = 0; i < elementi.size(); i++){
            if(elem == elementi.at(i)) dupli = true;
        }
        if(!dupli){
            elementi.push_back(elem);
            std::sort(elementi.begin(), elementi.end(), [](int a, int b){
                return a < b;
            });
        }
    }
    void Izbrisi(nekiTip elem){
        for(int i = 0; i < elementi.size(); i++){
            if(elem == elementi.at(i)){ 
                elementi.erase(elementi.begin() + i);
                i--;
            }
        }
    }
    bool ImaLiGa(nekiTip elem) const {
        for(int i = 0; i < elementi.size(); i++) if(elem == elementi.at(i)) return true;
        return false;
    }
};

int main()
{
    Skup<int> a = {5, 2, 3, 3};
    a.Izbrisi(2),
    a.Dodaj(1);
    std::cout << a.ImaLiGa(0) << std::endl;
    a.Ispisi();
}

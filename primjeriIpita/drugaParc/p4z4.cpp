#include <iostream>
#include <vector>
#include <algorithm>

// template <typename nekiTip>
class Skup
{
    std::vector<double> vektor;
public:
    Skup() : vektor(0) {}
    Skup(std::initializer_list<double> lista)
    {
        bool mali = false;
        for(auto it = lista.begin(); it != lista.end(); it++) {
            for(auto it2 = lista.begin(); it2 != it; it2++) {
                if(*it == *it2) {
                    mali = true;
                    break;
                }
            }
            if(!mali) {
                vektor.push_back(*it);
            } else if(mali) {
                mali = false;
            }
        }
    }
    void Ispisi() const
    {
        for(int i = 0; i < vektor.size(); i++) {
            std::cout << vektor.at(i) << " ";
        }
        std::cout << std::endl;
    }
    int Velicina() const { return vektor.size(); }
    void Dodaj(double elem){ 
        bool postoji = false;
        for(int i = 0; i < vektor.size(); i++){
            if(vektor.at(i) == elem) {
                postoji = true; 
                break;
            }
        }
        if(!postoji){
            vektor.push_back(elem); 
            std::sort(vektor.begin(),vektor.end(),[](double a, double b){
               return a<b; 
            });
        }
    }
    void Izbrisi(double elem){
        for(int i = 0; i < vektor.size(); i++){
            if(vektor.at(i) == elem) {
                vektor.erase(vektor.begin() + i);
                i--;
            }
        }
    }
    bool ImaLiGa(double elem){
        bool da = false;
        for(int i = 0; i < vektor.size(); i++){
            if(vektor.at(i) == elem) {
                da = true;
                break;
            } 
        }
        return da;
    }
};

int main()
{
    Skup a{1,2,3,4,5};
    a.Dodaj(3);
    a.Ispisi();
    a.Izbrisi(3);
    a.Ispisi();
    std::cout << a.Velicina() << std::endl;
    std::cout << a.ImaLiGa(0);
}

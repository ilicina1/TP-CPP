#include <iostream>
#include <vector>
#include <cmath>

class Polinom
{
    int stepen;
    std::vector<double> koeficijenti;
public:
    Polinom(int stepenPolinoma) : stepen(stepenPolinoma) {}
    double operator[](int i){
        if(i < 0 || i > stepen) throw std::logic_error("ode po cevape");
        return koeficijenti.at(i); 
    }
    double operator()(int argument){
        double rez = 0;
        for(int i = 0; i < koeficijenti.size(); i++){
            if(i == 0) rez += koeficijenti.at(i);
            else rez += koeficijenti.at(i) * pow(argument,i);
        }
        return rez;
      
    }
    
    friend Polinom operator +(const Polinom &p1, const Polinom &p2) {
        Polinom pom(p1.koeficijenti.size()-1);
        for(int i = 0; i < p1.koeficijenti.size(); i++){
            pom.koeficijenti.push_back(p1.koeficijenti.at(i) + p2.koeficijenti.at(i));
        }
        return pom;
    }
    friend Polinom operator +(const Polinom &p1, double broj) {
        Polinom pom(p1.koeficijenti.size()-1);
        pom.koeficijenti = p1.koeficijenti;
        pom.koeficijenti.at(0) += broj;
        return pom;
    }
    Polinom operator +=(const Polinom &p1){
        for(int i = 0; i < p1.koeficijenti.size(); i++){
            koeficijenti.at(i) += p1.koeficijenti.at(i);
        }
        return *this;
    }
    
    friend Polinom operator -(const Polinom &p1, const Polinom &p2) {
        Polinom pom(p1.koeficijenti.size()-1);
        for(int i = 0; i < p1.koeficijenti.size(); i++){
            pom.koeficijenti.push_back(p1.koeficijenti.at(i) - p2.koeficijenti.at(i));
        }
        return pom;
    }
    friend Polinom operator -(const Polinom &p1, double broj) {
        Polinom pom(p1.koeficijenti.size()-1);
        pom.koeficijenti = p1.koeficijenti;
        pom.koeficijenti.at(0) -= broj;
        return pom;
    }
    Polinom operator -=(const Polinom &p1){
        for(int i = 0; i < p1.koeficijenti.size(); i++){
            koeficijenti.at(i) -= p1.koeficijenti.at(i);
        }
        return *this;
    }
    
    friend Polinom operator *(const Polinom &p1, const Polinom &p2) {
        std::vector<double> koef;
        for(int i = 0; i < p1.koeficijenti.size(); i++){
            for(int j = 0; j < p2.koeficijenti.size(); j++){
                int rez = 0;
                rez = p1.koeficijenti.at(i) * p2.koeficijenti.at(j);
                if(i + j < j) {
                    koef.at(i + j) += rez;
                } else if(i + j > j){
                    koef.push_back(rez);
                }
            }
        }
        Polinom pom(koef.size()-1);
        pom.koeficijenti = koef;
        return pom;
    }
    friend Polinom operator *(const Polinom &p1, int broj) {
        Polinom pom(p1.koeficijenti.size()-1);
        pom.koeficijenti = p1.koeficijenti;
        for(int i = 0; i < p1.koeficijenti.size(); i++){
            pom.koeficijenti.at(i) = pom.koeficijenti.at(i) * broj;
        }
        return pom;
    }
    Polinom operator *=(const Polinom &p1){
       for(int i = 0; i < p1.koeficijenti.size(); i++){
            for(int j = 0; j < p1.koeficijenti.size(); j++){
                int rez = 0;
                rez = koeficijenti.at(i) * p1.koeficijenti.at(j);
                if(i + j < j) {
                    koeficijenti.at(i + j) += rez;
                } else if(i + j > j){
                    koeficijenti.push_back(rez);
                }
            }
        }
        return *this;
    }
    friend bool operator ==(const Polinom &p1, const Polinom &p2){
        bool jelIsti = true;
        for(int i = 0; i < p1.koeficijenti.size(); i++){
            if(p1.koeficijenti.at(i) != p2.koeficijenti.at(i)) jelIsti = false;
        }
        return jelIsti;
    }
    friend bool operator !=(const Polinom &p1, const Polinom &p2){
        bool jelIsti = true;
        for(int i = 0; i < p1.koeficijenti.size(); i++){
            if(p1.koeficijenti.at(i) == p2.koeficijenti.at(i)) jelIsti = false;
        }
        return jelIsti;
    }
    
    friend std::ostream &operator <<(std::ostream &tok, const Polinom &p1){
        tok << p1.koeficijenti.at(0) << " ";
        for(int i = 1; i < p1.koeficijenti.size(); i++){
            if(p1.koeficijenti.at(i) == 0){
                continue;
            } else if(p1.koeficijenti.at(i) < 1){
                tok << "- " << abs(p1.koeficijenti.at(i)) << " xˆ" << i << " ";
            }else{
                tok << "+ " << p1.koeficijenti.at(i) << " xˆ" << i << " ";
            }
        }
        return tok;
    }
    void DodajKoef(double koef) { koeficijenti.push_back(koef); }
    void Ispisi() const {
        for(int i = 0; i < koeficijenti.size(); i++){
            std::cout << koeficijenti.at(i) << " ";
        }
    }
};

int main()
{
    Polinom a(2);
    Polinom b(2);
    a.DodajKoef(2); a.DodajKoef(-5); a.DodajKoef(4); 
    b.DodajKoef(-1); b.DodajKoef(-7); b.DodajKoef(2);
    std::cout << a;
    // Polinom c(a * b);
    // a *= b;
    // if(!(a==b)) std::cout << "nisu isti";
    // std::cout << a(1) ;
    //std::cout << a(5);
    //std::cout << a[0];
    //a.Ispisi();
    return 0;
}

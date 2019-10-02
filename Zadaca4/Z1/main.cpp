//TP 2018/2019: Zadaća 4, Zadatak 1
#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

typedef std::pair<double, double> Tacka;

class Trougao
{
private:
    Tacka T1, T2, T3;
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) { 
        int orijentacija = Orijentacija(t1, t2, t3);
        if(orijentacija == 0) throw std::domain_error("Nekorektne pozicije tjemena");
        this->T1 = t1; this->T2 = t2; this->T3 = t3; 
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) { *this = Trougao(t1, t2, t3); }
    void Postavi(int indeks, const Tacka &t) { 
        if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
        if(indeks == 1) this->T1 = t;
        else if(indeks == 2) this->T2 = t;
        else if(indeks == 3) this->T3 = t;
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const { 
        if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
        if(indeks == 1) return T1;
        else if(indeks == 2) return T2;
        else if(indeks == 3) return T3;
    }
    double DajStranicu(int indeks) const {
        if(indeks == 1) return sqrt(pow((T3.first - T2.first), 2) + pow((T3.second - T2.second), 2));
        else if(indeks == 2) return sqrt(pow((T3.first - T1.first), 2) + pow((T3.second - T1.second), 2));
        else if(indeks == 3) return sqrt(pow((T2.first - T1.first), 2) + pow((T2.second - T1.second), 2));
        throw std::range_error("Nekorektan indeks");
    }
    double DajUgao(int indeks) const {
        if(indeks == 1) return acos((pow(DajStranicu(2), 2) + pow(DajStranicu(3), 2) - pow(DajStranicu(1), 2)) / (2 * DajStranicu(2) * DajStranicu(3)));
        else if(indeks == 2) return acos((pow(DajStranicu(1), 2) + pow(DajStranicu(3), 2) - pow(DajStranicu(2), 2)) / (2 * DajStranicu(1) * DajStranicu(3)));
        else if(indeks == 3) return acos((pow(DajStranicu(2), 2) + pow(DajStranicu(1), 2) - pow(DajStranicu(3), 2)) / (2 * DajStranicu(2) * DajStranicu(1)));
        if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
    }
    Tacka DajCentar() const {
        Tacka t;
        double x = (this->T1.first + this->T2.first + this->T3.first) / 3;
        double y = (this->T1.second + this->T2.second + this->T3.second) / 3;
        t.first = x; t.second = y;
        return t;
    }
    double DajObim() const { return DajStranicu(1) + DajStranicu(2) + DajStranicu(3); }
    double DajPovrsinu() const { return (T1.first * (T2.second - T3.second) - T2.first * (T1.second - T3.second) + T3.first * (T1.second - T2.second)) / 2.; }
    bool DaLiJePozitivnoOrijentiran() const {
        //int orijentacija = Orijentacija(this->T1, this->T2, this->T3);
        if(Orijentacija(this->T1, this->T2, this->T3) > 0) return true;
        else return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const { std::cout <<  "(" << "(" << T1.first << "," << T1.second << ")," << "(" << T2.first << "," << T2.second << ")," << "(" << T3.first << "," << T3.second << ")" << ")"; }
    void Transliraj(double delta_x, double delta_y) {
        this->T1.first += delta_x; this->T1.second += delta_y;
        this->T2.first += delta_x; this->T2.second += delta_y;
        this->T3.first += delta_x; this->T3.second += delta_y;
    }
    void Centriraj(const Tacka &t) {
        Tacka t2 = DajCentar();
        Tacka t3; 
        t3.first = t.first - t2.first; t3.second = t.second - t2.second;
        this->T1.first += t3.first; this->T1.second += t3.second; 
        this->T2.first += t3.first; this->T2.second += t3.second; 
        this->T3.first += t3.first; this->T3.second += t3.second; 
    }
    void Rotiraj(const Tacka &t, double ugao) {
        Tacka t1 = this->T1;
        this->T1.first = (t.first + (t1.first - t.first) * cos(ugao) - (t1.second - t.second) * sin(ugao));
        this->T1.second = (t.second + (t1.first - t.first) * sin(ugao) + (t1.second - t.second) * cos(ugao));
        Tacka t2 = this->T2;
        this->T2.first = (t.first + (t2.first - t.first) * cos(ugao) - (t2.second - t.second) * sin(ugao));
        this->T2.second = t.second + (t2.first - t.first) * sin(ugao) + (t.second - t.second) * cos(ugao);
        Tacka t3 = this->T3;
        this->T3.first = (t.first + (t3.first - t.first) * cos(ugao) - (t3.second - t.second) * sin(ugao));
        this->T3.second = (t.second + (t3.first - t.first) * sin(ugao) + (t3.second - t.second) * cos(ugao));
    }
    void Skaliraj(const Tacka &t, double faktor) {
        if(faktor == 0) throw std::domain_error("Nekorektan faktor skaliranja");
        this->T1.first = t.first + faktor * (T1.first - t.first);
        this->T1.second = t.second + faktor * (T1.second - t.second);
        this->T2.first = t.first + faktor * ( T2.first - t.first);
        this->T2.second = t.second + faktor * (T2.second - t.second);
        this->T3.first = t.first + faktor * (T3.first - t.first);
        this->T3.second = t.second + faktor * (T3.second - t.second);
    }
    void Rotiraj(double ugao) {
        Tacka t = DajCentar();
        Tacka t1 = this->T1;
        this->T1.first = (t.first + (t1.first - t.first) * cos(ugao) - (t1.second - t.second) * sin(ugao));
        this->T1.second = (t.second + (t1.first - t.first) * sin(ugao) + (t1.second - t.second) * cos(ugao));
        Tacka t2 = this->T2;
        this->T2.first = (t.first + (t2.first - t.first) * cos(ugao) - (t2.second - t.second) * sin(ugao));
        this->T2.second = t.second + (t2.first - t.first) * sin(ugao) + (t.second - t.second) * cos(ugao);
        Tacka t3 = this->T3;
        this->T3.first = (t.first + (t3.first - t.first) * cos(ugao) - (t3.second - t.second) * sin(ugao));
        this->T3.second = (t.second + (t3.first - t.first) * sin(ugao) + (t3.second - t.second) * cos(ugao));
    }
    void Skaliraj(double faktor) {
        if(faktor == 0) throw std::domain_error("Nekorektan faktor skaliranja");
        Tacka t = DajCentar();
        this->T1.first = t.first + faktor * (T1.first - t.first);
        this->T1.second = t.second + faktor * (T1.second - t.second);
        this->T2.first = t.first + faktor * ( T2.first - t.first);
        this->T2.second = t.second + faktor * (T2.second - t.second);
        this->T3.first = t.first + faktor * (T3.first - t.first);
        this->T3.second = t.second + faktor * (T3.second - t.second);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    return t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    bool x = false, y = false;
    
    if((t1.T1.first == t2.T1.first || t1.T1.first == t2.T2.first || t1.T1.first == t2.T3.first) && (t1.T2.first == t2.T1.first || t1.T2.first == t2.T2.first || t2.T1.first == t2.T3.first) && (t1.T3.first == t2.T1.first || t1.T3.first == t2.T2.first || t1.T3.first == t2.T3.first)) 
        x = true;
        
    if((t1.T1.second == t2.T1.second || t1.T1.second == t2.T2.second || t1.T1.second == t2.T3.second) && (t1.T2.second == t2.T1.second || t1.T2.second == t2.T2.second || t2.T1.second == t2.T3.second) && (t1.T3.second == t2.T1.second || t1.T3.second == t2.T2.second || t1.T3.second == t2.T3.second))
        y = true;
        
    if(x == true && y == true) return true;
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    bool stranice = false, uglovi = false;
    if((t1.DajStranicu(1) == t2.DajStranicu(1) || t1.DajStranicu(1) == t2.DajStranicu(2) || t1.DajStranicu(1) == t2.DajStranicu(3)) && (t1.DajStranicu(2) == t2.DajStranicu(1) || t1.DajStranicu(2) == t2.DajStranicu(2) || t1.DajStranicu(2) == t2.DajStranicu(3)) && (t1.DajStranicu(3) == t2.DajStranicu(1) || t1.DajStranicu(3) == t2.DajStranicu(2) || t1.DajStranicu(3) == t2.DajStranicu(3))) 
        stranice = true;
    if(stranice == true && uglovi == true){
        
    }
    //if(uglovi == true && stranice == true) return true;
    //return false;
    
    Trougao pomocni1 = t1, pomocni2 = t2;
    if(stranice == true && uglovi == true){
        //Tacka t = pomocni2.DajCentar();
        //t -= 1
        pomocni1.Centriraj(pomocni2.DajCentar());
        
        for(int i = 1; i <= 360; i++){
            pomocni1.Rotiraj(i);
            if((pomocni1.T1.first == pomocni2.T1.first && pomocni1.T1.second == pomocni2.T1.second) || (pomocni1.T1.first == pomocni2.T2.first && pomocni1.T1.second == pomocni2.T2.second) || (pomocni1.T1.first == pomocni2.T3.first && pomocni1.T1.second == pomocni2.T3.second)){
                if(pomocni1.T2.first == pomocni2.T1.first && pomocni1.T2.second == pomocni2.T1.second || (pomocni1.T2.first == pomocni2.T2.first && pomocni1.T2.second == pomocni2.T2.second) || (pomocni1.T2.first == pomocni2.T3.first && pomocni1.T2.second == pomocni2.T3.second)) return true;
            }
        }
    }
    return false;
}

int main ()
{
    
    int n;
    std::cout << "Koliko zelite kreirati trouglova:";
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> vektor(n);
    for(int i = 0; i < n; i++){
        Tacka t1, t2, t3;
        std::cout << "Unesite podatke za " << i + 1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin >> t1.first; std::cin >> t1.second;
        std::cin >> t2.first; std::cin >> t2.second;
        std::cin >> t3.first; std::cin >> t3.second;
        if(t1.first == t2.first && t1.second == t2.second && t1.first == t3.first && t1.second == t3.second && t2.first == t3.first && t2.second == t3.second){
            std::cout << "Nekorektne pozicije tjemena, ponovite unos!";
            continue;
        }
        Trougao t(t1,t2,t3);
        auto ptr = std::make_shared<Trougao>(t);
        vektor.at(i) = ptr;
    }
    
    std::cout << "Unesite vektor translacije (dx dy): ";
    double dx, dy;
    std::cin >> dx;
    std::cin >> dy;
    std::cout << "Unesite ugao rotacije: ";
    double ugao;
    std::cin >> ugao;
    std::cout << "Unesite faktor skaliranja: ";
    double faktor;
    std::cin >> faktor;
    transform(vektor.begin(), vektor.end(), vektor.begin(), [&] (std::shared_ptr<Trougao> a) {
        a->Transliraj(dx, dy);
        a->Rotiraj(ugao);
        a->Skaliraj(a->DajTjeme(1), faktor);
        return a;
    });
    
    std::sort(vektor.begin(), vektor.end(), [&](const std::shared_ptr<Trougao> x, const std::shared_ptr<Trougao> y) {
    return x->DajPovrsinu() < y->DajPovrsinu(); });
    
    std::cout << "Trouglovi nakon obavljenih transformacija: ";
    for(int i = 0; i < vektor.size(); i++) {
        vektor.at(i)->Ispisi();
        std::cout << std::endl;
    }
    
   /* Trougao t1({2, 1}, {6, 1}, {6, 4}), t2({1, 3}, {1, 7}, {4, 3});

if (DaLiSuPodudarni(t1, t2))
    std::cout << "Trouglovi t1 i t2 JESU podudarni.";
else
    std::cout << "Trouglovi t1 i t2 NISU podudarni.";
std::cout << std::endl;
    
//t1.Postavi({1, 3}, {4, 3}, {4, 7});
if (DaLiSuPodudarni(t1, t2))
    std::cout << "Nakon izmjene trouglovi t1 i t2 JESU podudarni.";
else
    std::cout << "Nakon izmjene trouglovi t1 i t2 NISU podudarni.";
    
    t1.Centriraj(t2.DajCentar());
    Tacka t = t1.DajCentar();
   // t.first -= 1;
    Tacka p = t2.DajCentar();
    std::cout << t.first << " " << t.second << " " << p.first << " " <<p.second << std::endl;
    
    t1.Ispisi();
    
    std::cout << std::endl;
    t1.Rotiraj(t1.DajCentar(), 5);
    
    t1.Ispisi();
    std::cout << std::endl;
    t2.Ispisi();*/
    
    return 0;
}

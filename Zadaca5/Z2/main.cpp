//TP 2018/2019: Zadaća 5, Zadatak 2
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iomanip>

class Berza
{
private:
    int minCijenaReg, maksCijenaReg;
    int minCijena = 0, maksCijena = 0;
    std::vector<int> cijene;
public:
    Berza(int minCijenaReg, int maksCijenaReg) : minCijenaReg(minCijenaReg), maksCijenaReg(maksCijenaReg) { if(minCijenaReg < 0 || maksCijenaReg < 0) throw std::range_error("Ilegalne granicne cijene"); }
    Berza(int maksCijenaReg) : minCijenaReg(0), maksCijenaReg(maksCijenaReg) { if(maksCijenaReg < 0) throw std::range_error("Ilegalne granicne cijene"); }
    //~Berza() { brojac--; }
    void RegistrirajCijenu(int cijena);
    int DajMinimalnuCijenu() const { if(cijene.empty()) throw std::range_error("Nema registriranih cijena"); return minCijena; }
    int DajMaksimalnuCijenu() const { if(cijene.empty()) throw std::range_error("Nema registriranih cijena"); return maksCijena; }
    int DajBrojRegistriranihCijena() const { return cijene.size(); }
    void BrisiSve()  { cijene.clear(); }
    bool operator !() const { return cijene.empty(); }
    int operator [](int indeks) const {
        if(indeks < 1 || indeks > cijene.size()) throw std::range_error("Neispravan indeks");
        return cijene.at(indeks - 1);
    }
    Berza &operator ++(){
        if(std::find_if(cijene.begin(), cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, maksCijenaReg - 100)) != cijene.end()) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
        std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
        return *this;
    }
    
    Berza operator ++(int){
        auto pomocni(*this);
        if(std::find_if(cijene.begin(), cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, maksCijenaReg - 100)) != cijene.end()) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
        std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
        return pomocni;
    }
    
    Berza &operator --(){
        if(std::find_if(cijene.begin(), cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, minCijenaReg + 100)) != cijene.end()) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
        std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 100));
        return *this;
    }
    
    Berza operator --(int){
        auto pomocni(*this);
        if(std::find_if(cijene.begin(), cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, minCijenaReg + 100)) != cijene.end()) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
        std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 100));
        return pomocni;
    }
    
    Berza operator -() const {
        Berza pomocna(*this);
        int zbirCijena = pomocna.minCijenaReg + pomocna.maksCijenaReg;
        std::transform(pomocna.cijene.begin(), pomocna.cijene.end(), pomocna.cijene.begin(),std::bind(std::minus<int>(), zbirCijena, std::placeholders::_1));
        return pomocna;;
    }
    
    Berza &operator +=(int x){
        return *this = *this + x;
    }
    
    Berza &operator -=(int x){
        return *this = *this - x;
    }
    
    Berza &operator -=(const Berza &x){
        return *this = *this - x;
    }
    
    friend Berza operator -(Berza d, int y);
    friend Berza operator -(int y, Berza d);
    friend Berza operator -(Berza d1, const Berza &d2);
    friend Berza operator +(int y, const Berza &d);
    friend Berza operator +(Berza d, int y);
    friend bool operator ==(const Berza &d1, const Berza &d2);
    friend bool operator !=(const Berza &d1, const Berza &d2);
    
    int BrojVecihOd(int cijena){
        if(cijene.empty()) throw std::range_error("Nema registriranih cijena");
        return std::count_if(cijene.begin(), cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, cijena));
    }
    void Ispisi(){
        std::vector<double> pomocni(cijene.begin(), cijene.end());
        std::sort(pomocni.begin(), pomocni.end(), std::greater<int>());
        std::transform(pomocni.begin(), pomocni.end(), std::ostream_iterator<double>(std::cout << std::setprecision(2) << std::fixed, "\n"),std::bind(std::divides<double>(), std::placeholders::_1, 100.));
    }
};

Berza operator -(Berza d, int y){
    if(std::find_if(d.cijene.begin(), d.cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, d.minCijenaReg - y)) != d.cijene.end()) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(d.cijene.begin(), d.cijene.end(), d.cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, y));
    return d;
}

Berza operator -(int y, Berza d){
    if(std::find_if(d.cijene.begin(), d.cijene.end(), std::bind(std::less<int>(), y - d.minCijenaReg, std::placeholders::_1)) != d.cijene.end()) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    if(std::find_if(d.cijene.begin(), d.cijene.end(), std::bind(std::greater<int>(), y - d.maksCijenaReg, std::placeholders::_1)) != d.cijene.end()) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(d.cijene.begin(), d.cijene.end(), d.cijene.begin(), std::bind(std::minus<int>(), y, std::placeholders::_1));
    return d;
}    

Berza operator -(Berza d1, const Berza &d2){
    if(d1.minCijenaReg != d2.minCijenaReg || d1.maksCijenaReg != d2.maksCijenaReg || d1.cijene.size() != d2.cijene.size()) throw std::domain_error("Nesaglasni operandi");
    std::transform(d1.cijene.begin(), d1.cijene.end(), d2.cijene.begin(), d1.cijene.begin(), std::minus<int>());
    if(std::find_if(d1.cijene.begin(), d1.cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, d1.minCijenaReg)) != d1.cijene.end()) throw std::domain_error("Nesaglasni operandi");
    return d1;
}

Berza operator +(Berza d, int y){
    if(std::find_if(d.cijene.begin(), d.cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, d.maksCijenaReg + y)) != d.cijene.end()) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(d.cijene.begin(), d.cijene.end(), d.cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, y));
    return d;
}

void Berza::RegistrirajCijenu(int cijena){
    if(cijena < minCijenaReg || cijena > maksCijenaReg) throw std::range_error("Ilegalna cijena");
    cijene.push_back(cijena);
    if(minCijena == 0 && maksCijena == 0) {
        maksCijena = cijena;
        minCijena = cijena;
    }
    else if(cijena < maksCijena) minCijena = cijena;
    else if(cijena > maksCijena) maksCijena = cijena;
}

Berza operator +(int y, const Berza &d){
    return d + y;
}

bool operator ==(const Berza &d1, const Berza &d2){
    if(d1.maksCijenaReg == d2. maksCijenaReg && d1.minCijenaReg == d2.minCijenaReg && d1.cijene.size() == d2.cijene.size() && std::equal(d1.cijene.begin(), d1.cijene.end(), d2.cijene.begin())) return true;
    return false;
}

bool operator !=(const Berza &d1, const Berza &d2){
    return !(d1 == d2);
}

int main ()
{
    Berza b1 = Berza(1000,4000); Berza b2 = Berza(5000,10000); Berza b3 = Berza(5000,15000);
    b1.RegistrirajCijenu(3000); b2.RegistrirajCijenu(5500); b3.RegistrirajCijenu(11000);
    b1.RegistrirajCijenu(1500); b2.RegistrirajCijenu(6000); b3.RegistrirajCijenu(12000);
    b1.RegistrirajCijenu(2000); b2.RegistrirajCijenu(6300); b3.RegistrirajCijenu(7500);
    b1.RegistrirajCijenu(1500); b2.RegistrirajCijenu(7000); b3.RegistrirajCijenu(8000);
    b1.RegistrirajCijenu(2000); b2.RegistrirajCijenu(9000); b3.RegistrirajCijenu(14000);
    for(int i = 0; i < 3; i++){
        std::cout << "Broj registrovanih cijena " << i + 1 << ". je: ";
        if(i == 0) std::cout << b1.DajBrojRegistriranihCijena() << std::endl;
        else if(i == 1) std::cout << b2.DajBrojRegistriranihCijena() << std::endl;
        else if(i == 2) std::cout << b3.DajBrojRegistriranihCijena() << std::endl;
    }
    
    for(int i = 0; i < 3; i++){
        std::cout << std::endl << "------------------------" << std::endl;
        std::cout << "Registrovane cijene " << i + 1 << ". su: " << std::endl;
        if(i == 0)  b1.Ispisi();
        else if(i == 1) b2.Ispisi();
        else if(i == 2) b3.Ispisi();
        std::cout << std::endl << "Najmanja cijena je ";
        if(i == 0) std::cout << b1.DajMinimalnuCijenu();
        else if(i == 1) std::cout << b2.DajMinimalnuCijenu();
        else if(i == 2) std::cout << b3.DajMinimalnuCijenu();
        std::cout << "," << std::endl << "a najveca je ";
        if(i == 0) std::cout << b1.DajMaksimalnuCijenu();
        else if(i == 1) std::cout << b2.DajMaksimalnuCijenu();
        else if(i == 2) std::cout << b3.DajMaksimalnuCijenu();
    }
    
    
	return 0;
}
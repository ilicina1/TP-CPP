#include <iostream>
#include <algorithm>

class Spremnik{
public:
    virtual Spremnik *DajKopiju() const = 0;
    virtual void Ispisi() const = 0;
    virtual ~Spremnik();
};

class Skladiste{
    Spremnik **spremnik;
    static int brojac;
    int kapacitet;
public:
    Skladiste(Spremnik *sprema, int kapacitet) : kapacitet(kapacitet) { spremnik[kapacitet++] = sprema;  brojac++;}
    Skladiste(int maksimalnaKolicina) : spremnik(new Spremnik*[maksimalnaKolicina]{}) {}
    Skladiste(const Skladiste &v) : spremnik(new Spremnik*[v.kapacitet]){
        std::copy(v.spremnik, v.spremnik + v.kapacitet, spremnik);
    }
    Skladiste &operator =(Skladiste v){
        std::swap(kapacitet, v.kapacitet); std::swap(spremnik, v.spremnik);
        return *this;
    }
    
    Skladiste(Skladiste &&v) : spremnik(v.spremnik), kapacitet(v.kapacitet) { v.spremnik = nullptr; }
    
    Skladiste &operator =(const Skladiste &v){
        if(kapacitet < v.kapacitet){
            Spremnik **noviProstor = new Spremnik*[v.kapacitet];
            delete[] spremnik; spremnik = noviProstor;
        }
        kapacitet = v.kapacitet;
        std::copy(v.spremnik, v.spremnik + v.kapacitet, spremnik);
        return *this;
    }
    
    virtual ~Skladiste();
    void DodajSpremnik(Spremnik *sprema);
    int BrojPohranjenih() const { return brojac; };
};

Skladiste::~Skladiste(){
    for(int i = 0; i < kapacitet;  i++) delete spremnik[i];
    delete[] spremnik;
}

void Skladiste::DodajSpremnik(Spremnik *sprema){
    spremnik[kapacitet++] = sprema;
}

class Bure : Spremnik{
    std::string nazivTecnosti;
    double tezinaBureta, tezinaTecnosti;
public:
    Bure(){}
    Bure(std::string naziv, double tezinaBureta, double tezinaTecnosti) : nazivTecnosti(naziv), tezinaBureta(tezinaBureta), tezinaTecnosti(tezinaTecnosti) {}
    std::string DajNaziv() const { return nazivTecnosti; }
    double DajTezBureta() const { return tezinaBureta; }
    double DajTezTecnosti() const { return tezinaTecnosti; }
    Spremnik *DajKopiju() const override { return new Bure(*this); } 
    void Ispisi() const override { std::cout << DajNaziv() << ": " << std::endl << "Tezina bureta: " << DajTezBureta() << std::endl << "Tezina tecnosti: " << DajTezTecnosti() << std::endl; }
};

class Sanduk : Spremnik{
    std::string nazivPredmeta;
    double tezinaSanduka, tezinaPredmeta;
    static int brojPredmeta;
public:
    Sanduk(){ brojPredmeta++; }
    Sanduk(std::string naziv, double tezinaSanduka, double tezinaPredmeta) : nazivPredmeta(naziv), tezinaSanduka(tezinaSanduka), tezinaPredmeta(tezinaPredmeta) { brojPredmeta++;}
    Spremnik *DajKopiju() const override { return new Sanduk(*this); }
    std::string DajNaziv() const { return nazivPredmeta; }
    double DajTezSanduka() const { return tezinaSanduka; }
    double DajTezPredmeta() const { return tezinaPredmeta; }
    int DajBrojPredmeta() const { return brojPredmeta; }
    void Ispisi() const override { std::cout << DajNaziv() << ": " << std::endl << "Tezina sanduka: " << DajTezSanduka() << std::endl << "Tezina predmeta:: " << DajTezPredmeta() << std::endl << "Broj predmeta u sanduku: " << DajBrojPredmeta() << std::endl; }
};

int Sanduk::brojPredmeta = 0;
int Skladiste::brojac =0;
int main(){
    return 0;
}
#include <iostream>
#include <vector>
#include <string>

class Artikal{
protected:
    std::string naziv;
    double cijena;
public:
    Artikal(std::string naziv, double cijena) : naziv(naziv), cijena(cijena) {}
    ~Artikal(){}
    std::string DajNaziv() const { return naziv; }
    double DajCijenu() const { return cijena; }
    virtual Artikal *DajKopiju() const = 0;
    virtual void Ispisi() const = 0;
};

class Brasno : public Artikal{
    double cijena, kilogrami;
public:
    Brasno(double cijena, double kilogrami) : Artikal("Brasno", cijena), kilogrami(kilogrami){}
    double DajKilograme() const { return kilogrami; }
    Artikal *DajKopiju() const override { return new Brasno(*this); }
    void Ispisi() const override { std::cout <<  DajKilograme() << "kg, " << DajCijenu() << "KM" << std::endl; }
};

class Ulje : public Artikal{
    double cijena, litri;
public:
    Ulje(double cijena, double litri) : Artikal("Ulje", cijena), litri(litri) {}
    double DajLitre() const { return litri; }
    Artikal *DajKopiju() const override { return new Ulje(*this); } 
    void Ispisi() const override { std::cout <<  DajLitre() << ", " << DajCijenu() << "KM" << std::endl; }
};

class Prodavnica
{
    std::vector<Artikal*> vektorPok;
public:
    Prodavnica(){}
    Prodavnica(const Artikal &artikal){
        vektorPok.emplace_back(artikal.DajKopiju());
    }
    void DodajBrasno(const Artikal &artikal)  { 
        vektorPok.emplace_back(artikal.DajKopiju());
    }
    void DodajUlje(const Artikal &artikal)  { 
        vektorPok.emplace_back(artikal.DajKopiju());
    }
    
    void DodajBrasno(double cijena, double kilogrami)  { 
        Brasno b(cijena, kilogrami);
        vektorPok.emplace_back(b.DajKopiju());
    }
    void DodajUlje(double cijena, double litri)  { 
        Ulje l(cijena, litri);
        vektorPok.emplace_back(l.DajKopiju());
    }
    
    void Ispisi() const { 
        for(int i = 0; i < vektorPok.size(); i++) vektorPok.at(i)->Ispisi();
    }
    
    Artikal* operator [](int indeks) const {
        return vektorPok.at(indeks);
    }
    ~Prodavnica(){}
};


int main()
{
    Prodavnica p, p2;
    Ulje u (2, 1); Brasno b (1.1, 1); p.DodajUlje(u); p.DodajUlje (7, 5); p.DodajBrasno(17, 20); p.DodajBrasno (b); Prodavnica p3 (p);
    p3.Ispisi(); //svaki artikal, u novom redu p2 = p;
    //Artikal *a = p2[0];
    //a->Ispisi(); // Ulje 1l, 2KM p2[2]->Ispisi(); // Brasno 17kg, 20KM
    return 0;
}
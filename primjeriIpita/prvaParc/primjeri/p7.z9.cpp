#include <iostream>

class Spremnik
{
protected:
    double tezinaSpremnika;
    std::string nazivMaterije;
    double tezinaMaterije;
public:
    Spremnik(double tezinaSpremnika, std::string nazivMaterije, double tezinaMaterije) : tezinaSpremnika(tezinaSpremnika), nazivMaterije(nazivMaterije), tezinaMaterije(tezinaMaterije) {}
    double DajTezinuSpremnika() const
    {
        return tezinaSpremnika;
    }
    std::string DajNazivMaterije() const
    {
        return nazivMaterije;
    }
    double DajTezinuMaterije() const
    {
        return tezinaMaterije;
    }
    virtual void Ispisi() const = 0;
    
};

class Sanduk : public Spremnik
{
    int brojPredmeta;
public:
    Sanduk(double tezinaSpremnika, std::string nazivMaterije, double tezinaMaterije, int brojPredmeta) : Spremnik(tezinaSpremnika, nazivMaterije, tezinaMaterije), brojPredmeta(brojPredmeta) {}
    int DajBrojPredmeta() const
    {
        return brojPredmeta;
    }
    virtual void Ispisi() const
    {
        std::cout << DajTezinuSpremnika() << " " <<DajTezinuMaterije() << " " << DajNazivMaterije() << " " << DajBrojPredmeta() << std::endl;
    }
};

class Bure : public Spremnik
{
public:
    Bure(double tezinaSpremnika, std::string nazivMaterije, double tezinaMaterije) : Spremnik(tezinaSpremnika, nazivMaterije, tezinaMaterije) {}
    virtual void Ispisi() const
    {
        std::cout << DajTezinuSpremnika() << " " <<DajTezinuMaterije() << " " << DajNazivMaterije() << std::endl;
    }
};

class Skladiste
{
    Spremnik **pok;
    int kolicina, broj_spremnika;
public:
    Skladiste(int kolicina) : kolicina(kolicina)
    {
        pok = new Spremnik*[kolicina];
    }
    void DodajSpremnik(Spremnik *spremnik)
    {
        if(broj_spremnika >= kolicina) {
            delete spremnik;
            throw std::range_error("Kolekcija popunjena!");
        }
        pok[broj_spremnika++] = spremnik;
    }
    void DodajBure(double tezinaSpremnika, std::string nazivMaterije, double tezinaMaterije)
    {
        DodajSpremnik(new Bure(tezinaSpremnika, nazivMaterije, tezinaMaterije));
    }
    void DodajSanduk(double tezinaSpremnika, std::string nazivMaterije, double tezinaMaterije, int brojPredmeta)
    {
        DodajSpremnik(new Sanduk(tezinaSpremnika, nazivMaterije, tezinaMaterije, brojPredmeta));
    }
    Skladiste() {}
    ~Skladiste(){}
    void Ispisi() const
    {
        for(int i = 0; i < kolicina; i++) pok[i]->Ispisi();
    }
};


int main()
{
    Skladiste skladiste(5);
    skladiste.DodajBure(12, "voda", 22);
    skladiste.DodajSanduk(22, "cigla", 2, 4);
    skladiste.Ispisi();
}

#include <iostream>
#include <string>

class Spremnik{
protected:
    double tezinaSpremnika, tezinaMaterije;
    std::string nazivMaterije;
public:
    Spremnik(double tezinaSpremnika, double tezinaMaterije, std::string nazivMaterije) : tezinaSpremnika(tezinaSpremnika), tezinaMaterije(tezinaMaterije), nazivMaterije(nazivMaterije){
        if(tezinaSpremnika < 0 || tezinaMaterije < 0 || nazivMaterije.length() < 0) throw std::logic_error("Ne valja!");
    }
    virtual double DajTezinuSpremnika() const = 0;
    virtual double DajTezinuMaterije() const = 0;
    virtual std::string DajNazivMaterije() const = 0;
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
};

class Sanduk : public Spremnik{
    int brojPredmeta;
public:
    Sanduk(double tezinaSpremnika, double tezinaMaterije, std::string nazivMaterije, int brojPredmeta) : Spremnik(tezinaSpremnika, tezinaMaterije, nazivMaterije), brojPredmeta(brojPredmeta) {
        if(brojPredmeta < 0) throw std::logic_error("Ne valja!");
    }
    double DajTezinuSpremnika() const override { return tezinaSpremnika; }
    double DajTezinuMaterije() const override { return tezinaMaterije; }
    std::string DajNazivMaterije() const override { return nazivMaterije; }
    double DajUkupnuTezinu() const override { return tezinaSpremnika + tezinaMaterije; }
    int DajBrojPredmeta() const { return brojPredmeta; }
    void Ispisi() const override { 
        std::cout << "Tezina sanduka: " << DajTezinuSpremnika() << 
        std::endl << "Tezina predmeta: " << DajTezinuMaterije() << 
        std::endl << "Naziv predmeta: " << DajNazivMaterije() << 
        std::endl << "Broj predmeta: " << DajBrojPredmeta() << 
        std::endl << "Ukupna tezina: " << DajUkupnuTezinu() << std::endl;
    }
};

class Burad : public Spremnik{
public:
    Burad(double tezinaSpremnika, double tezinaMaterije, std::string nazivMaterije) : Spremnik(tezinaSpremnika, tezinaMaterije, nazivMaterije){}
    double DajTezinuSpremnika() const override { return tezinaSpremnika; }
    double DajTezinuMaterije() const override { return tezinaMaterije; }
    double DajUkupnuTezinu() const override { return tezinaSpremnika + tezinaMaterije; }
    std::string DajNazivMaterije() const override { return nazivMaterije; }
    void Ispisi() const override { 
        std::cout << "Tezina sanduka: " << DajTezinuSpremnika() << 
        std::endl << "Tezina predmeta: " << DajTezinuMaterije() << 
        std::endl << "Naziv predmeta: " << DajNazivMaterije() << 
        std::endl << "Ukupna tezina: " << DajUkupnuTezinu() << std::endl;
    }
};

class Skladiste{

    Spremnik **pok;
    mutable int brojac = 0;
    int maks;
public:
int daj() const { return maks;}
    Skladiste(int maks) : maks(maks){
        try{
            pok = new Spremnik*[maks];
        } catch (...){
            throw std::bad_alloc();
        }
        for(int i = 0; i < maks; i++){
            pok[i] = nullptr;
        }
    }
    ~Skladiste(){ 
        // for(int i = 0; i < maks; i++) delete[] pok[i];
        delete[] pok; 
    }
    Skladiste(const Skladiste &spremnik) : maks(spremnik.maks){
        try{
            pok = new Spremnik*[maks];
        } catch (...){
            throw std::bad_alloc();
        }
        for(int i = 0; i < maks; i++){
            pok[i] = nullptr;
        }
        for(int i = 0; i < maks; i++) pok[i] = spremnik.pok[i];
        brojac = spremnik.brojac;
    }
    Skladiste &operator=(const Skladiste &spremnik){
        Spremnik **novoSkladiste = new Spremnik*[spremnik.maks];
        std::copy(spremnik.pok, spremnik.pok + spremnik.maks, novoSkladiste);
        delete[] pok;
        maks = spremnik.maks;
        pok = novoSkladiste;
        brojac = spremnik.brojac;
        return *this;
    }
    Skladiste(Skladiste &&spremnik) : pok(spremnik.pok), maks(spremnik.maks), brojac(spremnik.brojac){
        spremnik.pok = nullptr;
        spremnik.maks = 0;
        spremnik.brojac = 0;
    }
    Skladiste &operator =(Skladiste &&spremnik){
        pok = spremnik.pok;
        maks = spremnik.maks;
        spremnik.pok = nullptr;
        spremnik.maks = 0;
        return *this;
    }
    Spremnik &operator [](int i){
        return *pok[i];
    }
    void DodajSanduk(double tezinaSpremnika, double tezinaMaterije, std::string nazivMaterije, int brojPredmeta) {
        if(brojac == maks) throw std::logic_error("Nema mjesta!");
        //Spremnik *sanduk = new Sanduk{tezinaSpremnika, tezinaMaterije, nazivMaterije, brojPredmeta};
        pok[brojac] = new Sanduk(tezinaSpremnika, tezinaMaterije, nazivMaterije, brojPredmeta);
        brojac++;
    }
    void DodajBure(double tezinaSpremnika, double tezinaMaterije, std::string nazivMaterije) {
        if(brojac == maks) throw std::logic_error("Nema mjesta!");
        //Spremnik *sanduk = new Sanduk{tezinaSpremnika, tezinaMaterije, nazivMaterije, brojPredmeta};
        pok[brojac] = new Burad(tezinaSpremnika, tezinaMaterije, nazivMaterije);
        brojac++;
    }
    Spremnik &DajNajlaksiSpremnik(){
        Spremnik *najlaksi = pok[0];
        int b = 0;
        for(int i = 0; i < brojac; i++){
            if(najlaksi->DajTezinuSpremnika() > pok[i]->DajTezinuSpremnika()) b = i;
        }
        return *pok[b];
    }
    Spremnik &DajNajteziSpremnik(){
        Spremnik *najtezi = pok[0];
        int b = 0;
        for(int i = 0; i < brojac; i++){
            if(najtezi->DajTezinuSpremnika() < pok[i]->DajTezinuSpremnika()) b = i;
        }
        return *pok[b];
    }
    int BrojObjekataVecihOd(double tezina) const {
        int counter = 0;
        for(int i = 0; i < brojac; i++){
            if(pok[i]->DajTezinuSpremnika() + pok[i]->DajTezinuMaterije() > tezina) counter++;
        }
        return counter;
    }
    int DajBrojPohranjenihObjekata() const { return brojac; }
};

int brojac = 0;

int main()
{
    Skladiste skladiste(5);
    skladiste.DodajSanduk(21, 2, "Drvo", 3);
    skladiste.DodajSanduk(2, 22, "Konstrukcija", 5);
    skladiste.DodajSanduk(24, 22, "Tastatura", 5);
    skladiste.DodajBure(21, 22, "Vino");
    Skladiste skladiste2(2);
    skladiste2.DodajSanduk(21, 2, "aa", 3);
    skladiste2 = skladiste;

    std::cout << skladiste2.BrojObjekataVecihOd(0) << std::endl;
    std::cout << skladiste2[2].DajNazivMaterije() << " " << skladiste2.DajBrojPohranjenihObjekata();
    
}

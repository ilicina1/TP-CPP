#include <iostream>
#include <iomanip>
#include <cstring>
struct Uposlenik
{
    char ime_prezime[20];
    char adresa[50];
    int broj_telefona;
public:
    Uposlenik(char *ime_prezime, char *adresa, int broj_telefona) {
        for(int i = 0; i < 20; i++) this->ime_prezime[i] = ime_prezime[i];
        for(int i = 0; i < 20; i++) this->adresa[i] = adresa[i];
        this->broj_telefona = broj_telefona;
    }
    virtual ~Uposlenik() {}
    const char *DajImePrezime() const { return ime_prezime; }
    const char *DajAdresu() const { return adresa; }
    int DajBrojTelefona() const { return broj_telefona; }
    void Ispisi() const {
        std::cout << "Ime i prezime: " << std::setw(20) << DajImePrezime() << std::endl << "Adresa: " << std::setw(27) << DajAdresu() << std::endl << "Broj telefona: " << std::setw(20) << DajBrojTelefona() << std::endl << "-------------------------------------------------" << std::endl;
    }
    Uposlenik *DajKopiju() const { return new Uposlenik(*this); }
};

class Imenik
{
    Uposlenik **uposlenik;
    int kapacitet, broj_uposlenika;
public:
    explicit Imenik(int kapacitet) {
        uposlenik = new Uposlenik*[kapacitet];
        this->kapacitet = kapacitet;
        this->broj_uposlenika = 0;
    }
    Imenik(){}
    virtual ~Imenik() {
        for(int i = 0; i < broj_uposlenika; i++) delete[] uposlenik[i];
        delete[] uposlenik;
    }
    void DodajUposlenika(Uposlenik *up);
    void Ispisi() const {
        for(int i = 0; i < broj_uposlenika; i++) uposlenik[i]->Ispisi();
    }
    void DodajUposlenika(char *ime_prezime, char *adresa, int broj_telefona);
    Imenik(const Imenik &imenik);
    Imenik &operator =(const Imenik &imenik);
    void IspisiUposlenika(char *ime_prezime) const {
        for(int i = 0; i < broj_uposlenika; i++) if(strcmp(uposlenik[i]->DajImePrezime(), ime_prezime) == 0) uposlenik[i]->Ispisi();
    }
    void IspisiSveNaSlovo(char a){
        for(int i = 0; i < broj_uposlenika; i++){
            const char *p = uposlenik[i]->DajImePrezime();
            if(p[0] == a) uposlenik[i]->Ispisi();
        }
    }
    int operator [](char *imeprezime) const {
        for(int i = 0; i < broj_uposlenika; i++){
            if(strcmp(uposlenik[i]->DajImePrezime(), imeprezime) == 0) return uposlenik[i]->DajBrojTelefona();
        }
    }
    friend bool operator !(const Imenik imenik) {
        if(imenik.kapacitet == 0) return true;
        return false;
    }
};

Imenik &Imenik::operator =(const Imenik &imenik){
    Uposlenik **novi_prostor = new Uposlenik*[imenik.kapacitet]{};
    try{
        for(int i = 0; i < imenik.kapacitet; i++){
            novi_prostor[i] = imenik.uposlenik[i]->DajKopiju();
        }
    } catch(...) {
        for(int i = 0; i < broj_uposlenika; i++) delete novi_prostor[i];
         delete[] novi_prostor; throw;
    }
    for(int i = 0; i < broj_uposlenika; i++) delete uposlenik[i];
    delete[] uposlenik;
    uposlenik = novi_prostor; kapacitet = imenik.kapacitet; broj_uposlenika = imenik.broj_uposlenika;
    return *this;
}

void Imenik::DodajUposlenika(Uposlenik *uposlen){
    if(broj_uposlenika >= kapacitet) {
        delete uposlen;
        throw std::logic_error("Nema mjesta!");
    }
    uposlenik[broj_uposlenika++] = uposlen;
}

void Imenik::DodajUposlenika(char *ime_prezime, char *adresa, int broj_telefona){
    if(broj_uposlenika >= kapacitet) {
        throw std::logic_error("Nema mjesta!");
    }
    uposlenik[broj_uposlenika++] = new Uposlenik(ime_prezime, adresa, broj_telefona);
}

Imenik::Imenik(const Imenik &imenik) : uposlenik(new Uposlenik*[imenik.kapacitet]), kapacitet(imenik.kapacitet), broj_uposlenika(imenik.broj_uposlenika){
    try{
        for(int i = 0; i < imenik.kapacitet; i++) uposlenik[i] = imenik.uposlenik[i]->DajKopiju();
    }catch(...) {
        for(int i = 0; i < broj_uposlenika; i++) delete uposlenik[i];
        delete[] uposlenik; throw;
 }
}

int main()
{
    char ime[20] = "ilhan licina";
    char adresa[20] = "drinolino";
    Imenik a(3);
    Uposlenik *bb = new Uposlenik(ime, adresa, 225);
    a.DodajUposlenika(bb);
    char ime2[20] = "bab vaga";
    char adresa2[50] = "papalinska ulica";
    a.DodajUposlenika(new Uposlenik(ime2, adresa2, 22115));
    char ime3[20] = "mama ina";
    char adresa3[50] = "lovackau lica";
    a.DodajUposlenika(ime3, adresa3, 3111);
    //bb->Ispisi();
    a.Ispisi();
    Imenik b(3);
    b = a;
    b.Ispisi();
    b.IspisiUposlenika(ime);
    b.IspisiSveNaSlovo('b');
    std::cout << b[ime2];
    Imenik prazni(0);
    if(!prazni) std::cout << std::endl <<"Prazan je";
    else std::cout << std::endl <<"Nije prazan";
}

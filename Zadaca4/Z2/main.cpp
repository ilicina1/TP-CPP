//TP 2018/2019: Zadaća 4, Zadatak 2
#include <iostream>
#include <string>

class GradjaninBiH
{
private:
    std::string NameAndSurname;
    long long int jmbg;
    long long int nizJmbg[13];
    GradjaninBiH *pok;
    
    void UpisiJMBG() {
        long long int tempJMBG = jmbg;
        for(int i=0; i < 13; i++) {
            nizJmbg[i] = tempJMBG % 10;
            tempJMBG /= 10;
        }
    }
public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
        
        NameAndSurname = ime_i_prezime;
        this->jmbg = jmbg;
        UpisiJMBG();
    };
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
        long long int jedinstveni = (dan_rodjenja * 100) + mjesec_rodjenja;
        if(godina_rodjenja <= 1999) godina_rodjenja -= 1000;
        else godina_rodjenja -= 2000;
        jedinstveni = jedinstveni * 1000 + godina_rodjenja;
        jedinstveni = jedinstveni * 100 + sifra_regije;
        //int brojPola;
        jedinstveni = jedinstveni * 1000; // broj pola
        int kontrolnaCifra = 11 - (7 * ((dan_rodjenja / 10) + (godina_rodjenja % 10)) + 6 * ((dan_rodjenja % 10) + (sifra_regije / 10)) + 5 * ((mjesec_rodjenja / 10) + (sifra_regije % 10)) + 4 * ((mjesec_rodjenja % 10) + (0)) + 3 * ((godina_rodjenja / 100) + 0) + 2 * ((godina_rodjenja / 10 % 10) + 0) ) % 11;
        if(kontrolnaCifra == 11) kontrolnaCifra = 0;
        else if(kontrolnaCifra == 10) throw std::logic_error("JMBG nije validan");
        jedinstveni = jedinstveni * 10 + kontrolnaCifra;
        this->jmbg = jedinstveni;
        this->NameAndSurname = ime_i_prezime;
        
        
    }
    std::string DajImeIPrezime() const { return NameAndSurname; }
    long long int DajJMBG() const { return jmbg; }
    int DajDanRodjenja() const {
        return nizJmbg[12] * 10 + nizJmbg[11];
    }
    void IspisiJMBG() const {
        for (int i = 0; i < 13; i++) {
            std::cout << nizJmbg[i]<< "  ";
        }
    }
    int DajMjesecRodjenja() const {
        return nizJmbg[10] * 10 + nizJmbg[9];
    }
    int DajGodinuRodjenja() const {
         int godina = (nizJmbg[8] * 100) + (nizJmbg[7] * 10) + nizJmbg[6];
         if(godina >= 0 && godina <= 17) godina += 2000;
         else /*if(godina >= 917 && godina <= 999)*/ godina += 1000;
         return godina;
    }
    int DajSifruRegije() const {
        return nizJmbg[5] * 10 + nizJmbg[4];
    }
    Pol DajPol() const {
        int pol = (nizJmbg[3] * 100) + (nizJmbg[2] * 10) + nizJmbg[1];
        if(pol >= 499) return Zensko;
        else return Musko;
    }
    void PromijeniImeIPrezime(std::string novo_ime){
        this->NameAndSurname = novo_ime;
    }
};

int main ()
{   
    std::cout << "Koliko gradjana zelite unijeti po JMBG?" << std::endl;
    int brojGradjana;
    std::cin >> brojGradjana;
    for(int i = 0; i < brojGradjana; i++){
        std::cout << "Unesite ime i prezime (u istom redu):";
        std::string ime_i_prezime;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::getline(std::cin, ime_i_prezime);
        std::cout << "Unesite JMBG:";   
        long long int jmbg = 0;
        std::cin >> jmbg;
        GradjaninBiH a(ime_i_prezime, jmbg);
    }
    return 0;
}

//TP 2018/2019: Tutorijal 8, Zadatak 3
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

const int BrojPredmeta(8);

struct Datum {
    int dan, mjesec, godina;
};

struct Ucenik {
    std::string ime, prezime;
    Datum datum_rodjenja;
    int ocjene[BrojPredmeta];
    double prosjek;
    bool prolaz;
};

int main()
{
    void UnesiUcenike(Ucenik *p_ucenici);
    void ObradiUcenike(Ucenik *p_ucenici);
    void IspisiIzvjestaj(const Ucenik *p_ucenici);
    void OslobodiMemoriju(Ucenik *p_ucenici);
    int broj_ucenika;
    std::cout << "Koliko ima učenika: ";
    std::cin >> broj_ucenika;
    try {
        Ucenik **p_ucenici;
        Ucenik *ucenici;
        ucenici = new Ucenik[broj_ucenika];
        p_ucenici = new Ucenik*[broj_ucenika] {};
        try {
            UnesiUcenike(*p_ucenici);
        } catch(...) {
            OslobodiMemoriju(*p_ucenici);
            throw;
        }
        ObradiUcenike(*p_ucenici);
        IspisiIzvjestaj(*p_ucenici);
        OslobodiMemoriju(*p_ucenici);
    } catch(...) {
        std::cout << "Problemi sa memorijom...\n";
    }
    return 0;
}

void UnesiUcenike(Ucenik *p_ucenici, int broj_ucenika)
{
    void UnesiJednogUcenika(Ucenik *p_ucenici);
    for(int i = 0; i < broj_ucenika; i++) {
        std::cout << "Unesite podatke za " << i + 1 << ". učenika:\n";
     // p_ucenici = new Ucenik*[broj_ucenika]{};
        UnesiJednogUcenika(p_ucenici);
    }
}

void UnesiJednogUcenika(Ucenik *p_ucenik)
{
    void UnesiDatum(Datum &datum);
    void UnesiOcjene(int ocjene[], int broj_predmeta);
    std::cout << " Ime: ";
    std::cin >> p_ucenik->ime;
    std::cout << " Prezime: ";
    std::cin >> p_ucenik->prezime;
    std::cout << " Datum rođenja (D/M/G): ";
    UnesiDatum(p_ucenik->datum_rodjenja);
    UnesiOcjene(p_ucenik->ocjene, BrojPredmeta);
}

void UnesiDatum(Datum &datum)
{
    char znak;
    std::cin >> datum.dan >> znak >> datum.mjesec >> znak >> datum.godina;
}

void UnesiOcjene(int ocjene[], int broj_predmeta)
{
    for(int i = 0; i < broj_predmeta; i++) {
        std::cout << "  Ocjena iz " << i + 1 << ". predmeta: ";
        std::cin >> ocjene[i];
    }
}

void ObradiUcenike(Ucenik *p_ucenik, int broj_ucenika)
{
    void ObradiJednogUcenika(Ucenik *p_ucenik);
    for(int i = 0; i < broj_ucenika; i++) ObradiJednogUcenika(p_ucenik);
    std::sort(p_ucenik, p_ucenik + broj_ucenika,
    [](const Ucenik *p_u1, const Ucenik *p_u2) {
        return p_u1->prosjek > p_u2->prosjek;
    });
}

void ObradiJednogUcenika(Ucenik *p_ucenici)
{
    double suma_ocjena = 0;
    p_ucenici->prosjek = 1;
    p_ucenici->prolaz = false;
    for(int ocjena : p_ucenici->ocjene) {
        if(ocjena == 1) return;
        suma_ocjena += ocjena;
    }
    p_ucenici->prolaz = true;
    p_ucenici->prosjek = suma_ocjena / BrojPredmeta;
}

void IspisiIzvjestaj(const Ucenik *p_ucenici, int broj_ucenika)
{
    void IspisiJednogUcenika(const Ucenik *p_ucenik);
    std::cout << std::endl;
    for(int i = 0; i < broj_ucenika; i++) IspisiJednogUcenika(p_ucenici);
}

void IspisiJednogUcenika(const Ucenik *p_ucenik)
{
    void IspisiDatum(const Datum &datum);
    std::cout << "Učenik " << p_ucenik->ime << " " << p_ucenik->prezime
              << " rođen ";
    IspisiDatum(p_ucenik->datum_rodjenja);
    if(p_ucenik->prolaz)
        std::cout << " ima prosjek " << std::setprecision(3) << p_ucenik->prosjek;
    else
        std::cout << " mora ponavljati razred";
    std::cout << std::endl;
}

void IspisiDatum(const Datum &datum)
{
    std::cout << datum.dan << "/" << datum.mjesec << "/" << datum.godina;
}

void OslobodiMemoriju(Ucenik *p_ucenici, int broj_ucenika)
{
    for(int i = 0; i < broj_ucenika; i++) delete p_ucenici;
}

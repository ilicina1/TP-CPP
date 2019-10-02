//TP 2018/2019: Tutorijal 8, Zadatak 6
#include <iostream>

template<typename nekiTip>
struct Cvor {
    nekiTip element;
    Cvor *veza;
};

template<typename TipElemenata>
Cvor<TipElemenata> *KreirajPovezanuListu(TipElemenata zavrsni)
{

    Cvor<TipElemenata> *pocetak = nullptr, *prethodni;
    for(;;) {
        TipElemenata element;
        std::cin >> element;
        if(element == zavrsni) {
            break;
        }
        Cvor<TipElemenata> *novi = new Cvor<TipElemenata> {element, nullptr };
        if(!pocetak) {
            pocetak = novi;
        } else {
            prethodni->veza = novi;
        }
        prethodni = novi;
    }

    return pocetak;
}

template<typename TipElemenata>
int BrojElemenata(Cvor<TipElemenata> *pocetak)
{
    int brojac = 0;

    for(Cvor<TipElemenata> *p = pocetak; p != nullptr; p = p->veza) {
        brojac++;
    }

    return brojac;
}

template<typename TipElemenata>
TipElemenata SumaElemenata(Cvor<TipElemenata> *pocetak)
{
    TipElemenata suma = 0;
    for(Cvor<TipElemenata> *p = pocetak; p != nullptr; p = p->veza) {
        suma += p->element;
    }

    return suma;
}

template<typename TipElemenata>
int BrojVecihOd(Cvor<TipElemenata> *pocetak, TipElemenata prag)
{
    int brojac = 0;

    for(Cvor<TipElemenata> *p = pocetak; p != nullptr; p = p->veza) {
        if(p->element > prag) {
            brojac++;
        }
    }


    return brojac;
}

template<typename TipElemenata>
void UnistiListu(Cvor<TipElemenata> *pocetak)
{
    for(Cvor<TipElemenata> *p = pocetak; p != nullptr ; p = p->veza)  {
        Cvor<TipElemenata> *pomocni = p;
        p = p->veza;
        delete pomocni;
    }
}

int main ()
{
    std::cout << "Unesite slijed brojeva (0 za kraj): ";

    Cvor<double> *lista = KreirajPovezanuListu(0.0);

    int broj_elemenata = BrojElemenata(lista);

    double suma = SumaElemenata(lista);

    double aritmeticka_sredina = suma / broj_elemenata;

    int broj_vecih_od = BrojVecihOd(lista, aritmeticka_sredina);

    std::cout << "U slijedu ima " << broj_vecih_od << " brojeva vecih od njihove aritmeticke sredine";

    UnistiListu(lista);
    return 0;
}

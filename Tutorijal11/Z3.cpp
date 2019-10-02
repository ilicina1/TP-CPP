// TP 16/17 (Tutorijal 11, Zadatak 3)
#include <iostream>
#include <iomanip>
#include <cstring>

class Tim
{
private:
	char ime_tima[20];
	int broj_pobjeda, broj_nerijesenih, broj_poraza, broj_datih, broj_primljenih, broj_poena, broj_odigranih;
public:
	Tim(const char ime[]) : broj_pobjeda(0) , broj_nerijesenih(0) , broj_poraza(0) , broj_datih(0) , broj_primljenih(0) , broj_poena(0), broj_odigranih(0) {
		if(strlen(ime) > 20) throw std::range_error("Predugacko ime tima");
		strncpy(ime_tima, ime, 20);
	}
	void ObradiUtakmicu(int broj_datih, int broj_primljenih){
		if(broj_datih < 0 || broj_primljenih < 0) throw std::range_error("Neispravan broj golova");
		this->broj_datih += broj_datih;
		this->broj_primljenih += broj_primljenih;
		broj_odigranih++;
		if(broj_datih < broj_primljenih) broj_poraza++;
		else if(broj_datih > broj_primljenih) {
			broj_pobjeda++;
			broj_poena += 3;
		}
		else {
			broj_nerijesenih++;
			broj_poena++;
		}
	}
	const char*DajImeTima() const { return ime_tima; }
	int DajBrojPoena() const { return broj_poena; }
	int DajGolRazliku() const { return broj_datih - broj_primljenih; }
	void IspisiPodatke() const { std::cout << std::left << std::setw(20) << ime_tima << std::right << std::setw(4) << broj_odigranih << std::setw(4) << broj_pobjeda << std::setw(4) << broj_nerijesenih << std::setw(4) << broj_poraza << std::setw(4) << broj_datih << std::setw(4) << broj_primljenih << std::setw(4) << broj_poena << std::endl; }
};

//int Tim::broj_odigranih = 0;

int main ()
{
	Tim t1("FK Sarajevo") ;

    t1.ObradiUtakmicu(6,1) ;
    t1.ObradiUtakmicu(0,1) ;
    t1.ObradiUtakmicu(2,1) ;
    t1.ObradiUtakmicu(0,1) ;
    t1.ObradiUtakmicu(1,1) ;

    Tim t2("FK Zeljeznicar") ;

    t2.ObradiUtakmicu(0,1) ;
    t2.ObradiUtakmicu(1,2) ;
    t2.ObradiUtakmicu(1,0) ;
    t2.ObradiUtakmicu(1,1) ;
    t2.ObradiUtakmicu(2,1) ;
    t2.ObradiUtakmicu(2,1) ;
    t2.ObradiUtakmicu(0,0) ;
    t2.ObradiUtakmicu(1,0) ;
    t2.ObradiUtakmicu(3,2) ;
    t2.ObradiUtakmicu(0,2) ;


    t1.IspisiPodatke() ;
    t2.IspisiPodatke() ;
	return 0;
}

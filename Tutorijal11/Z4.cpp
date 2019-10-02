// TP 16/17 (Tutorijal 11, Zadatak 4
#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>

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

class Liga
{
private:
	static bool kriterij(Tim* a, Tim* b) {
        if(a->DajBrojPoena() > b->DajBrojPoena())
            return true;
        if(a->DajBrojPoena() == b->DajBrojPoena())
            if(a->DajGolRazliku() > b->DajGolRazliku())
                return true;
        return false;
    }
	int broj_timova;
	const int max_br_timova;
	Tim** timovi;
public:
	explicit Liga(int velicina_lige) : broj_timova(0), max_br_timova(velicina_lige), timovi(new Tim*[velicina_lige]) {
		for(int i = 0; i < velicina_lige; i++) timovi[i] = nullptr;
	}
	explicit Liga(std::initializer_list<Tim> lista_timova);
	~Liga() { if(timovi) for(int i = 0; i < max_br_timova; i++) delete timovi[i]; delete[] timovi; }
	Liga(const Liga &l);
	Liga(Liga &&l) : broj_timova(l.broj_timova), max_br_timova(l.max_br_timova), timovi(new Tim*[l.max_br_timova]) {
		timovi = l.timovi;
		l.timovi = nullptr;
	}
	Liga &operator =(const Liga &l);
	Liga &operator =(Liga &&l);
	void DodajNoviTim(const char ime_tima[]);
	void RegistrirajUtakmicu(const char tim1[], const char tim2[],
	int rezultat_1, int rezultat_2);
	void IspisiTabelu() {
        std::sort(timovi, timovi + broj_timova, kriterij);
        for(int i = 0; i < broj_timova; i++) timovi[i]->IspisiPodatke();
    };
};

Liga::Liga(std::initializer_list<Tim> lista_timova) : broj_timova(lista_timova.size()), max_br_timova(lista_timova.size()), timovi(new Tim*[lista_timova.size()]){
	for(int i = 0; i < lista_timova.size(); i++) timovi[i] = nullptr;
	try{
		int j(0);
		for(auto i : lista_timova){
			timovi[j++] = new Tim(i);
		}
	} catch(...){
		for(int i = 0; i < max_br_timova; i++) delete timovi[i];
		delete[] timovi;
		throw;
	}
}

Liga::Liga(const Liga &l) : broj_timova(l.broj_timova), max_br_timova(l.max_br_timova), timovi(new Tim*[l.max_br_timova]){
	if(max_br_timova != l.max_br_timova) throw std::logic_error("Nesaglasni kapaciteti liga");
	for(int i = 0; i < max_br_timova; i++) timovi[i] = nullptr;
	try{
		for(int i = 0; i < broj_timova; i++){
			timovi[i] = new Tim(*l.timovi[i]);
		}
	}catch(...){
		for(int i = 0; i < max_br_timova; i++)	delete timovi[i];
		delete[] timovi;
		throw;
	}
}

Liga& Liga::operator =(const Liga &l) {
	if(&l != this){
		if(max_br_timova == l.max_br_timova){
			for(int i = 0; i < l.broj_timova; i++) *timovi[i] = *l.timovi[i];
			broj_timova = l.broj_timova;
		} else throw std::logic_error("Nesaglasni kapaciteti liga");
	}
	return *this;
}

Liga& Liga::operator =(Liga &&l){
	if(max_br_timova == l.max_br_timova){
		broj_timova = l.broj_timova;
		timovi = l.timovi;
		l.timovi = nullptr;
	} else throw std::logic_error("Nesaglasni kapaciteti liga");
	return *this;
}

void Liga::DodajNoviTim(const char ime_tima[]){
	if(broj_timova == max_br_timova) throw std::range_error("Liga popunjena");
	if(strlen(ime_tima) > 20) throw std::range_error("Predugacko ime tima");
	//for(int i = 0; i < broj_timova; i++) if(timovi[i]->ime_tima == ime_tima) throw std::logic_error("Tim vec postoji");
	timovi[broj_timova++] = new Tim(ime_tima);
}

void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[],
    int rezultat_1, int rezultat_2) {
    Tim* a(nullptr), *b(nullptr);
    for(int i = 0; i < broj_timova; i++)
        if(strcmp(timovi[i]->DajImeTima(), tim1) == 0)
            a = timovi[i];
    for(int i = 0; i < broj_timova; i++)
        if(strcmp(timovi[i]->DajImeTima(), tim2) == 0)
            b = timovi[i];
    if(!a || !b) throw "Timovi ne postoje";
    a->ObradiUtakmicu(rezultat_1, rezultat_2);
    b->ObradiUtakmicu(rezultat_2, rezultat_1);
}

int main ()
{
	Liga l1(6) ;
    l1.DodajNoviTim("FK Zeljeznicar") ;
    l1.DodajNoviTim("FK Sarajevo") ;
    l1.DodajNoviTim("NK Celik") ;
    l1.DodajNoviTim("FK Sloboda") ;
    l1.DodajNoviTim("FK Mladost") ;
    l1.DodajNoviTim("FK Olimpic") ;


    l1.RegistrirajUtakmicu("FK Sarajevo", "NK Celik",2,1) ;
    l1.RegistrirajUtakmicu("FK Zeljeznicar", "FK Sloboda",2,2) ;
    l1.RegistrirajUtakmicu("FK Olimpic", "FK Mladost",1,2) ;


    l1.RegistrirajUtakmicu("NK Celik", "FK Zeljeznicar", 1,4) ;
    l1.RegistrirajUtakmicu("FK Olimpic", "FK Sarajevo" ,1,1) ;
    l1.RegistrirajUtakmicu("FK Mladost", "FK Sloboda", 1,2) ;

    l1.RegistrirajUtakmicu("FK Zeljeznicar", "FK Sarajevo", 1,1) ;
    l1.RegistrirajUtakmicu("FK Sloboda", "NK Celik",1,3) ;
    l1.RegistrirajUtakmicu("FK Olimpic", "FK Mladost",1,1) ;

    l1.RegistrirajUtakmicu("FK Sarajevo", "FK Mladost",1,1) ;
    l1.RegistrirajUtakmicu("FK Zeljeznicar", "NK Celik" , 1,2) ;
    l1.RegistrirajUtakmicu("FK Sloboda", "FK Olimpic", 0,2) ;

    Tim t1("FK Sarajevo") ;
    Tim t2("FK Zeljeznicar") ;
    Tim t3("NK Celik") ;
    Tim t6 ("FK Sloboda") ;
    Tim t4("FK Mladost") ;
    Tim t5 ("FK Olimpic") ;

    Liga l2 {t1,t2,t3,t4,t5,t6} ;

    l2.RegistrirajUtakmicu("FK Sarajevo", "NK Celik",1,2) ;
    l2.RegistrirajUtakmicu("FK Zeljeznicar", "FK Sloboda",2,2) ;
    l2.RegistrirajUtakmicu("FK Olimpic", "FK Mladost",1,2) ;


    l2.RegistrirajUtakmicu("NK Celik", "FK Zeljeznicar", 1,3) ;
    l2.RegistrirajUtakmicu("FK Olimpic", "FK Sarajevo" ,1,2) ;
    l2.RegistrirajUtakmicu("FK Mladost", "FK Sloboda", 2,2) ;

    l2.RegistrirajUtakmicu("FK Zeljeznicar", "FK Sarajevo", 2,2) ;
    l2.RegistrirajUtakmicu("FK Sloboda", "NK Celik",2,3) ;
    l2.RegistrirajUtakmicu("FK Olimpic", "FK Mladost",1,0) ;

    l2.RegistrirajUtakmicu("NK Celik", "FK Olimpic", 1,2) ;
    l2.RegistrirajUtakmicu("FK Sloboda", "FK Zeljeznicar",2,3) ;
    l2.RegistrirajUtakmicu("FK Sarajevo", "FK Mladost",1,0) ;

    Liga l3(l1) ;

    l1 = l2 ;
    l2 = l3 ;

    l1.IspisiTabelu() ;

    l2 = l2;
    l2 = l2 = l2 = l2;

    l2.IspisiTabelu();
	return 0;
}

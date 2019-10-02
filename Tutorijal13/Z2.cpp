// TP 16/17 (Tutorijal 13, Zadatak 2)
#include <iostream>
#include <string>

class ApstraktniStudent
{
protected:
	std::string ime;
	std::string prezime;
	int brojIndeksa;
	int brojPolozenih;
	double prosjecnaOcjena;
public:
	ApstraktniStudent(std::string ime, std::string prezime, int brojIndeksa) : ime(ime), prezime(prezime), brojIndeksa(brojIndeksa), brojPolozenih(0), prosjecnaOcjena(5) {}
	ApstraktniStudent(std::string ime, std::string prezime, int brojIndeksa, int brojPolozenih, double prosjecnaOcjena) : ime(ime), prezime(prezime), brojIndeksa(brojIndeksa), brojPolozenih(brojPolozenih), prosjecnaOcjena(prosjecnaOcjena) {}
	virtual ~ApstraktniStudent()  {};
	std::string DajIme() const { return ime; }
	std::string DajPrezime() const { return prezime; }
	int DajBrojIndeksa() const { return brojIndeksa; }
	int DajBrojPolozenih() const { return brojPolozenih; }
	double DajProsjek() const { return prosjecnaOcjena; }
	void RegistrirajIspit(int ocjena);
	void PonistiOcjene();
	virtual void IspisiPodatke() const = 0 ;
	virtual ApstraktniStudent* DajKopiju() const = 0;
};

class StudentBachelor : public ApstraktniStudent
{
public:
	StudentBachelor(std::string ime, std::string prezime, int brojIndeksa) : ApstraktniStudent(ime, prezime, brojIndeksa) {}
	StudentBachelor(std::string ime, std::string prezime, int brojIndeksa, int brojPolozenih, double prosjecnaOcjena) : ApstraktniStudent(ime, prezime, brojIndeksa, brojPolozenih, prosjecnaOcjena) {}
	void IspisiPodatke() const override {
		std::cout << "Student bachelor studija " << ime << " " << prezime << ", sa brojem indeksa " << brojIndeksa << "," << std::endl << "ima prosjek " << prosjecnaOcjena << "." << std::endl;
	}
	ApstraktniStudent* DajKopiju() const override {
		return new StudentBachelor(ime, prezime, brojIndeksa, brojPolozenih, prosjecnaOcjena);
	}
};

class StudentMaster : public ApstraktniStudent
{
private:
	int godina;
public:
	StudentMaster(std::string ime, std::string prezime, int brojIndeksa, int godina) : ApstraktniStudent(ime, prezime, brojIndeksa), godina(godina) {}
	StudentMaster(std::string ime, std::string prezime, int brojIndeksa, int brojPolozenih, double prosjecnaOcjena, int godina) : ApstraktniStudent(ime, prezime, brojIndeksa, brojPolozenih, prosjecnaOcjena), godina(godina) {}
	void IspisiPodatke() const override {
		std::cout << "Student master studija " << ime << " " << prezime << ", sa brojem indeksa " << brojIndeksa << "," << std::endl << "zavrsio bachelor studij godine " << godina << ",ima prosjek " << prosjecnaOcjena << "." << std::endl;
	}
	ApstraktniStudent* DajKopiju() const override {
		return new StudentMaster(ime, prezime, brojIndeksa, brojPolozenih, prosjecnaOcjena, godina);
	}
};

void ApstraktniStudent::RegistrirajIspit(int ocjena){
	if(ocjena < 5 || ocjena > 10) throw std::domain_error("Neispravna ocjena");
	if(ocjena > 5){
		double ocjenaPomocna = prosjecnaOcjena * brojPolozenih;
		this->brojPolozenih++;
		this->prosjecnaOcjena = (ocjenaPomocna + ocjena) / brojPolozenih;
	}
}

void ApstraktniStudent::PonistiOcjene(){
	this->brojPolozenih = 0;
	this->prosjecnaOcjena = 5;
}

int main ()
{
	//Student Master
	ApstraktniStudent *ps, *pskopija;
	ps = new StudentBachelor("Dusko", "Dugousko", 1234);
	ps->RegistrirajIspit(7); ps->RegistrirajIspit(6); ps->RegistrirajIspit(5);
	ps->RegistrirajIspit(10); ps->RegistrirajIspit(7);
	std::cout << "Originalni student: " << std::endl;
	std::cout << "-----------------" << std::endl;
	ps->IspisiPodatke();

	pskopija = ps->DajKopiju();
	std::cout << "Kopija student: " << std::endl;
	std::cout << "-----------------" << std::endl;
	pskopija->IspisiPodatke();


	ps->RegistrirajIspit(10);

	std::cout << "Originalni student nakon izmjene: " << std::endl;
	std::cout << "-----------------" << std::endl;
	ps->IspisiPodatke();


	std::cout << "Kopija student: " << std::endl;
	std::cout << "-----------------" << std::endl;
	pskopija->IspisiPodatke();

	delete pskopija;
	delete ps;

	//Student bachelor
	ApstraktniStudent *s, *skopija;
	s = new StudentMaster("Dusko", "Dugousko", 1234, 2014);
	s->RegistrirajIspit(7); s->RegistrirajIspit(6); s->RegistrirajIspit(5);
	s->RegistrirajIspit(10); s->RegistrirajIspit(7);
	std::cout << "Originalni student: " << std::endl;
	std::cout << "-----------------" << std::endl;
	s->IspisiPodatke();

	skopija = s->DajKopiju();
	std::cout << "Kopija student: " << std::endl;
	std::cout << "-----------------" << std::endl;
	skopija->IspisiPodatke();


	s->RegistrirajIspit(10);

	std::cout << "Originalni student nakon izmjene: " << std::endl;
	std::cout << "-----------------" << std::endl;
	s->IspisiPodatke();


	std::cout << "Kopija student: " << std::endl;
	std::cout << "-----------------" << std::endl;
	skopija->IspisiPodatke();

	delete skopija;
	delete s;
	return 0;
}

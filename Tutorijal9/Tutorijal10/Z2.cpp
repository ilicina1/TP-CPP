// TP 16/17 (Tutorijal 10, Zadatak 2)
#include <iostream>
#include <cmath>
#include <iomanip>

class Krug{
private:
	double poluprecnik;
public:
	Krug(double x){
		if(x <= 0) throw std::domain_error("Neispravan poluprecnik");
		else Krug::poluprecnik = x;
	}
	void Postavi(double x) {
		if(x <= 0) throw std::domain_error("Neispravan poluprecnik");
		else Krug::poluprecnik = x;
	}
	double DajPoluprecnik() const { return poluprecnik; }
	double DajObim() const { return 2 * poluprecnik * (4 * atan(1.0)); }
	double DajPovrsinu() const { return (4 * atan(1.0)) * pow(poluprecnik, 2); }
	Krug &Skaliraj(double x) {
		if(x <= 0) throw std::domain_error("Neispravan faktor skaliranja");
		else poluprecnik *= x;
		return *this;
	}
	void Ispisi() const {
		std::cout << "R=" << std::fixed << std::setprecision(5) << DajPoluprecnik() << " O=" << std::fixed<<std::setprecision(5) << DajObim() << " P=" << std::fixed<<std::setprecision(5) << DajPovrsinu();
	}
};

class Valjak{
private:
	Krug baza;
	double visina;
public:
	Valjak(const Krug &x, const double y) : baza(x) {
		if(x.DajPoluprecnik() < 0) throw std::domain_error("Neispravan poluprecnik");
		if(y < 0) throw std::domain_error("Neispravna visina");
		else {
			this->baza = x;
			this->visina = y;
		}
	}

	void Postavi(Krug x, double y){
		if(x.DajPoluprecnik() < 0) throw std::domain_error("Neispravan poluprecnik");
		if(y < 0) throw std::domain_error("Neispravna visina");
		else {
			this->baza = x;
			this->visina = y;
		}
	}

	Krug DajBazu() const { return this->baza; }
	double DajPoluprecnikBaze() const { return this->baza.DajPoluprecnik(); }
	double DajVisinu() const { return this->visina; }
	double DajPovrsinu() const { return (2 * baza.DajPovrsinu()) + (baza.DajObim() * visina); }
	double DajZapreminu() const { return baza.DajPovrsinu() * visina; }
	Valjak &Skaliraj(double faktor) {
		if(faktor <= 0) throw std::domain_error("Neispravan faktor skaliranja");
		else baza.Skaliraj(faktor);
		return *this;
	}

	void Ispisi() const {
		std::cout << "R=" << std::fixed<<std::setprecision(5) << DajPoluprecnikBaze() << " H=" << std::fixed<<std::setprecision(5) << DajVisinu() << " P=" << std::fixed<<std::setprecision(5) << DajPovrsinu() << " V=" << std::fixed<<std::setprecision(5) << DajZapreminu();
	}
};

int main ()
{
	Krug k(5);
	k.Skaliraj(10);
	Valjak v(5,5);
	v.Skaliraj(10);
	std::cout<<k.DajPoluprecnik()<<std::endl;
	std::cout<<v.DajBazu().DajPoluprecnik()<<std::endl;
	return 0;
}

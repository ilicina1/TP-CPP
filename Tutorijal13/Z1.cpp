// TP 16/17 (Tutorijal 13, Zadatak 1)
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <memory>

class Lik
{
public:
	virtual void IspisiSpecificnosti() = 0;
	virtual double DajObim() const = 0;
	virtual double DajPovrsinu() const = 0;
	virtual void Ispisi() = 0;

};

class Krug : public Lik
{
	double poluprecnik;
	static constexpr double PI = atan(1) * 4;
public:
	Krug(double poluprecnik) : poluprecnik(poluprecnik) {
		if(poluprecnik <= 0) throw std::domain_error("Neispravni parametri");
	}
	double DajObim() const { return 2 * poluprecnik * PI; }
	double DajPovrsinu() const { return pow(poluprecnik, 2) * PI; }
	void IspisiSpecificnosti() { std::cout << std::endl << "Krug poluprecnika " << poluprecnik << std::endl; }
	void Ispisi() {
		IspisiSpecificnosti();
		std::cout << "Obim: " << DajObim() << " Povrsina: " << DajPovrsinu();
	}
};

class Pravougaonik : public Lik
{
	double a, b;
public:
	Pravougaonik(double a, double b) : a(a), b(b) { if(a <= 0 || b <= 0) throw std::domain_error("Neispravni parametri"); }
	double DajObim() const { return 2 * a + 2 * b; }
	double DajPovrsinu() const { return a * b; }
	void IspisiSpecificnosti() { std::cout << std::endl << "Pravougaonik sa stranicama duzine " << a << " i " << b << std::endl; }
	void Ispisi() {
		IspisiSpecificnosti();
		std::cout << "Obim: " << DajObim() << " Povrsina: " << DajPovrsinu();
	}
};

class Trougao : public Lik
{
	double a, b, c;
public:
	Trougao(double a, double b, double c) : a(a), b(b), c(c) {
		if(a <= 0 || b <= 0 || c <= 0) throw std::domain_error("Neispravni parametri");
		if(a + b <= c || a + c <= b || b + c <= a) throw std::domain_error("Neispravni parametri");
	}
	double DajObim() const { return a + b + c; }
	double DajPovrsinu() const { return (a * b) / 2; }
	void IspisiSpecificnosti() { std::cout << std::endl << "Trougao sa stranicama duzine " << a << ", " << b << " i " << c << std::endl; }
	void Ispisi() {
		IspisiSpecificnosti();
		std::cout << "Obim: " << DajObim() << " Povrsina: " << DajPovrsinu();
	}
};

void ProvjeraZnaka(char znak) { if(znak != ',')  throw std::domain_error("Pogresni podaci"); }
void ProvjeraToka() { if(std::cin.peek() != '\n') throw std::domain_error("Pogresni podaci"); }

std::shared_ptr<Pravougaonik> UnosPravougaonika() {
	double a, b;
	char znak;
	std::cin >> a >> znak >> b;
	ProvjeraZnaka(znak);
	ProvjeraToka();
	return std::make_shared<Pravougaonik> (a,b);
}

std::shared_ptr<Trougao> UnosTrougla() {
	double a, b, c;
	char znak;
	std::cin >> a >> znak >> b;
	ProvjeraZnaka(znak);
	std::cin >> znak >> c;
	ProvjeraZnaka(znak);
	ProvjeraToka();
	return std::make_shared<Trougao> (a,b,c);
}

std::shared_ptr<Krug> UnosKrug() {
	double r;
	std::cin >> r;
	ProvjeraToka();
	return std::make_shared<Krug> (r);
}

std::shared_ptr<Lik> UnosLika(){
	char lik;
	std::cin >> lik;
	if(!isdigit(std::cin.peek())) throw std::domain_error("Neispravni podaci");
	if(lik == 'K') return UnosKrug();
	if(lik == 'P') return UnosPravougaonika();
	if(lik == 'T') return UnosTrougla();
	throw std::logic_error("Neispravni podaci");
}

int main ()
{
	std::cout << "Koliko zelite likova: ";
	int n;
	std::cin >> n;
	std::vector<std::shared_ptr<Lik>> likovi(n);
	for(int i = 0; i < n; i++){
		std::cout << "Lik " << i + 1 << ": ";
		try{ likovi.at(i) = UnosLika();}
		catch(...){
			std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			i--;
		}
	}

	std::cout << std::endl;

	for(const auto &lik : likovi){
		lik->Ispisi();
		std::cout << std::endl;
	}

	return 0;
}

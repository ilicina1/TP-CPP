// TP 16/17 (Tutorijal 10, Zadatak 1)
#include <iostream>

class StedniRacun
{
private:
	double stanjeRacuna;
public:
	StedniRacun() { stanjeRacuna = 0; }
	StedniRacun(double x) {
		if(x < 0) throw std::logic_error("Nedozvoljeno pocetno stanje");
		else stanjeRacuna = x;
	}
	void Ulozi(double x);
	void Podigni(double x);
	double DajStanje() const { return stanjeRacuna; }
	void ObracunajKamatu(double kamatnaStopa);

};

void StedniRacun::Ulozi(double x){
	if((x < 0) && (this->stanjeRacuna + x < 0)) throw std::logic_error("Transakcija odbijena");
	else if((x < 0) && (x - this->stanjeRacuna >= 0)) this->stanjeRacuna -= x;
	else this->stanjeRacuna += x;
}

void StedniRacun::Podigni(double x){
	if(x > this->stanjeRacuna) throw std::logic_error("Transakcija odbijena");
	else this->stanjeRacuna -= x;
}

void StedniRacun::ObracunajKamatu(double x){
	if(x < 0) throw std::logic_error("Nedozvoljena kamatna stopa");
	else this->stanjeRacuna += (x / 100) * this->stanjeRacuna;
}

int main ()
{
	StedniRacun s1=0;
	s1.Ulozi(20);
	std::cout << s1.DajStanje()<<std::endl;
	s1.Ulozi(50);
	std::cout << s1.DajStanje()<<std::endl;
	s1.Ulozi(-10);
	std::cout << s1.DajStanje()<<std::endl;

	return 0;
}

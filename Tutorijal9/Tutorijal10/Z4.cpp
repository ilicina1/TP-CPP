// TP 16/17 (Tutorijal 10, Zadatak 4)
#include <iostream>
#include <cmath>
#include <iomanip>

const double pi = 4 * atan(1);

class Ugao
{
	double radijan;
public:
	Ugao(double radijani = 0) : radijan(radijani){ Postavi(radijani); }
	Ugao(int stepeni, int minute, int sekunde) {
        double decimalDegree = stepeni + minute/60 + sekunde/3600;
        radijan = pi * (decimalDegree/180);
    }
	// void Postavi(double radijani) {
	// 	if(radijani > 2 * pi) this->radijan = fmod(radijani, 2 * pi);
	// }
	void Postavi(double rad){
        if(rad > 2*pi) this->radijan = fmod(rad, 2*pi);
        else if(rad < 0) this->radijan *= (180/pi);
    }
	double DajRadijane() const { return radijan; }
	void OcitajKlasicneJedinice(int &stepeni, int &minute, int &sekunde);
	int DajStepene() const { return radijan * 180 /  pi; }
	int DajMinute() const { return fmod(radijan * 180 / pi, DajStepene() * 60); }
	int DajSekunde() const {
		double sekunde = fmod(radijan * 180 / pi, DajMinute() * 60);
		return fmod(sekunde, DajMinute() * 3600);
	}
	void Ispisi() const { std::cout << std::fixed << std::setprecision(5) << radijan; }
	void IspisiKlasicno() const { std::cout << DajStepene() << "deg " << DajMinute() << "min " << DajSekunde() << "sec"; }
	Ugao &SaberiSa(const Ugao &u);
	Ugao &PomnoziSa(double x);
	friend Ugao ZbirUglova(const Ugao &u1, const Ugao &u2);
	friend Ugao ProduktUglaSaBrojem(const Ugao &u, double x);
};

int main ()
{
	Ugao u1, u2(1), u3(100), u4(-55), u5 = 1, u6=-5;
	Ugao uu(100, 20, 10);
	uu.Ispisi();
	std::cout << std::endl;
	std::cout << std::endl;
	u1.Ispisi(); std::cout << std::endl;
	u2.Ispisi(); std::cout << std::endl;
	u2.IspisiKlasicno(); std::cout << std::endl;
	u3.Ispisi(); std::cout << std::endl;
	u4.Ispisi(); std::cout << std::endl;
	u5.Ispisi(); std::cout << std::endl;
	u6.Ispisi(); std::cout << std::endl;
	return 0;
}

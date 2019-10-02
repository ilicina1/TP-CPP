// TP 16/17 (Tutorijal 9, Zadatak 4)
#include <iostream>
#include <iomanip>
#include <cmath>

class Sat
{
private:
	int sati, minute, sekunde;

public:
	static bool DaLiJeIspravno(int h, int m, int s);
	void Postavi(int sati, int minute, int sekunde);
	void PostaviNormalizirano(int sati, int minute, int sekunde);
	Sat &PomjeriZa(int broj);
	Sat &Sljedeci()
	{
		return PomjeriZa(1);
	}
	Sat &Prethodni(){
		return PomjeriZa(-1);
	}
	int DajSate() const
	{
		return sati;
	}
	int DajMinute() const
	{
		return minute;
	}
	int DajSekunde() const
	{
		return sekunde;
	}
	void Ispisi() const
	{
		std::cout << std::setw(2) << std::setfill('0') << sati << ":" << std::setw(2) << std::setfill('0') << minute << ":" << std::setw(2) << std::setfill('0') << sekunde;
	};
	friend int BrojSekundiIzmedju(const Sat &s1, const Sat &s2);
	static int Razmak(const Sat &s1, const Sat &s2);
};

bool Sat::DaLiJeIspravno(int sati, int minute, int sekunde)
{
	if((sati >= 0 && sati <= 23) && (minute >= 0 && minute <= 59) && (sekunde >= 0 && sekunde <= 59)) return true;
	return false;
}

void Sat::Postavi(int sati, int minute, int sekunde)
{
	if(sekunde < 0 || sekunde >= 60 || minute < 0 || minute >= 60 || sati < 0 || sati >= 24) throw std::domain_error("Nesipravno vrijeme");
	this->sati = sati;
	this->minute = minute;
	this->sekunde = sekunde;
}

void Sat::PostaviNormalizirano(int sati, int minute, int sekunde)
{
	Sat::sekunde = sekunde;
	Sat::minute = minute;
	Sat::sati = sati;

	if(Sat::sekunde >= 59) {
		int brojac = this->sekunde / 60;
		this->sekunde %= 60;
		for(int i = 0; i < brojac; i++)	this->minute++;
	}
	if(Sat::sekunde < 0) {
		this->sekunde += 60;
		this->minute--;
	}

	if(Sat::minute >= 59) {
		int brojac2 = this->minute / 60;
		this->minute %= 60;
		for(int i = 0; i < brojac2; i++) this->sati++;
	}
	if(Sat::minute < 0) {
		this->minute += 60;
		this->sati--;
	}

	if(Sat::sati >= 23) {
		this->sati %= 24;
	}
	if(Sat::sati < 0) {
		while(this->sati < 0){
			this->sati += 24;
		}
	}


}

Sat &Sat::PomjeriZa(int broj)
{
	sekunde += broj;
	Sat::PostaviNormalizirano(Sat::sati, Sat::minute, Sat::sekunde);


	return *this;
}

int BrojSekundiIzmedju(const Sat &s1, const Sat &s2)
{
	return s1.DajSekunde() + s1.DajMinute() * 60 + s1.DajSate() * 3600 - s2.DajSekunde() - s2.DajMinute() * 60 - s2.DajSate() * 3600;
}

int Sat::Razmak(const Sat &s1, const Sat &s2)
{
	return s1.DajSekunde() + s1.DajMinute() * 60 + s1.DajSate() * 3600 - s2.DajSekunde() - s2.DajMinute() * 60 - s2.DajSate() * 3600;
}

int main ()
{

  Sat s;
  s.Postavi(10,10,10);
  s.Prethodni().Ispisi();
  std::cout << std::endl;
  s.Prethodni().Prethodni().Ispisi();
  std::cout << std::endl;

  s.Postavi(0,0,0);
  s.Prethodni().Ispisi(); std::cout << std::endl;
  s.Postavi(10,0,0);
  s.Prethodni().Ispisi(); std::cout << std::endl;
  s.Postavi(10,10,0);
  s.Prethodni().Ispisi(); std::cout << std::endl;
	return 0;
}

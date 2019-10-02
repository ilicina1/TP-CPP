// TP 16/17 (Tutorijal 12, Zadatak 1)
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
	Sat(int sati, int minute, int sekunde) : sati(sati), minute(minute), sekunde(sekunde) { PostaviNormalizirano(sati, minute, sekunde); }
	Sat() : sati(0), minute(0), sekunde(0) {}

	friend int operator -(const Sat &s1, const Sat &s2){ return s1.sekunde + s1.minute * 60 + s1.sati * 3600 - s2.sekunde - s2.minute * 60 - s2.sati * 3600; }
	friend Sat operator -(const Sat &s1, int broj){
		Sat pomocni = s1;
		pomocni.sekunde -= broj;
		pomocni.PostaviNormalizirano(pomocni.sati, pomocni.minute, pomocni.sekunde);
		return pomocni;
	}
	friend int operator +(const Sat &s1, const Sat &s2){ return s1.sekunde + s1.minute * 60 + s1.sati * 3600 + s2.sekunde + s2.minute * 60 + s2.sati * 3600; }
	friend Sat operator +(const Sat &s1, int broj){
		Sat pomocni = s1;
		pomocni.sekunde += broj;
		pomocni.PostaviNormalizirano(pomocni.sati, pomocni.minute, pomocni.sekunde);
		return pomocni;
	}
	friend Sat &operator ++(Sat &s){ s.sekunde += 1; return s; }
	friend Sat &operator --(Sat &s){ s.sekunde -= 1; return s; }
	friend Sat operator ++(Sat &s, int){ Sat pomocni = s; ++s; return pomocni; }
	friend Sat operator --(Sat &s, int){ Sat pomocni = s; --s; return pomocni; }
	friend Sat &operator +=(Sat &s, int broj){ s.sekunde += broj; s.PostaviNormalizirano(s.sati, s.minute, s.sekunde); return s; }
	friend Sat &operator -=(Sat &s, int broj){ s.sekunde -= broj; s.PostaviNormalizirano(s.sati, s.minute, s.sekunde); return s; }
	friend std::ostream &operator <<(std::ostream &tok, const Sat &s){
		return tok << std::setw(2) << std::setfill('0') << s.sati << ":" << std::setw(2) << std::setfill('0') << s.minute << ":" << std::setw(2) << std::setfill('0') << s.sekunde;
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

	while(Sat::sekunde >= 59) {
		int brojac = this->sekunde / 60;
		this->sekunde %= 60;
		for(int i = 0; i < brojac; i++)	this->minute++;
	}
	while(Sat::sekunde < 0) {
		this->sekunde += 60;
		this->minute--;
	}

	while(Sat::minute >= 59) {
		int brojac2 = this->minute / 60;
		this->minute %= 60;
		for(int i = 0; i < brojac2; i++) this->sati++;
	}
	while(Sat::minute < 0) {
		this->minute += 60;
		this->sati--;
	}

	while(Sat::sati >= 23) {
		this->sati %= 24;
	}
	while(Sat::sati < 0) {
		while(this->sati < 0){
			this->sati += 24;
		}
	}


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
	 Sat s1(11, 4, 39);
  std::cout << s1 << std::endl;
  Sat s2(25, 150, 1000);
  std::cout << s2 << std::endl;
  std::cout << s1 - s2 << std::endl;
  std::cout << s1 + 100 << std::endl;
  std::cout << s1 << std::endl;
  std::cout << s1 - 100 << std::endl;
  std::cout << s1 << std::endl;
  s2 = s1 += 100;
  std::cout << s2 << std::endl;
	return 0;
}

// TP 16/17 (Tutorijal 11, Zadatak 1)
#include <iostream>

class NeobicnaKlasa {

	public:

	 NeobicnaKlasa(double x) { std :: cout << "Kopirajuca inicijalizacija"; std :: cout << std :: endl;}       // Sto nije int je kopirajuca inicijalizacija

	explicit NeobicnaKlasa(int x) { std :: cout << "Direktna inicijalizacija"; std :: cout << std :: endl; }



};


int main ()
{

	NeobicnaKlasa k1(5);
	NeobicnaKlasa k2 = 5;


	return 0;
}

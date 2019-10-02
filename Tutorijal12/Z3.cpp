// TP 16/17 (Tutorijal 12, Zadatak 3)
#include <iostream>

enum Dani {Ponedjeljak, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};

std::ostream &operator <<(std::ostream &tok, const Dani &d){
	if(d == 0) tok << "Ponedjeljak";
	if(d == 1) tok << "Utorak";
	if(d == 2) tok << "Srijeda";
	if(d == 3) tok << "Cetvrtak";
	if(d == 4) tok << "Petak";
	if(d == 5) tok << "Subota";
	if(d == 6) tok << "Nedjelja";
	return tok;
}

Dani operator ++(Dani &d){
	return d = Dani(((int)d + 1)%7);
}

Dani operator ++(Dani &d, int){
	auto d2(d); ++d;
    return d2;
}

int main ()
{
	for(Dani d = Ponedjeljak; d <= Petak; d++) std::cout << d << std::endl;
	for(Dani d = Ponedjeljak; d <= Nedjelja; d++) {
		std::cout << d << std::endl;
		if(d == Nedjelja) break;
	}
	return 0;
}

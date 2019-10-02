//TP, 2018/2019, Zadaća 1, Zadatak 3
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

typedef std::vector<std::vector<int>> Matrica;
typedef std::vector<int> Vektor;

Matrica KreirajMatricu(int broj_redova, int broj_kolona)
{
	return Matrica(broj_redova, Vektor(broj_kolona) );
}

int brojRedova(Matrica m)
{
	return m.size();
}

int brojKolona(Matrica m)
{
	return m.at(0).size();
}


Matrica KroneckerovProizvod(Matrica a, Matrica b)
{

/*	bool prva = false, druga = false;

	for(int i = 0; i < brojKolona(a); i++) {
		if(a.at(0).size() != a.at(i).size()) {
			prva = true;
			break;
		}
	}

	for(int i = 0; i < brojKolona(b); i++) {
		if(b.at(0).size() != b.at(i).size()) {
			druga = true;
			break;
		}
	}

	if(prva && druga) throw "Parametri nemaju formu matrice";
	if(prva) throw "Prvi parametar nema formu matrice";
	if(druga) throw "Drugi parametar nema formu matrice";
*/
	Matrica konacna;

	for(int i = 0; i < brojRedova(a); i++) {
		for(int j = 0; j < brojRedova(b); j++) {
			Vektor pomocni;
			for(int k = 0; k < brojKolona(a); k++) {
				for(int l = 0; l < brojKolona(b); l++) {
					pomocni.push_back(a.at(i).at(k) * b.at(j).at(l));
				}
			}
			konacna.push_back(pomocni);
		}
	}

	return konacna;
}

int Sirina(int x)
{
	int length = 0;

	if(x < 0) {
		length = log10(abs(x)) + 2;
	} else {
		length = log10(x) + 1;
	}

	return length;
}

int NajvecaSirina(Matrica m)
{
	int maxSirina = 0;

	for(int i = 0; i < brojRedova(m); i++) {
		for(int j = 0; j < brojKolona(m); j++) {
			int sirina = 0;

			sirina = Sirina(m.at(i).at(j));

			if(sirina > maxSirina) maxSirina = sirina;
		}
	}

	return maxSirina;
}


int main ()
{

	int broj_redova = 0, broj_kolona = 0;

	std::cout << "Unesite dimenzije prve matrice:" << std::endl;
	std::cin >> broj_redova >> broj_kolona;


	std::cout << "Unesite elemente prve matrice:" << std::endl;
	Matrica prva = KreirajMatricu(broj_redova, broj_kolona);

	for(int i = 0; i < broj_redova; i++) {
		for(int j = 0; j < broj_kolona; j++) {
			std::cin >> prva.at(i).at(j);
		}
	}

	int broj_redova2 = 0, broj_kolona2 = 0;

	std::cout << "Unesite dimenzije druge matrice:" << std::endl;
	std::cin >> broj_redova2 >> broj_kolona2;

	std::cout << "Unesite elemente druge matrice:" << std::endl;
	Matrica druga = KreirajMatricu(broj_redova2, broj_kolona2);

	for(int i = 0; i < broj_redova2; i++) {
		for(int j = 0; j < broj_kolona2; j++) {
			std::cin >> druga.at(i).at(j);
		}
	}

	Matrica konacna;


	konacna = KroneckerovProizvod(prva, druga);

	std::cout << "Njihov Kroneckerov proizvod glasi:" << std::endl;

	int sirina = NajvecaSirina(konacna);

	for(auto i : konacna) {
		for(auto j : i) std::cout << std::right << std::setw(sirina + 1) << j;
		std::cout << std::endl;
	}


	return 0;
}

// TP 2018/2019: Tutorijal 5, Zadatak 3
#include <iostream>
#include <algorithm>
#include <cmath>

bool najmanjiBrojCifara(int a, int b)
{

	a = log10(abs(a) + 1);
	b = log10(abs(b) + 1);

	return (a < b);
}

bool neTrocifreniBrojevi(int a)
{

	return abs(a) < 100 || abs(a) >= 1000;

}

bool potpuniKvadrat(int p)
{
	int korijen = sqrt(p);
	if(p == korijen * korijen) {
		return true;
	}

	return false;
}

void unesi(int &a)
{
	std::cin >> a;
}

void ispisi(int a)
{
	std::cout << a;
}

int main ()
{
	std::cout << "Unesite broj elemenata (max. 1000): ";

	int n;

	do {
		std::cin >> n;
	} while(n < 1 || n > 1000);

	std::cout << "Unesite elemente: ";

	int niz[1000];

	std::for_each(niz, niz + n, unesi);

	std::cout << "Najveci element niza je " << *std::max_element(niz, niz + n) << std::endl;

	int min = *std::min_element(niz, niz + n);

	std::cout << "Najmanji element niza se pojavljuje " << std::count(niz, niz + n, min)<< " puta u nizu" << std::endl;

	std::cout << "U nizu ima " << std::count_if(niz, niz + n, potpuniKvadrat) << " brojeva koji su potpuni kvadrati" << std::endl;


	std::cout << "Prvi element sa najmanjim brojem cifara je " << *std::min_element(niz, niz + n, najmanjiBrojCifara) << std::endl;

	int niz2[1000];
	int m;

	m = std::count_if(niz, niz + n, neTrocifreniBrojevi);

	std::copy_if(niz, niz + n, niz2, neTrocifreniBrojevi);


	std::cout << "Elementi koji nisu trocifreni su: ";

	std::for_each(niz2, niz2 + m, [] (int a) {std::cout << a << " ";});
	return 0;
}

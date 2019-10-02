// TP 2018/2019: Tutorijal 5, Zadatak 4
#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>

int main ()
{
	std::cout << "Unesite broj elemenata: ";

	int n;

	std::cin >> n;

	std::cout << "Unesite elemente: ";

	std::deque<int> dek(n);

	std::for_each(dek.begin(), dek.end(), [] (int &a) {
		std::cin >> a;
	});

	std::cout << "Najveci element deka je " << *std::max_element(dek.begin(), dek.end()) << std::endl;

	int min = *std::min_element(dek.begin(), dek.end());

	std::cout << "Najmanji element deka se pojavljuje " << std::count(dek.begin(), dek.end(), min)<< " puta u deku" << std::endl;

	std::cout << "U deku ima " << std::count_if(dek.begin(), dek.end(), [] (int p) {
		int korijen = sqrt(p);
		if(p == korijen * korijen) {
		return true;
		}

		return false;
	}) << " brojeva koji su potpuni kvadrati" << std::endl;


	std::cout << "Prvi element sa najmanjim brojem cifara je " << *std::min_element(dek.begin(), dek.end(), [] (int a, int b){
		a = log10(abs(a) + 1);
		b = log10(abs(b) + 1);

		return (a < b);
	}) << std::endl;

	int m = std::count_if(dek.begin(), dek.end(), [] (int &a){
		return abs(a) < 100 || abs(a) >= 1000;
	});

	std::deque<int> dek2(m);

	std::copy_if(dek.begin(), dek.end(), dek2.begin(), [] (int a){
		return abs(a) < 100 || abs(a) >= 1000;
	});


	std::cout << "Elementi koji nisu trocifreni su: ";

	std::for_each(dek2.begin(), dek2.end(), [] (int a) {
		std::cout << a << " ";
	});

	return 0;
}

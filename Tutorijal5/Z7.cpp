// TP 2018/2019: Tutorijal 5, Zadatak 7
#include <iostream>
#include <deque>

template <typename nekiTip>
	auto SumaBloka(nekiTip p1, nekiTip p2) -> decltype (*p1 + *p1){

		auto suma = 0.;

		while(p1 != p2){
			suma += *p1;
			++p1;
		}

		return suma;
	}

int main ()
{
	std::deque<double> dek;

	std::cout << "Unesite broj elemenata deka: ";

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){

		double a = 0;

		std::cin >> a;
		dek.push_back(a);

	}

	auto suma = SumaBloka(dek.begin(), dek.end());

	std::cout << "Suma elemenata iznosi: " << suma;

	return 0;
}

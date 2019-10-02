// TP 16/17 (Tutorijal 7, Zadatak 8)
#include <iostream>
#include <string>
#include <algorithm>

std::string IzvrniBezRazmaka(std::string recenica)
{
	std::string pomocnaRecenica;

	remove_copy(recenica.rbegin(), recenica.rend(), back_inserter(pomocnaRecenica), ' ');

//	std::reverse(recenica.begin(), recenica.end());

	return pomocnaRecenica;
}

int main ()
{
	std::string recenica;

	std::cout << "Unesite recenicu: ";

	std::getline(std::cin, recenica);

	std::cout << "Izvrnuta recenica bez razmaka glasi: ";

	std::string izvrnutaRecenica = IzvrniBezRazmaka(recenica);

	std::cout << izvrnutaRecenica;
	return 0;
}

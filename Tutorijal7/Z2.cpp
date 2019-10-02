// TP 16/17 (Tutorijal 7, Zadatak 2)
#include <iostream>
#include <cstring>
#include <algorithm>

int main ()
{
	int brojRecenica = 0;

	std::cout << "Koliko zelite recenica: ";
	std::cin >> brojRecenica;
	std::cin.ignore(10000, '\n');

	std::cout << "Unesite recenice:" << std::endl;

	try {
		char **recenice = new char*[brojRecenica];
		for(int i = 0; i < brojRecenica; i++) recenice[i] = nullptr;
		for(int i = 0; i < brojRecenica; i++) {
			char radniProstor[1000];
			std::cin.getline(radniProstor, sizeof radniProstor);

			recenice[i] = new char[std::strlen(radniProstor) + 1];
			std::strcpy(recenice[i], radniProstor);
		}

		std::sort(recenice, recenice + brojRecenica, [] (const char *a, const char *b) {
			return std::strcmp(a,b) < 0;
		});

	std::cout << "Sortirane recenice:" << std::endl;

	for(int i = 0; i < brojRecenica; i++) {
	std::cout << recenice[i] << std::endl;
	}

	for(int i = 0; i < brojRecenica; i++) delete[] recenice[i];

	delete[] recenice;

} catch(std::bad_alloc)
{
	std::cout << "Problemi s memorijom!";
}

return 0;
}

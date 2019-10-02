// TP 16/17 (Tutorijal 7, Zadatak 1)
#include <iostream>
#include <cstring>

template <typename tip>
void bubbleSort(tip &recenica, int n)
{
	for(int i = 0; i < n - 1; i++) {
		for(int j =0; j < n - i - 1; j++) {
			if(strcmp(recenica[j], recenica[j + 1]) > 0) std::swap(recenica[j], recenica[j + 1]);
		}
	}

}

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

		bubbleSort(recenice, brojRecenica);

		std::cout << "Sortirane recenice:" << std::endl;

		for(int i = 0; i < brojRecenica; i++) {
			std::cout << recenice[i] << std::endl;
		}

		for(int i = 0; i < brojRecenica; i++) delete[] recenice[i];

		delete[] recenice;

	} catch(std::bad_alloc) {
		std::cout << "Problemi s memorijom!";
	}

	return 0;
}

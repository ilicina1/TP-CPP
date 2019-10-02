// TP 16/17 (Tutorijal 7, Zadatak 3)
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

int main ()
{
	int brojRecenica = 0;

	std::cout << "Koliko zelite recenica: ";
	std::cin >> brojRecenica;
	std::cin.ignore(10000, '\n');

	std::cout << "Unesite recenice:" << std::endl;

	try {
		std::string **recenice = new std::string*[brojRecenica];
		for(int i = 0; i < brojRecenica; i++) recenice[i] = nullptr;
		for(int i = 0; i < brojRecenica; i++) {
			recenice[i] = new std::string;
			std::getline(std::cin, *recenice[i]);
		}

		std::sort(recenice, recenice + brojRecenica, [] (const std::string *a, const std::string *b) {
			return *a < *b;
		});

		std::cout << "Sortirane recenice:" << std::endl;

		for(int i = 0; i < brojRecenica; i++) {
			std::cout << *recenice[i]<< std::endl;
		}

		for(int i = 0; i < brojRecenica; i++) delete recenice[i];

		delete[] recenice;

	} catch(std::bad_alloc) {
		std::cout << "Problemi s memorijom!";
	}

	return 0;
}

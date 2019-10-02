#include <iostream>
#include <list>

template <typename nekiTip>
std::list<nekiTip> SortirajListu(std::list<nekiTip> &lista)
{   
    for(auto i = lista.begin(); i != lista.end(); i++){
        for(auto j = lista.begin(); j != lista.end(); j++){
            if(j == lista.end()) break;
            if(*j > *i) std::swap(*i, *j);
        }
    }
    return lista;
}

int main()
{
    int brojElemenata;

	std::cout << "Koliko ima elemenata: ";
	std::cin >> brojElemenata;

	std::list<int> lista;

	std::cout << "Unesite elemente: ";
	
	for(int i = 0; i < brojElemenata; i++){
		int a = 0;
		std::cin >> a;
		lista.push_back(a);
	}
	
	SortirajListu(lista);
	std::cout << "Sortirana lista: ";
	
	for(auto i = lista.begin(); i != lista.end(); i++) std::cout << *i << " ";
}

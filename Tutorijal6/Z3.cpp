// TP 2018/2019: Tutorijal 6, Zadatak 3
#include <iostream>
#include <new>

int **KreirajTrougao(int n)
{
	if(n <= 0) throw std::domain_error ("Broj redova mora biti pozitivan");

	try{
		int **m(new int* [n]);
		for(int i = 0; i < n; i++) m[i] = nullptr;

		try{


			for(int i = 0; i < n; i++){
				m[i] = new int [2 * i + 1];
				for(int j = 0; j < (2 * i + 1); j++){
					if(i == 0 && j == 0) m[i][j] = 1;
					else if(j == 0) m[i][j] = i + 1;
					else if(j == (2 * i + 1) - 1) m[i][j] = m[i][j - 1] + 1;
					else m[i][j] = m[i - 1][j - 1];
				}
			}

			return m;
		} catch(...){
			for(int i = 0; i < n; i++) delete[] m[i];
			delete[] m;
			throw;
		}
	} catch(...){
		throw;
	}
}

int main ()
{
	int n;

	std::cout << "Koliko zelite redova: ";
	std::cin >> n;

	try{
		int **m = KreirajTrougao(n);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 2 * i + 1; j++) std::cout << m[i][j] << " ";
			std::cout << std::endl;
		}

		for(int i = 0; i < n; i++) delete[] m[i];
		delete[] m;

	} catch(std::bad_alloc){
		std::cout << "Izuzetak: Nedovoljno memorije!";
	}
	catch(std::domain_error poruka){
		std::cout << "Izuzetak: " << poruka.what();
	}

	return 0;
}

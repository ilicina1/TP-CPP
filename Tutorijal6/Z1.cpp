// TP 2018/2019: Tutorijal 6, Zadatak 1
#include <iostream>
#include <limits>
#include <cmath>

template <typename nekiTip>
	nekiTip *GenerirajStepeneDvojke(int n)
	{
		if(n <= 0) throw std::domain_error ("Broj elemenata mora biti pozitivan");

		nekiTip *pokNaNiz = nullptr;
		try{
			pokNaNiz = new nekiTip[n];
		}catch(...){
			std::runtime_error("Alokacija nije uspjela");
		}

		for(int i = 0; i < n; i++) {
			if(std::numeric_limits<nekiTip>::max() - pow(2, i) < 0){
				delete[] pokNaNiz;
				throw std::overflow_error("Prekoracen dozvoljeni opseg");
			}

			pokNaNiz[i] = pow(2, i);
		}

		return pokNaNiz;
	}

int main ()
{
	try{
	int n;

	std::cout << "Koliko zelite elemenata: ";
	std::cin >> n;

	int *nizBrojeva = nullptr;

	nizBrojeva = GenerirajStepeneDvojke<int>(n);

	for(int i = 0; i < n; i++) std::cout << nizBrojeva[i] << " ";

	delete[] nizBrojeva;

	} catch(std::domain_error poruka){
		std::cout << "Izuzetak: " << poruka.what();
	} catch(std::runtime_error poruka){
		std::cout << "Izuzetak: " << poruka.what();
	}
	catch(std::overflow_error poruka){
		std::cout << "Izuzetak: " << poruka.what();
	}

	return 0;
}

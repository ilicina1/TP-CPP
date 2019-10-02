// TP, 2018/2019, Zadaća 1, Zadatak 2
#include <iostream>
#include <complex>
#include <vector>

typedef std::vector<std::vector<int>> Matrica;
typedef std::vector<int> Vektor;
typedef std::complex<double> Kompleksni;

Matrica KreirajMatricu(int broj_redova, int broj_kolona)
{
	return Matrica(broj_redova, Vektor(broj_kolona) );
}


std::complex<double> VrhMatrice(Matrica m, int x, int y)
{
	for(int i = 0; i < m.at(0).size(); i++) {
		if(m.at(0).size() != m.at(i).size()) {
			throw "Nekorektna matrica";
			break;
		}
	}

	if(x < 0 || y < 0 || x > m.size() || y > m.at(0).size()) throw "Nekorektna pocetna pozicija";

	int maxNum = 0;
	Kompleksni koordinate;

	for(;;) {

		if(x == 0 && y == 0) {
			if(m.at(x).at(y + 1) > maxNum) {
				maxNum = m.at(x).at(y + 1);
				koordinate = Kompleksni(x, y + 1);
			}
			if(m.at(x + 1).at(y + 1) > maxNum) {
				maxNum = m.at(x + 1).at(y + 1);
				koordinate = Kompleksni(x + 1, y + 1);
			}
			if(m.at(x + 1).at(y) > maxNum) {
				maxNum = m.at(x + 1).at(y);
				koordinate = Kompleksni(x + 1, y);
			}

			x = real(koordinate);
			y = imag(koordinate);
		} else if(x == 0 && y > 0 && y < m.at(0).size() - 1) {
			if(m.at(x).at(y +  1) > maxNum) {
				maxNum = m.at(x).at(y + 1);
				koordinate = Kompleksni(x, y + 1);
			}
			if(m.at(x + 1).at(y + 1) > maxNum) {
				maxNum = m.at(x + 1).at(y + 1);
				koordinate = Kompleksni(x + 1, y + 1);
			}
			if(m.at(x + 1).at(y) > maxNum) {
				maxNum = m.at(x + 1).at(y);
				koordinate = Kompleksni(x + 1, y);
			}
			if(m.at(x + 1).at(y - 1) > maxNum) {
				maxNum = m.at(x + 1).at(y - 1);
				koordinate = Kompleksni(x + 1, y - 1);
			}
			if(m.at(x).at(y - 1) > maxNum) {
				maxNum = m.at(x).at(y - 1);
				koordinate = Kompleksni(x, y - 1);
			}

			x = real(koordinate);
			y = imag(koordinate);
		} else if(y == m.at(0).size() - 1 && x == 0) {
			if(m.at(x + 1).at(y) > maxNum) {
				maxNum = m.at(x - 1).at(y);
				koordinate = Kompleksni(x - 1, y);
			}
			if(m.at(x + 1).at(y - 1) > maxNum) {
				maxNum = m.at(x - 1).at(y - 1);
				koordinate = Kompleksni(x - 1, y - 1);
			}
			if(m.at(x).at(y - 1) > maxNum) {
				maxNum = m.at(x).at(y - 1);
				koordinate = Kompleksni(x, y - 1);
			}

			x = real(koordinate);
			y = imag(koordinate);
		} else if(y == 0 && x > 0 && x < m.size() - 1) {
			if(m.at(x - 1).at(y) > maxNum) {
				maxNum = m.at(x - 1).at(y);
				koordinate = Kompleksni(x - 1, y);
			}
			if(m.at(x - 1).at(y + 1)) {
				maxNum = m.at(x - 1).at(y + 1);
				koordinate = Kompleksni(x - 1, y - 1);
			}
			if(m.at(x).at(y + 1) > maxNum) {
				maxNum = m.at(x).at(y + 1);
				koordinate = Kompleksni(x, y + 1);
			}
			if(m.at(x + 1).at(y + 1) > maxNum) {
				maxNum = m.at(x + 1).at(y + 1);
				koordinate = Kompleksni(x + 1, y + 1);
			}
			if(m.at(x + 1).at(y) > maxNum) {
				maxNum = m.at(x + 1).at(y);
				koordinate = Kompleksni(x + 1, y);
			}

			x = real(koordinate);
			y = imag(koordinate);
		} else if(x == m.size() - 1 && y == 0) {
			if(m.at(x - 1).at(y) > maxNum) {
				maxNum = m.at(x - 1).at(y);
				koordinate = Kompleksni(x - 1, y);
			}
			if(m.at(x - 1).at(y + 1)) {
				maxNum = m.at(x - 1).at(y + 1);
				koordinate = Kompleksni(x - 1, y - 1);
			}
			if(m.at(x).at(y + 1) > maxNum) {
				maxNum = m.at(x).at(y + 1);
				koordinate = Kompleksni(x, y + 1);
			}

			x = real(koordinate);
			y = imag(koordinate);
		} else if(x == m.size() - 1 && y == m.at(0).size() - 1) {
			if(m.at(x - 1).at(y) > maxNum) {
				maxNum = m.at(x - 1).at(y);
				koordinate = Kompleksni(x - 1, y);
			}
			if(m.at(x).at(y - 1) > maxNum) {
				maxNum = m.at(x).at(y - 1);
				koordinate = Kompleksni(x, y - 1);
			}
			if(m.at(x + 1).at(y - 1) > maxNum) {
				maxNum = m.at(x + 1).at(y - 1);
				koordinate = Kompleksni(x + 1, y - 1);
			}

			x = real(koordinate);
			y = imag(koordinate);
		} else if(x > 0 && x < m.size() - 1 && y == m.at(0).size() - 1) {
			if(m.at(x - 1).at(y) > maxNum) {
				maxNum = m.at(x - 1).at(y);
				koordinate = Kompleksni(x - 1, y);
			}
			if(m.at(x + 1).at(y) > maxNum) {
				maxNum = m.at(x + 1).at(y);
				koordinate = Kompleksni(x + 1, y);
			}
			if(m.at(x + 1).at(y - 1) > maxNum) {
				maxNum = m.at(x + 1).at(y - 1);
				koordinate = Kompleksni(x + 1, y - 1);
			}
			if(m.at(x).at(y - 1) > maxNum) {
				maxNum = m.at(x).at(y - 1);
				koordinate = Kompleksni(x, y - 1);
			}
			if(m.at(x - 1).at(y - 1) > maxNum) {
				maxNum = m.at(x - 1).at(y - 1);
				koordinate = Kompleksni(x - 1, y - 1);
			}

			x = real(koordinate);
			y = imag(koordinate);
		} else if(x == m.size() - 1 && y > 0 && y < m.at(0).size() - 1) {
			if(m.at(x - 1).at(y) > maxNum) {
				maxNum = m.at(x - 1).at(y);
				koordinate = Kompleksni(x - 1, y);
			}
			if(m.at(x - 1).at(y + 1) > maxNum) {
				maxNum = m.at(x - 1).at(y + 1);
				koordinate = Kompleksni(x - 1, y + 1);
			}
			if(m.at(x).at(y + 1) > maxNum) {
				maxNum = m.at(x).at(y + 1);
				koordinate = Kompleksni(x, y + 1);
			}
			if(m.at(x).at(y - 1) > maxNum) {
				maxNum = m.at(x).at(y - 1);
				koordinate = Kompleksni(x, y - 1);
			}
			if(m.at(x - 1).at(y - 1) > maxNum) {
				maxNum = m.at(x - 1).at(y - 1);
				koordinate = Kompleksni(x - 1, y - 1);
			}

			x = real(koordinate);
			y = imag(koordinate);
		} else {
			if(m.at(x - 1).at(y) > maxNum) {
				maxNum = m.at(x - 1).at(y);
				koordinate = Kompleksni(x - 1, y);
			}
			if(m.at(x - 1).at(y + 1) > maxNum) {
				maxNum = m.at(x - 1).at(y + 1);
				koordinate = Kompleksni(x - 1, y + 1);
			}
			if(m.at(x).at(y + 1) > maxNum) {
				maxNum = m.at(x).at(y + 1);
				koordinate = Kompleksni(x, y + 1);
			}
			if(m.at(x + 1).at(y + 1) > maxNum) {
				maxNum = m.at(x + 1).at(y + 1);
				koordinate = Kompleksni(x + 1, y + 1);
			}
			if(m.at(x + 1).at(y) > maxNum) {
				maxNum = m.at(x + 1).at(y);
				koordinate = Kompleksni(x + 1, y);
			}
			if(m.at(x + 1).at(y - 1) > maxNum) {
				maxNum = m.at(x + 1).at(y - 1);
				koordinate = Kompleksni(x + 1, y - 1);
			}
			if(m.at(x).at(y - 1) > maxNum) {
				maxNum = m.at(x).at(y - 1);
				koordinate = Kompleksni(x, y - 1);
			}
			if(m.at(x - 1).at(y - 1) > maxNum) {
				maxNum = m.at(x - 1).at(y - 1);
				koordinate = Kompleksni(x - 1, y - 1);
			}

			x = real(koordinate);
			y = imag(koordinate);
		}

		// Provjera da li je maksNum veci od svojih susjeda
		if(x == 0 && y == 0) {
			if(maxNum >= m.at(x).at(y + 1) && maxNum >= m.at(x + 1).at(y + 1) && maxNum >= m.at(x + 1).at(y))
				break;
		} else if(x == 0 && y > 0 && y < m.at(0).size() - 1) {
			if(maxNum >= m.at(x).at(y +  1) && maxNum >= m.at(x + 1).at(y + 1) && maxNum >= m.at(x + 1).at(y) && m.at(x + 1).at(y - 1) && m.at(x).at(y - 1))
				break;
		} else if(y == m.at(0).size() - 1 && x == 0) {
			if(maxNum >= m.at(x + 1).at(y) && maxNum >= m.at(x + 1).at(y - 1) && maxNum >= m.at(x).at(y - 1))
				break;
		} else if(y == 0 && x > 0 && x < m.size() - 1) {
			if(maxNum >= m.at(x - 1).at(y) && maxNum >= m.at(x - 1).at(y + 1) && maxNum >= m.at(x).at(y + 1) && maxNum >= m.at(x + 1).at(y + 1) && maxNum >= m.at(x + 1).at(y))
				break;
		} else if(x == m.size() - 1 && y == 0) {
			if(maxNum >= m.at(x - 1).at(y) && maxNum >= m.at(x - 1).at(y + 1) && maxNum >= m.at(x).at(y + 1))
				break;
		} else if(x == m.size() - 1 && y == m.at(0).size() - 1) {
			if(maxNum >= m.at(x - 1).at(y) && maxNum >= m.at(x).at(y - 1) && maxNum >= m.at(x + 1).at(y - 1))
				break;
		} else if(x > 0 && x < m.size() - 1 && y == m.at(0).size() - 1) {
			if(maxNum >= m.at(x - 1).at(y) && maxNum >= m.at(x + 1).at(y) && maxNum >= m.at(x + 1).at(y - 1) && maxNum >= m.at(x).at(y - 1) && maxNum >= m.at(x - 1).at(y - 1))
				break;
		} else if(x == m.size() - 1 && y > 0 && y < m.at(0).size() - 1) {
			if(maxNum >= m.at(x - 1).at(y) && maxNum >= m.at(x - 1).at(y + 1) && maxNum >= m.at(x).at(y + 1) && maxNum >= m.at(x).at(y - 1) && maxNum >= m.at(x - 1).at(y - 1))
				break;
		} else {
			if(maxNum >= m.at(x - 1).at(y) && maxNum >= m.at(x - 1).at(y + 1) && maxNum >= m.at(x).at(y + 1) && maxNum >= m.at(x + 1).at(y + 1) && maxNum >= m.at(x + 1).at(y) && maxNum >= m.at(x + 1).at(y - 1) && maxNum >= m.at(x).at(y - 1) && maxNum >=m.at(x - 1).at(y - 1) )
				break;
		}
	}

	Kompleksni konacnaKoordinata = Kompleksni(x, y);
	return konacnaKoordinata;
}



int main ()
{

	int brRedova = 0, brKolona = 0;

	std::cout << "Unesite broj redova i kolona matrice:";
	std::cin >> brRedova >> brKolona;

	std::cout << "Unesite elemente matrice:";

	Matrica  a = KreirajMatricu(brRedova, brKolona);

	for(int i = 0; i < brRedova; i++) {
		for(int j = 0; j < brKolona; j++) {
			std::cin >> a.at(i).at(j);
		}
	}

	int x = 0, y = 0;
	std::cout << "Unesite poziciju odakle zapocinje pretraga:";
	std::cin >> x >> y;

	/*for(int i = 0; i < brRedova; i++){
		for(int j = 0; j < brKolona; j++){
			std::cout << a.at(i).at(j);
		}
		std::cout << std::endl;
	}*/

	Kompleksni k;
	try {
		k = VrhMatrice(a, x, y);
	} catch(std::range_error e) {
		std::cout << "Izuzetak: " << e.what();
	} catch(std::domain_error e) {
		std::cout << "Izuzetak: " << e.what();
	}
	std::cout << "Nadjen je vrh matrice na poziciji " << real(k) << " " << imag(k) << std::endl;
	std::cout << "Njegova vrijednost je " << a.at(real(k)).at(imag(k)) << std::endl;

	return 0;
}

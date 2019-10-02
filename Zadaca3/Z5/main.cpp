//TP 2018/2019: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <vector>
#include <set>

 struct Dijete {
    std::string ime;
    Dijete *sljedeci;
};

typedef std::vector<std::set<std::string>> skupoviTimova;


int DuzinaImena(const std::string &ime)
{
    int duzina = 0;

    for(int i = 0; i < ime.length(); i++) {
        if( (ime.at(i) >= 48 && ime.at(i) <= 57) || (ime.at(i) >= 65 && ime.at(i) <= 90) || (ime.at(i) >=97 && ime.at(i) <= 122) ) duzina++;
    }

    return duzina;
}

skupoviTimova Razvrstavanje(const std::vector<std::string> &djeca, const int brojTimova)
{
    if(brojTimova < 1 || brojTimova > djeca.size()) throw std::logic_error("Razvrstavanje nemoguce");

    Dijete *pocetak = nullptr, *prethodni;
    for(int i = 0; i < djeca.size(); i++) {
        Dijete *novi = new Dijete {djeca.at(i), nullptr};

        if(!pocetak) pocetak = novi;
        else prethodni->sljedeci = novi;
        prethodni = novi;


    }
    skupoviTimova vektorSkupova(brojTimova);

    int brojClanovaTima = djeca.size() / brojTimova;
    auto it = pocetak;
    
    for(int i = 0; i < brojTimova; i++) {
        for(int j = 0; j < (i < djeca.size() % brojTimova ? brojClanovaTima + 1 : brojClanovaTima); j++) { // Koliko tim ima clanova
           
            vektorSkupova.at(i).insert(it->ime);
            int brojSlova = DuzinaImena(it->ime);

            Dijete *pomocni = it;
            
            if(it->sljedeci != nullptr)it = it->sljedeci;
            else it->sljedeci = pocetak;
            prethodni->sljedeci = it;


            for(int k = 0; k < (brojSlova - 1); k++) {
                if(prethodni->sljedeci != nullptr)prethodni = prethodni->sljedeci;
                else prethodni->sljedeci = pocetak;
                if(it->sljedeci != nullptr)it = it->sljedeci;
                else it->sljedeci = pocetak;
                
            }
            delete pomocni;

        }

    }

    return vektorSkupova;
}

int main ()
{
    try {
        int brojDjece;

        std::cout << "Unesite broj djece: ";
        std::cin >> brojDjece;

        std::vector<std::string> imenaDjece;

        std::cout << "Unesite imena djece: " << std::endl;

        std::string str;

        std::cin.clear();
        std::cin.ignore(10000, '\n');

        for(int i = 0; i < brojDjece; i++) {
            std::getline(std::cin, str);
            imenaDjece.push_back(str);
        }

        int brojTimova;

        std::cout << "Unesite broj timova: ";
        std::cin >> brojTimova;

        skupoviTimova konacniSkup = Razvrstavanje(imenaDjece, brojTimova);

        for(int i = 0; i < brojTimova; i++) {
            std::cout << "Tim " << i + 1 << ": ";
            for(auto it = konacniSkup.at(i).begin(); it != konacniSkup.at(i).end(); it++) {
                std::cout << *it << (it != --konacniSkup.at(i).end() ? ", " : "\n");
            }
            std::cout << std::endl;
        }
    } catch(std::logic_error poruka) {
        std::cout << "Izuzetak: " << poruka.what() << std::endl;
    }

    return 0;
}

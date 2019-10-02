#include <iostream>
#include <vector>


int obrniBroj(int a)
{
    int modul, obrnutBroj = 0;

    while(a != 0) {
        modul = a % 10;
        obrnutBroj = obrnutBroj * 10 + modul;
        a /= 10;
    }

    return obrnutBroj;
}

std::vector<int> PalindromskaOtpornost(std::vector<int> v)
{

    std::vector<int> vrijednost;

    for(int i = 0; i < v.size(); i++) {

        int brojac = 0, elem = v.at(abs(i));

        for(;;) {

            int elemInv = obrniBroj(elem);

            if(elem == elemInv) {
                vrijednost.push_back(brojac);
                break;
            } else {
                brojac++;
                elem += elemInv;
            }

        }
      
    }
    return vrijednost;
}

int main ()
{

    int brojElemenata;

    std::cout << "Koliko zelite unijeti elemenata: ";
    std::cin >> brojElemenata;

    std::cout << "Unesite elemente: ";

    std::vector<int> elementi;

    for(int i = 0; i < brojElemenata; i++) {
        int a;
        std::cin >> a;
        elementi.push_back(a);
    }
    
    std::vector<int> pOtpornost = PalindromskaOtpornost(elementi);

    for(int i = 0; i < pOtpornost.size(); i++) {
        std::cout << "Palindromska otpornost broja " << elementi.at(i) << " iznosi " << pOtpornost.at(i) << std::endl;
    }

    return 0;

}

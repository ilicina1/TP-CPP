#include <iostream>
#include <vector>

std::vector<int> funkcija(std::string str)
{
    int broj;
    bool jelPrvi = true;
    std::vector<int> brojevi;
    for(int i = 0; i < str.length(); i++) {
        if(jelPrvi == false) {
            broj *= 10;
            int pom = 0;
            pom = str[i] - '0';
            broj += pom;
            if(str[i+1] < '0' || str[i+1] > '9') {
                brojevi.push_back(broj);
                broj = 0;
                jelPrvi = true;
            }
        }
        if( (str[i] >= '0' && str[i] <= '9') && (str[i-1] < '0' || str[i-1] > '9') && ((str[i+1] < 'A' || str[i+1] > 'Z') && (str[i+1] < 'a' || str[i+1] > 'z') )) {
            broj = str[i] - '0';
            jelPrvi = false;
        }
    }
    return brojevi;
}

int main()
{
    std::string str = "120 hrabrih studenata izašlo na ispit, 35 ih je odustalo, ostalo ih 85 a postoji i 2pac..";
    std::vector<int> vektor;
    vektor = funkcija(str);
    for(int i = 0; i < vektor.size(); i++) {
        std::cout << vektor.at(i) << std::endl;
    }
    return 0;
}

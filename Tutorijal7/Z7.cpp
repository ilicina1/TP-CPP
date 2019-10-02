// TP 16/17 (Tutorijal 7, Zadatak 7)
#include <iostream>
#include <set>
#include <string>

template <typename nekiTip>
std::set<nekiTip> Unija(std::set<nekiTip> prviSkup, std::set<nekiTip> drugiSkup)
{
    std::set<nekiTip> konacniSkup;

    for(auto i = prviSkup.begin(); i != prviSkup.end(); i++) {
        for(auto j = drugiSkup.begin(); j != drugiSkup.end(); j++) {
            konacniSkup.insert(*i);
        }
    }

    for(auto i = drugiSkup.begin(); i != drugiSkup.end(); i++) {
        for(auto j = prviSkup.begin(); j != prviSkup.end(); j++) {
            konacniSkup.insert(*i);
        }
    }

    return konacniSkup;
}

template <typename nekiTip>
std::set<nekiTip> Presjek(std::set<nekiTip> prviSkup, std::set<nekiTip> drugiSkup)
{
    std::set<nekiTip> konacniSkup;

    for(auto i = prviSkup.begin(); i != prviSkup.end(); i++) {
        for(auto j = drugiSkup.begin(); j != drugiSkup.end(); j++) {
            if(*i == *j) konacniSkup.insert(*i);
        }
    }

    return konacniSkup;
}

int main ()
{
    std::set<std::string> prviSkupStringova;
    std::set<std::string> drugiSkupStringova;

    std::cout << "Unesite elemente prvog skupa stringova (prazan red za kraj): ";

    for(;;) {
        std::string element;
        std::getline(std::cin, element);
        if(element == "") break;
        prviSkupStringova.insert(element);
    }

    std::cout << "Unesite elemente drugog skupa stringova (prazan red za kraj): ";

    for(;;) {
        std::string element;
        std::getline(std::cin, element);
        if(element == "") break;
        drugiSkupStringova.insert(element);
    }

    std::set<std::string> unijaSkupova = Unija(prviSkupStringova, drugiSkupStringova);
    std::set<std::string> presjekSkupova = Presjek(prviSkupStringova, drugiSkupStringova);

    std::cout << "Presjek: ";
    for(auto i : presjekSkupova) std::cout << i << ", ";

    std::cout << std::endl;

    std::cout << "Unija: ";
    for(auto i : unijaSkupova) std::cout << i << ", ";

    return 0;
}

//TP 2018/2019: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>

void malaSlova(std::string &rijec){
    boost::algorithm::to_lower(rijec);
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(const std::string &tekstt)
{
    std::vector<std::string> rijeci;
    std::vector<int> indeksi;
    std::string tekst = tekstt;
    malaSlova(tekst);
    
    for(int i = 0; i < tekst.length(); i++) {
        if(i == 0) {
            if((tekst.at(i) >= 48 && tekst.at(i) <= 57) || (tekst.at(i) >= 65 && tekst.at(i) <= 90) || (tekst.at(i) >= 97 && tekst.at(i) <= 122)) indeksi.push_back(i);
        } else if( ((tekst.at(i) >= 48 && tekst.at(i) <= 57) || (tekst.at(i) >= 65 && tekst.at(i) <= 90) || (tekst.at(i) >= 97 && tekst.at(i) <= 122)) && ((tekst[i - 1] >= 0 && 
                tekst[i - 1] <= 47) || (tekst[i - 1] >= 58 && tekst[i - 1] <= 64) || (tekst[i - 1] >= 91 && tekst[i - 1] <= 96) || (tekst[i - 1] >= 123 && tekst[i - 1] <= 127)) ) {
            indeksi.push_back(i);
        }
    }

    std::string pomocni;

    for(auto i : tekst) {
        if( (i >= 48 && i <= 57) || (i >= 65 && i <= 90) || (i >= 97 && i <= 122) ) {
            pomocni.push_back(i);
        }

        if( (i >= 0 && i <= 47) || (i >= 58 && i <= 64) || (i >= 91 && i <= 96) || (i >= 123 && i <= 127) ) {
            if(pomocni.length() > 0) {
                rijeci.push_back(pomocni);
                pomocni.clear();
            }
        }
    }
    
    if(pomocni.length() > 0) rijeci.push_back(pomocni);
    std::map<std::string, std::set<int>> mapaPojmova;

    for(int i = 0; i < rijeci.size(); i++) {
        std::set<int> pomocniSet;

        for(int j = i + 1; j < rijeci.size(); j++) {
            if(rijeci.at(i) == rijeci.at(j)) {
                pomocniSet.insert(indeksi.at(i));
                pomocniSet.insert(indeksi.at(j));
            }
        }
        pomocniSet.insert(indeksi.at(i));
        if(!mapaPojmova.count(rijeci.at(i))) mapaPojmova.insert({rijeci.at(i), pomocniSet});
    }

    return mapaPojmova;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa)
{
    for(auto it = mapa.begin(); it != mapa.end(); it++) {
        std::cout << it->first << ": ";

        for(auto set_it = it->second.begin(); set_it != it->second.end(); ++set_it) {
            std::cout << *set_it << (set_it != --it->second.end() ? "," : "\n");
        }

    }

}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> mapa)
{
    malaSlova(rijec);
    auto it = mapa.find(rijec);
    std::set<int> skup;
    if(it == mapa.end()) std::cout << "Unesena rijec nije nadjena!" << std::endl;
    else {
        for(auto set_it = it->second.begin(); set_it != it->second.end(); ++set_it) {
            skup.insert(*set_it);
        }
    }
    return skup;
}

int main ()
{
    std::cout << "Unesite tekst: ";

    std::string tekst;

    std::getline(std::cin, tekst);

    std::map<std::string, std::set<int>> mapaPojmova = KreirajIndeksPojmova(tekst);

    IspisiIndeksPojmova(mapaPojmova);

    std::string rijec = "";

    for(;;) {
        std::set<int> skup;
        std::cout << "Unesite rijec: ";
        std::cin >> rijec;
        if(rijec == ".") break;
        skup = PretraziIndeksPojmova(rijec, mapaPojmova);
        for(int x : skup) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}

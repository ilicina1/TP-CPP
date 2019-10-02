// TP, 2018/2019, Zadaća 1, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <boost/algorithm/string.hpp>

void IzvrniString(std::string &s)
{

	int length = s.length();


	for(int i = 0; i < length / 2; i++) {
		std::swap(s[i], s[length - i - 1]);
	}


}

void VelikaSlova(std::string &s)
{
//	boost::algorithm::to_lower(s);
	boost::algorithm::to_upper(s);
}

std::vector<std::string> NadjiSimetricneRijeci(std::string &str)
{
	std::string rijec = "";
	std::vector<std::string> s;

	for (auto x : str) {

		if(x == ',' || x == ' ' || x == '.' || x == '!' || x == '#' || x == '$' || x == '%' || x == '/' || x == '(' || x == ')' || x == '=' || x == '?' || x == '*' || x == '[' || x == ']' || x == '<' || x == '>' || x == '-' || x == '_' || x == '+') {
			if(rijec.length() >= 2) s.push_back(rijec);
				rijec.clear();
				continue;
		} 
		
		rijec = rijec + x;
	}
	
	if(rijec.length() != 0) s.push_back(rijec);

	std::vector<std::string> pomocni;

	for(int i = 0; i < s.size(); i++) {
		pomocni.push_back(s.at(i));
	}

	std::vector<std::string> pomocni2;
	for(int i = 0; i < s.size(); i++) {
		pomocni2.push_back(s.at(i));
	}

	for(int i = 0; i < pomocni.size(); i++) {
		IzvrniString(pomocni.at(i));
	}

	for(int i = 0; i < pomocni.size(); i++) {
		VelikaSlova(pomocni.at(i));
	}

	for(int i = 0; i < pomocni2.size(); i++) {
		VelikaSlova(pomocni2.at(i));
	}

	std::vector<std::string> finalni;

	for(int i = 0; i < pomocni.size(); i++) {
		if(pomocni.at(i) == pomocni2.at(i)) finalni.push_back(s.at(i));
	}

	return finalni;
}


int main()
{
	std::string str;

	std::cout << "Unesite recenicu:" << std::endl;
	std::getline(std::cin, str);

	std::vector<std::string> stringon = NadjiSimetricneRijeci(str);

	if(stringon.size() == 0) {
		std::cout << "Recenica ne sadrzi simetricne rijeci!";
		return 0;
	}

	std::cout << "Simetricne rijeci unutar recenice su:" << std::endl;
	for(auto x : stringon) {
		std::cout << x << std::endl;
	}

	return 0;
}

// TP 16/17 (Tutorijal 12, Zadatak 2)
#include <iostream>
#include <set>
#include <algorithm>
#include <utility>

template <typename T>
std::set<T> operator +(const std::set<T> &s1, const std::set<T> &s2)
{
	std::set<T> pomocni(s1);
	for(auto i : s2) pomocni.insert(i);
	return pomocni;
}

template <typename T>
std::set<T> operator *(const std::set<T> &s1, const std::set<T> &s2)
{
	std::set<T> pomocni;
	for(auto i = s1.begin(); i != s1.end(); i++){
		for(auto j = s2.begin(); j != s2.end(); j++){
			if(*i == *j) pomocni.insert(*i);
		}
	}
	return pomocni;
}

template <typename T>
std::ostream &operator <<(std::ostream &tok, const std::set<T> &s1)
{
	tok << "{";
	for(auto i = s1.begin(); i != s1.end();){
		tok << *i;
		if(++i != s1.end()) tok << ",";
	}
	tok << "}";
	return tok;
}

template <typename T>
std::set<T> operator *=(std::set<T> &s1, const std::set<T> &s2)
{
	std::set<T> pomocni;
	for(auto i = s1.begin(); i != s1.end(); i++){
		for(auto j = s2.begin(); j != s2.end(); j++){
			if(*i == *j) {
				pomocni.insert(*i);
				break;
			}
		}
	}
	return pomocni;
}

template <typename T>
std::set<T> &operator +=(std::set<T> &s1, const std::set<T> &s2)
{
	for(auto i : s2) s1.insert(i);
	return s1;
}

template <typename T, typename P>
std::set<P> operator %(const std::set<T> &s1, const std::set<T> &s2)
{
	std::set<std::pair<char, int>> pomocni;
	std::pair<char, int> pomocniPar;
	for(auto i = s1.begin(); i != s1.end(); i++){
		for(auto j = s2.begin(); j != s2.end(); j++){
			pomocniPar.first = *i;
			pomocniPar.second = *j;
			pomocni.insert(pomocniPar);
		}
	}
	return pomocni;
}

std::ostream &operator <<(std::ostream &tok, const std::set<std::pair<char, int>> &s1)
{

	for(auto i = s1.begin(); i != s1.end();){
		std::pair<char, int> x = *i;
		tok << "(" << x.first << "," << x.second << ")";
	}
	return tok;
}

int main ()
{
	 std::set<char> s3{'A', 'B'};
	 std::set<int> s4{1, 2, 3};
	 std::cout << s3 % s4 << std::endl;
	 return 0;
}

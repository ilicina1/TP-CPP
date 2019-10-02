// TP 2018/2019: Tutorijal 5, Zadatak 2
#include <iostream>
#include <vector>
#include <deque>

template <typename nekiTip, typename nekiTip2>
	void RazmijeniBlokove(nekiTip p1, nekiTip p2, nekiTip2 p3)
	{
		while(p1 != p2){
			auto pomocni = *p1;
			*p1++ = *p3;
			*p3++ = pomocni;
		}

	}

int main ()
{
	int niz[] {2, 41, 242, 422, 221, 433, 343}, niz2[] {21, 241, 4242, 3422, 1221, 4533, 2343};

	RazmijeniBlokove(std::begin(niz), std::end(niz), std::begin(niz2));

	std::cout << "Prvi kontejner: ";

	for(auto i : niz){
		std::cout << i << " ";
	}

	std::cout << std::endl;

	std::cout << "Drugi kontejner: ";

	for(auto i : niz2){
		std::cout << i << " ";
	}

	std::cout << std::endl;

	std::string s1("String s1 ce postati s2!"), s2("String s2 ce postati s1!");

	RazmijeniBlokove(s1.begin(), s1.end(), s2.begin());

	for(auto i : s1){
		std::cout << i;
	}

	std::cout << std::endl;

	for(auto i : s2){
		std::cout << i;
	}

	return 0;
}

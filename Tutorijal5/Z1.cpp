// TP 2018/2019: Tutorijal 5, Zadatak 1
#include <iostream>

int main ()
{
	char str[1000], *p = str;

	std::cout << "Unesite recenicu: ";
	std::cin.getline(str, sizeof str);

	while(*p == ' ' && *p != '\0') p++;
	while(*p != ' ' && *p != '\0') p++;
	while(*p == ' ' && *p != '\0') p++;

	std::cout << "Recenica bez prve rijeci glasi: " << p << std::endl;

	return 0;
}

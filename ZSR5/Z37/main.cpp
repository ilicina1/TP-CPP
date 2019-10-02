//TP 2018/2019: ZSR 5, Zadatak 37
#include <iostream>
#include <string>

template <typename Comp>
std::string funkcija(std::string &str, char x, Comp fun){
    for(int i = 0; i < str.length(); i++) if(fun(str.at(i))) str.at(i) = x;
    return str;
}
int main ()
{
    std::string str = "Cao pIcko sta ima";
    str = funkcija(str, 'Y', [](char a){
       return (a > 96 && a < 123);
    });
    std::cout << str;
	return 0;
}
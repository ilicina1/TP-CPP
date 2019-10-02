//TP 2018/2019: Tutorijal 4, Zadatak 2
#include <iostream>

void IzvrniString(std::string &s){

    int length = s.length();

    for(int i = 0; i < length / 2; i++){
        std::swap(s[i], s[length - i - 1]);
    }

}

int main ()
{
    std::string str;

    std::cout << "Unesi string: ";
    getline(std::cin, str);

    IzvrniString(str);

    std::cout << "Izvrnuti string je: " << str;

	return 0;
}

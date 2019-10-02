#include <iostream>
#include <string>

std::string IzdvojiRijec(std::string str, int n)
{
    std::string rijec;
    int niz[20];
    int brojacRijeci = 0;
    int indeks = 0;
    for(int i = 0; i < str.length(); i++) {
        if((i == 0) && ((str.at(0) >= 'A' && str.at(0) <= 'Z') || (str.at(0) >= 'a' && str.at(0) <= 'z'))) {
            brojacRijeci++;
            niz[indeks] = i;
            indeks++;
            continue;
        }
        if(( (str.at(i) >= 'A' && str.at(i) <= 'Z') && str.at(i-1) == ' ') || ((str.at(i) >= 'a' && str.at(i) <= 'z') && str.at(i-1) == ' ')) {
            brojacRijeci++;
            niz[indeks] = i;
            indeks++;
        }
    }
    if(n < 1 || n > brojacRijeci) throw std::logic_error("Bum");
    int m = 0;
    for(int i = niz[n-1]; i < str.length(); i++) {
        if(str[i] == ' ') break;
        rijec[m] = str[i];
        m++;
    }
    
    return rijec;
}

int main()
{
    std::string s = "haha koji malja";
    std::string m = IzdvojiRijec(s, 2);
    int i = 0;
    for(;;) {
        if(m[i] == '\0') break;
        i++;
    }
    std::cout << s<< '\n';
    for(int j = 0; j < i; j++){
        std::cout << m[j];
    }
    return 0;
}

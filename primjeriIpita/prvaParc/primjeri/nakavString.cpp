#include <iostream>
#include <string>

void funkcija(std::string &str, int n)
{
    std::string pom = " ";
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ') {
            for(int j = 0; j < n; j++) {
                str.insert(i+j, pom);
            }
            i += n;
        }
    }
    //return str;
}

int main()
{
    std::string s;
    std::getline(std::cin, s);
    funkcija(s, 5);
    std::cout << s;
    return 0;
}

//TP 2018/2019: ZSR 6, Zadatak 22
#include <iostream>
#include <vector>
#include <string>

// template <typename nekiTip>
char **nekaFunkcija(std::vector<std::string> str)
{
    char **a;
    try {
        a = new char*[str.size()];
        for(int i = 0; i < str.size(); i++) {
            a[i] = new char[str.at(i).length() + 1];
            //a[str.at(i).length()] = '\0';
        }
    } catch(std::bad_alloc) {
        for(int i = 0; i < str.size(); i++) delete[] a[i];
        delete[] a;
        std::cout << "Allocation failed" << std::endl;
    }
    for(int i = 0; i < str.size(); i++) {
        for(int j = 0; j < str.at(i).length(); j++) a[i][j] = str.at(i).at(j);
        a[i][str.at(i).length()] = '\0';
    }
    return a;
}

int main ()
{
    std::cout << "Unesite broj elemenata: ";
    int n;
    std::cin >> n;
    std::vector<std::string> str;
    for(int i = 0; i < n + 1; i++) {
        std::string s = "";
        std::getline(std::cin, s);
        str.push_back(s);
    }
    char **a = nekaFunkcija(str);
    for(int i = 0; i < str.size(); i++) {
        for(int j = 0; j < str.at(i).size(); j++) std::cout << a[i][j];
        std::cout << std::endl;
    }
    for(int i = 0; i < str.size(); i++) delete[] a[i];
    delete[] a;
    return 0;
}

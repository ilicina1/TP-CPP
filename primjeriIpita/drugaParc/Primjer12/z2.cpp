#include <iostream>

struct Studenti{
private:
    int brIndeksa;
    char imePrezime[20];
    char adresa[50];
    char eAdresa[50];
    Studenti *niz;
    int maks;
public:
    Studenti() {}
    Studenti(int maks){
        try{
            niz = new Studenti[maks];
        } catch(...){
            throw std::bad_alloc();
        }
    }
    ~Studenti() { delete niz; }
};

int main()
{
    Studenti s(5);
}

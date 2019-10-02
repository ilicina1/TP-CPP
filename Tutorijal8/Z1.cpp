//TP 2018/2019: Tutorijal 8, Zadatak 1
#include <iostream>
#include <iomanip>

struct Vrijeme {
    int sati, minute, sekunde;
};

void TestirajVrijeme(const Vrijeme &vrijeme)
{
    if(vrijeme.sati < 0 || vrijeme.sati > 23 || vrijeme.minute < 0 || vrijeme.minute > 59 || vrijeme.sekunde < 0 || vrijeme.sekunde > 59) throw std::domain_error ("Neispravno vrijeme");
}

void IspisiVrijeme (const Vrijeme &vrijeme)
{
    TestirajVrijeme(vrijeme);
    std::cout << std::setfill('0') << std::setw(2) << vrijeme.sati << ":" << std::setfill('0') << std::setw(2) << vrijeme.minute << ":" << std::setfill('0') << std::setw(2) << vrijeme.sekunde << std::endl;
}

Vrijeme SaberiVrijeme(const Vrijeme &prvoVrijeme, const Vrijeme &drugoVrijeme)
{
    TestirajVrijeme(prvoVrijeme);
    TestirajVrijeme(drugoVrijeme);

    Vrijeme zbir {prvoVrijeme.sati + drugoVrijeme.sati, prvoVrijeme.minute + drugoVrijeme.minute, prvoVrijeme.sekunde + drugoVrijeme.sekunde};

    if(zbir.sekunde >= 60) {
        zbir.sekunde %= 60;
        zbir.minute++;
    }

    if(zbir.minute >= 60) {
        zbir.minute %= 60;
        zbir.sati++;
    }

    if(zbir.sati >= 23) {
        zbir.sati %= 24;
    }

    return zbir;
}

int main ()
{
    std::cout << "Unesite prvo vrijeme (h m s): ";
    try {
        Vrijeme prvoVrijeme, drugoVrijeme;

        std::cin >> prvoVrijeme.sati >> prvoVrijeme.minute >> prvoVrijeme.sekunde;
        TestirajVrijeme(prvoVrijeme);

        std::cout << "Unesite drugo vrijeme (h m s): ";

        std::cin >> drugoVrijeme.sati >> drugoVrijeme.minute >> drugoVrijeme.sekunde;
        TestirajVrijeme(drugoVrijeme);

        std::cout << "Prvo vrijeme: ";
        IspisiVrijeme(prvoVrijeme);

        std::cout << "Drugo vrijeme: ";
        IspisiVrijeme(drugoVrijeme);

        Vrijeme zbir = SaberiVrijeme(prvoVrijeme, drugoVrijeme);

        std::cout << "Zbir vremena: ";

        IspisiVrijeme(zbir);

    } catch(std::domain_error poruka) {
        std::cout << poruka.what() << std::endl;
    }
    return 0;
}

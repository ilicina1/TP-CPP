#include <iostream>
#include <algorithm>
#include <iomanip>

struct Student{
    int brojIndeksa;
    char ime_prezime[20];
    char adresa[50];
    char e_adresa[50];
public:
    Student(int brojIndeksa, char *ime_prezime, char *adresa, char *e_adresa) : brojIndeksa(brojIndeksa){
        for(int i = 0; i < 20; i++) this->ime_prezime[i] = ime_prezime[i];
        for(int i = 0; i < 50; i++) this->adresa[i] = adresa[i];
        for(int i = 0; i < 50; i++) this->e_adresa[i] = e_adresa[i];
    }
    ~Student(){}
    int DajBrojIndeksa() const { return brojIndeksa; }
    const char *DajImePrezime() const { return ime_prezime; }
    const char *DajAdresu() const { return adresa; }
    const char *DaMailAdresu() const { return e_adresa; }
    Student *DajKopiju() const { return new Student(*this); }
    void Ispisi() const { 
        std::cout << "Ime i Prezime: " << std::setw(34) << DajImePrezime() << std::endl << "Broj indeksa: " << std::setw(35) << DajBrojIndeksa() << std::endl <<
        "Adresa stanovanja: " << std::setw(30) << DajAdresu() << std::endl << "E-mail adresa: " << std::setw(34) << DaMailAdresu() << std::endl << "---------------------------------------------------" << std::endl;
    }
};


class PolimorfniStudent{
    Student **studenti;
    int broj_studenata, kapacitet;
public:
    explicit PolimorfniStudent(int kapacitet) : studenti(new Student*[kapacitet]{}), broj_studenata(0), kapacitet(kapacitet){}
    ~PolimorfniStudent(){
        for(int i = 0; i < broj_studenata; i++) delete[] studenti[i];
        delete[] studenti;
    }
    PolimorfniStudent(const PolimorfniStudent &student) : studenti(new Student*[student.kapacitet]), broj_studenata(student.broj_studenata), kapacitet(student.kapacitet){
        try{
            for(int i = 0; i < student.kapacitet; i++) studenti[i] = student.studenti[i]->DajKopiju();
        } catch(...){
            for(int i = 0; i < student.kapacitet; i++) delete[] studenti[i];
            delete[] studenti;
        }
    }
    PolimorfniStudent(PolimorfniStudent &&stjud);
    PolimorfniStudent &operator =(const PolimorfniStudent &stjud);
    PolimorfniStudent &operator =(PolimorfniStudent &&stjud);
    void DodajStudenta(int brojIndeksa, char *ime_prezime, char *adresa, char *e_adresa);
    void IspisiStudenta(int indeks) const { studenti[indeks]->Ispisi(); }
    void Ispisi() const { for(int i = 0; i < broj_studenata; i++) studenti[i]->Ispisi(); }
    const char *operator [](int indeks){
        return studenti[indeks]->DaMailAdresu();
    }
};

void PolimorfniStudent::DodajStudenta(int brojIndeksa, char *ime_prezime, char *adresa, char *e_adresa){
    if(broj_studenata >= kapacitet){
        throw std::logic_error("Nema mjesta!");
    }
    studenti[broj_studenata++] = new Student(brojIndeksa, ime_prezime, adresa, e_adresa);
}

PolimorfniStudent::PolimorfniStudent(PolimorfniStudent &&stjud) : studenti(stjud.studenti), broj_studenata(stjud.broj_studenata), kapacitet(stjud.kapacitet) {
    stjud.studenti = nullptr; stjud.broj_studenata = 0; stjud.kapacitet = 0;
}

PolimorfniStudent &PolimorfniStudent::operator =(PolimorfniStudent &&stjud){
    std::swap(studenti, stjud.studenti);
    std::swap(broj_studenata, stjud.broj_studenata);
    std::swap(kapacitet, stjud.kapacitet);
    return *this;
}

PolimorfniStudent &PolimorfniStudent::operator =(const PolimorfniStudent &stjud){
    Student **novi_prostor = new Student*[stjud.kapacitet];
    try{
        for(int i = 0; i < stjud.broj_studenata; i++) novi_prostor[i] = stjud.studenti[i]->DajKopiju();
    }catch(...){
        for(int i = 0; i < broj_studenata; i++) delete[] novi_prostor[i];
        delete[] novi_prostor;
        throw;
    }
    for(int i = 0; i < broj_studenata; i++) delete[] studenti[i];
    delete[] studenti;
    studenti = novi_prostor; broj_studenata = stjud.broj_studenata; kapacitet = stjud.kapacitet;
    return *this;
}

int main()
{
    PolimorfniStudent stjudent(10);
    int indeks = 42;
    char ime[20] = "ilhan licina";
    char adresa[20] = "drinolino";
    char mail[21] = "ilhan.cs12@gmail.com";
    stjudent.DodajStudenta(indeks, ime, adresa, mail);
    stjudent.Ispisi();
    std::cout << std::endl << stjudent[0] << std::endl;
}
